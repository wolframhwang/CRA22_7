#pragma once

#include "IDataBase.h"
#include "Employee.h"

struct ICmd {
public:
    static shared_ptr<ICmd> getCmd(string CmdType); // ADD, DEL, SCH, MOD
    virtual bool execute(const shared_ptr<IDataBase> database) = 0;
    virtual const vector<string>& getParsedCmd() const = 0;
    virtual bool setParsedCmd(const vector<string>& parsedCmd)  = 0;
    virtual void setEmployee(const shared_ptr<Employee> employee) = 0;
    virtual void setCondition(const shared_ptr<Condition> targetCondition) = 0;
};
