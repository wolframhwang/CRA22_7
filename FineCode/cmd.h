#pragma once

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

protected:
    Result *result_;
};

class CmdAdd : public ICmd {
public:
    CmdAdd(Employee* employee, Result* result) :
        ICmd(result), employee_(employee) {
    }

    virtual bool execute(const shared_ptr<IDataBase> database) override {
        database->add(*employee_, *result_);
    }

private:
    Employee *employee_;
};

class ICmdTarget : public ICmd {
public:
    ICmdTarget(ConditionPtr targetCondition, Result *result) :
        ICmd(result), targetCondition_(targetCondition) {
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
        database->search(*targetCondition_, *result_);
    }
};

class CmdModify : public ICmdTarget {
public:
    CmdModify(ConditionPtr targetCondition, ConditionPtr modifyCondition, Result *result) :
        ICmdTarget(targetCondition, result), modifyCondition_(modifyCondition) {
    }

    virtual bool execute(const shared_ptr<IDataBase> database) override {
        database->modify(*targetCondition_, *modifyCondition_, *result_);
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
        database->erase(*targetCondition_, *result_);
    }
};
