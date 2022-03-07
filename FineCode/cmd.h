#pragma once

#include <stdexcept>

#include "IDataBase.h"
#include "Employee.h"
#include "Condition.h"
#include "Result.h"

class ICmd {
public:
    static shared_ptr<ICmd> getCmd(const vector<string> &params);

    ICmd(Result* result) :
        result_(result) {
    }

    virtual bool execute(const shared_ptr<IDataBase> database) = 0;
    virtual string getResut() = 0;

protected:
    Result *result_;
};

class CmdAdd : public ICmd {
public:
    CmdAdd(Employee* employee, Result* result) :
        ICmd(result), employee_(employee) {
    }

    virtual bool execute(const shared_ptr<IDataBase> database) override {
        try {
            database->add(*employee_, *result_);
        }
        catch (...) {
            throw std::runtime_error("DB error : add");
        }

        return true;
    }
    virtual string getResut() override  {
        return result_->toString();
    }
private:
    Employee *employee_;
};

class ICmdTarget : public ICmd {
public:
    ICmdTarget(ConditionPtr targetCondition, Result *result) :
        ICmd(result), targetCondition_(targetCondition) {
    }
    virtual string getResut() override {
        return result_->toString();
    }
protected:
    ConditionPtr targetCondition_;
};

class CmdSearch : public ICmdTarget {
public:
    CmdSearch(ConditionPtr targetCondition, Result *result) :
        ICmdTarget(targetCondition, result) {
    }

    virtual bool execute(const shared_ptr<IDataBase> database) override {
        try {
            database->search(*targetCondition_, *result_);
        }
        catch (...) {
            throw std::runtime_error("DB error : search");
        }
        return true;
    }
};

class CmdModify : public ICmdTarget {
public:
    CmdModify(ConditionPtr targetCondition, ConditionPtr modifyCondition, Result *result) :
        ICmdTarget(targetCondition, result), modifyCondition_(modifyCondition) {
    }

    virtual bool execute(const shared_ptr<IDataBase> database) override {
        try {
            database->modify(*targetCondition_, *modifyCondition_, *result_);
        }
        catch (...) {
            throw std::runtime_error("DB error : modify");
        }
        return true;
    }

private:
    ConditionPtr modifyCondition_;
};

class CmdErase : public ICmdTarget {
public:
    CmdErase(ConditionPtr targetCondition, Result *result) :
        ICmdTarget(targetCondition, result) {
    }

    virtual bool execute(const shared_ptr<IDataBase> database) override {
        try {
            database->erase(*targetCondition_, *result_);
        }
        catch (...) {
            throw std::runtime_error("DB error : erase");
        }
        return true;
    }
};
