#pragma once
#include <list>
#include <vector>
#include "Employee.h"
#include "Condition.h"
#include "Result.h"

using namespace std;

struct IDataBase {
    virtual void add(Employee &employee, Result &result) = 0;
    virtual void modify(const Condition &targetCondition, const Condition &modifyCondition, Result &result) = 0;
    virtual void erase(const Condition &targetCondition, Result &result) = 0;
    virtual void search(const Condition &targetCondition, Result &result) = 0;
};

class DataBase: public IDataBase {
public:
    virtual void add(Employee &employee, Result &result) override {
        result.insert(employee);
        employees_.push_back(employee);
    }    
    
    virtual void modify(const Condition &targetCondition, const Condition &modifyCondition, Result &result) override {
        for (auto employee : employees_) {
            if (targetCondition.isEqual(employee)) {
                result.insert(employee);
                modifyCondition.set(employee);
            }
        }
    }

    virtual void erase(const Condition &targetCondition, Result &result) override {
        for (auto employee : employees_) {
            if (targetCondition.isEqual(employee)) {
                result.insert(employee);
                employees_.remove(employee);
            }
        }
    }

    virtual void search(const Condition &targetCondition, Result &result) override {
        for (auto employee : employees_) {
            if (targetCondition.isEqual(employee)) {
                result.insert(employee);
            }
        }
    }
    
private:
    list<Employee> employees_;
};