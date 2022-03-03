#include <map>
#include "Util.h"

using namespace std;

struct IDataBase {
    virtual bool add(EmployeeInfo employeeInfo);
    virtual bool modify(int employeeNumber, EmployeeInfo employeeInfo);
    virtual bool erase(int employeeNumber);
    virtual EmployeeInfo* getEmployeeInfo(int employeeNumber);
};

class DataBase: public IDataBase {
public:
    DataBase() {}
    virtual ~DataBase() {}

    virtual bool add(EmployeeInfo employee) override {
        int employeeNum = employee.employeeNumber;        
        return employeesList.insert(make_pair(employeeNum, employee)).second;
    }    
    
    virtual bool modify(int employeeNumber, EmployeeInfo employeeInfo) {
        if(employeesList.find(employeeNumber) == employeesList.end()) return false;
        employeesList[employeeNumber] = employeeInfo;
        return true;
    }

    virtual bool erase(int employeeNumber) {
        return employeesList.erase(employeeNumber);
    }
    
private:
    map<int, EmployeeInfo> employeesList;

};