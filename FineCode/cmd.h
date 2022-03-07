#pragma once

#include "IDataBase.h"
#include "Employee.h"
#include "Condition.h"
#include "Result.h"

class ICmd {
public:
    static shared_ptr<ICmd> getCmd(const vector<string> &params) {
        auto type = params[0];

        if (type == "ADD") {
            if (ConditionEmployeeNum::isValid(params[4]) &&
                ConditionName::isValid(params[5]) &&
                ConditionCl::isValid(params[6]) &&
                ConditionPhoneNum::isValid(params[7]) &&
                ConditionBirthday::isValid(params[8]) &&
                ConditionCerti::isValid(params[9])) {
            
                Employee *employee = new Employee(params);
                Result *result = new ResultCount(type);
                return make_shared<CmdAdd>(CmdAdd{ employee, result });
            }
        }
        
        return nullptr;
    }

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
    ICmdTarget(Condition *targetCondition, Result *result) :
        ICmd(result), targetCondition_(targetCondition) {
    }

protected:
    Condition *targetCondition_;
};

class CmdSearch : public ICmdTarget {
public:
    CmdSearch(Condition *targetCondition, Result *result) :
        ICmdTarget(targetCondition, result) {
    }

    virtual bool execute(const shared_ptr<IDataBase> database) override {
        database->search(*targetCondition_, *result_);
    }
};

class CmdModify : public ICmdTarget {
public:
    CmdModify(Condition *targetCondition, Condition *modifyCondition, Result *result) :
        ICmdTarget(targetCondition, result), modifyCondition_(modifyCondition) {
    }

    virtual bool execute(const shared_ptr<IDataBase> database) override {
        database->modify(*targetCondition_, *modifyCondition_, *result_);
    }

private:
    Condition *modifyCondition_;
};

class CmdErase : public ICmdTarget {
public:
    CmdErase(Condition *targetCondition, Result *result) :
        ICmdTarget(targetCondition, result) {
    }

    virtual bool execute(const shared_ptr<IDataBase> database) override {
        database->erase(*targetCondition_, *result_);
    }

private:
    Condition *modifyCondition_;
};
