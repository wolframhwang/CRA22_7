#include "Employee.h"

#include <string>
#include <vector>
#include <queue>

using namespace std;

const int PCommand = 5;

class Result {    
public:    
    Result() { 
        entryCount = 0; 
        employees = priority_queue<EmployeeInfo>(); 
    }
    ~Result() {}

    void setEntryCountPlus() {
        entryCount += 1;
    }

    int getEntryCount() {
        return entryCount;
    }

    void employeeAddonResult(EmployeeInfo emp) {
        employees.push(emp);
    }
    
    vector<string> employeesPrint() {
        vector<string> ret;
        for(int i = 0; i < PCommand; i++) {
            if(employees.empty()) return ret;
            ret.push_back(toString(employees.top()));
            employees.pop();
        }
        return ret;
    }
    
private:
    int entryCount;
    priority_queue<EmployeeInfo> employees;
};