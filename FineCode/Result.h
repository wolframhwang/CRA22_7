#pragma once

#include "Employee.h"
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int maxEmployeePrintCount = 5;

class Result {    
public:    
    Result() { 
        entryCount = 0; 
        employees = priority_queue<Employee>(); 
    }
    ~Result() {}

    void setEntryCountPlus() {
        entryCount += 1;
    }

    int getEntryCount() {
        return entryCount;
    }

    void employeeAddonResult(Employee emp) {
        employees.push(emp);
    }
    
    vector<string> employeesPrint() {
        vector<string> ret;
        for(int i = 0; i < maxEmployeePrintCount; i++) {
            if(employees.empty()) return ret;
            ret.push_back(toString(employees.top()));
            employees.pop();
        }
        return ret;
    }

private:
    string toString(const Employee& employee) {
        return "Not Implemented"s;
    }

    int entryCount;
    priority_queue<Employee> employees;
};
