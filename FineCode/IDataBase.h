#pragma once
#include <map>
#include <vector>
#include "Employee.h"
#include "cmd.h"
#include "Condition.h"

using namespace std;

struct IDataBase {
    virtual bool add(EmployeeInfo employeeInfo) = 0;
    virtual bool modify(unsigned long employeeNumber, Condition &modifyCondtion) = 0;
    virtual bool erase(unsigned int employeeNumber) = 0;
    virtual vector<unsigned long> search(Condition &searchCondition) = 0;
    virtual EmployeeInfo* getEmployeeInfo(unsigned int employeeNumber) = 0;
};

class DataBase: public IDataBase {
public:
    DataBase() { mutex = false; }
    virtual ~DataBase() {}

    virtual bool add(EmployeeInfo employee) override {
        int employeeNum = employee.employeeNum;
        return employeesList.insert(make_pair(employeeNum, employee)).second;
    }    
    
    virtual bool modify(unsigned long employeeNumber, Condition &modifyCondition) override {
        if(mutex) return false;
        mutex = true;
        modifyCondition.set(employeesList[employeeNumber]);
        mutex = false;
        return true;
    }

    virtual bool erase(unsigned int employeeNumber) override {
        if(mutex) return false;
        if(employeesList.find(employeeNumber) == employeesList.end()) return false;
        mutex = true;
        employeesList.erase(employeeNumber);
        mutex = false;
        return employeesList.erase(employeeNumber);
    }

    virtual vector<unsigned long> search(Condition &searchCondition) {
        vector<unsigned long> ret;
        for(auto employee: employeesList) {
            if (searchCondition.isEqual(employee.second)) {
                ret.push_back(employee.first);
            }
        }
        return ret;
    }

    virtual EmployeeInfo* getEmployeeInfo(unsigned int employeeNumber) override {
        if (employeesList.find(employeeNumber) == employeesList.end()) return NULL;
        return &employeesList[employeeNumber];
    }
    
private:
    map<unsigned long, EmployeeInfo> employeesList;
    bool mutex;
};