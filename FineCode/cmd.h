#pragma once
#include <memory>

#include "Employee.h"
#include "Condition.h"
#include "IDataBase.h"

// TODO : remove this temporal code
#ifdef DEBUG_RESULT
struct Result {
    string str;
    bool operator == (Result a) {
        return this->str == a.str;
    }
    void operator = (Result a) {
        this->str = a.str;
    }
};
#endif

struct ICmd {
public:
    ICmd(): result() {};
    virtual Result execute(shared_ptr<IDataBase> database) = 0;
    virtual void setCondition(shared_ptr<Condition> targetCondition) {}
    vector<string> getParsedCmd() { return parsedCmd_; }
    void setParsedCmd(vector<string> parsedCmd) { parsedCmd_ = parsedCmd; }
protected:
    Result result;
    vector<string> parsedCmd_;
};

class CmdAdd : public ICmd {
public:
    CmdAdd() : employee(nullptr) {};
    virtual Result execute(shared_ptr<IDataBase> database) override {
        return result;
        // return database.add(employee);
    }
private:
    Employee* employee;
};

class ICmdTarget : public ICmd {
public:
    virtual Result execute(shared_ptr<IDataBase> database) = 0;
    void setCondition(shared_ptr<Condition> targetCondition) {
        this->targetCondition = targetCondition;
    }
protected:
    shared_ptr<Condition> targetCondition;
};

class CmdModify : public ICmdTarget {
public:
    virtual Result execute(shared_ptr<IDataBase> database) override {
        return result;
        // return database.modify(targetCondition);
    }
};
class CmdSearch : public ICmdTarget {
public:
    virtual Result execute(shared_ptr<IDataBase> database) override {
        return result;
        // return database.erase(targetCondition);
    }
};
class CmdErase : public ICmdTarget {
public:
    virtual Result execute(shared_ptr<IDataBase> database) override {
        return result;
        // return database.erase(targetCondition);
    }
};
