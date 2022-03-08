#pragma once
#include <unordered_map>
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
        unsigned long key = employee.employeeNum;

        if (employees_.find(key) != employees_.end()) {
            throw runtime_error("DB error : employeeNum already exists");
        }
        result.insert(employee);
        employees_.insert(make_pair(key, employee));
    }    
    
    virtual void modify(const Condition &targetCondition, const Condition &modifyCondition, Result &result) override {
        for (auto& employee : employees_) {
            auto& value = employee.second;

            if (targetCondition.isEqual(value)) {
                result.insert(value);
                modifyCondition.set(value);
            }
        }
    }

    virtual void erase(const Condition &targetCondition, Result &result) override {
        for (auto& employee : employees_) {
            auto& key = employee.first;
            auto& value = employee.second;

            if (targetCondition.isEqual(value)) {
                result.insert(value);
                employees_.erase(key);
            }
        }
    }

    virtual void search(const Condition &targetCondition, Result &result) override {
        for (auto& employee : employees_) {
            auto& value = employee.second;

            if (targetCondition.isEqual(value)) {
                result.insert(value);
            }
        }
    }
    
private:
    unordered_map<unsigned long, Employee> employees_;
};