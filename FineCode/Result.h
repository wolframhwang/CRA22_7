#pragma once

#include <string>
#include <vector>
#include <queue>

#include "Employee.h"

using namespace std;

const int maxEmployeePrintCount = 5;

class Result {    
public:    
    Result(const string& cmd) : cmd_(cmd + ",") {}

    virtual void insert(const Employee& employee) = 0;
    virtual string toString(void) = 0;

protected:
    string cmd_;
};

class ResultCount : public Result {    
public:
    ResultCount(string cmd) :
        Result(cmd), entryCount_(0) {
    }

    virtual void insert(const Employee& employee) override {
        entryCount_++;
    }

    virtual string toString(void) override {
        if (entryCount_ == 0) {
            return cmd_ + "NONE";
        }
        return cmd_ + to_string(entryCount_);
    }

private:
    int entryCount_;
};

struct EmployeeCompare {
    bool operator()(const Employee* e1, const Employee* e2) {
        return e1->employeeNum > e2->employeeNum;
    }
};

class ResultTop : public Result {    
public:
    ResultTop(string cmd, int printCount) : 
        Result(cmd), printCount_(printCount) {
    }

    virtual void insert(const Employee& employee) override {
        employees_.push(&employee);
    }

    virtual string toString(void) override {
        if (employees_.size() == 0) {
            return cmd_ + "NONE";
        }

        string result;
        for (int index = 0; index < printCount_; index++) {
            auto employee = employees_.top();
            result += cmd_ + employee->toString() + "\n";

            employees_.pop();
            if (employees_.empty()) {
                break;
            }
        }
        return result;
    }

private:
    int printCount_;
    priority_queue<const Employee*, std::vector<const Employee*>, EmployeeCompare> employees_;
};

class ResultNone : public Result {    
public:
    ResultNone(string cmd) : 
        Result(cmd) {
    }

    virtual void insert(const Employee& employee) override {
    }

    virtual string toString(void) override {
        return "";
    }

private:
};
