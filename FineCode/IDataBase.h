#include <map>
#include "common.h"

using namespace std;

struct IDataBase {
    virtual bool add(EmployeeInfo employeeInfo) = 0;
    virtual bool modify(unsigned int employeeNumber, EmployeeInfo employeeInfo) = 0;
    virtual bool erase(unsigned int employeeNumber) = 0;
    virtual EmployeeInfo* getEmployeeInfo(unsigned int employeeNumber) = 0;
};

class DataBase: public IDataBase {
public:
    DataBase() {}
    virtual ~DataBase() {}

    virtual bool add(EmployeeInfo employee) override {
        int employeeNum = employee.employeeNum;
        return employeesList.insert(make_pair(employeeNum, employee)).second;
    }    
    
    virtual bool modify(unsigned int employeeNumber, EmployeeInfo employeeInfo) override {
        if(employeesList.find(employeeNumber) == employeesList.end()) return false;
        employeesList[employeeNumber] = employeeInfo;
        return true;
    }

    virtual bool erase(unsigned int employeeNumber) override {
        return employeesList.erase(employeeNumber);
    }

    virtual EmployeeInfo* getEmployeeInfo(unsigned int employeeNumber) override {
        if (employeesList.find(employeeNumber) == employeesList.end()) return NULL;
        return &employeesList[employeeNumber];
    }
    
private:
    map<int, EmployeeInfo> employeesList;

};