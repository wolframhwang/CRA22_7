#include "Condition.h"

class ConditionEmployeeNum : public Condition {
public:
    static bool isValid(const string &employeeNum) {
        static const unsigned EMPLOYEE_NUM_LENGTH = 8;

        if (employeeNum.length() != EMPLOYEE_NUM_LENGTH) {
            return false;
        }

        for (auto elem : employeeNum) {
            if (elem < '0' || elem > '9') {
                return false;
            }
        }

        unsigned year = (employeeNum[0] - '0') * 10 + (employeeNum[1] - '0');
        if (year > 21 && year < 69) {
            return false;
        }

        return true;
    }

    ConditionEmployeeNum(const unsigned long &employeeNum) :
        employeeNum_(employeeNum) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return employee.employeeNum == employeeNum_;
    }

    virtual void set(Employee &employee) const override {
        employee.employeeNum = employeeNum_;
    }

private:
    unsigned long employeeNum_;
};

class ConditionNameFirst : public Condition {
public:
    static bool isValid(const string &first) {
        if (first.length() == 0) {
            return false;
        }

        for (auto elem : first) {
            if (elem < 'A' || elem > 'Z') {
                return false;
            }
        }

        return true;
    }

    ConditionNameFirst(const string &first) :
        first_(first) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return employee.name.first == first_;
    }

    virtual void set(Employee &employee) const override {
        employee.name.first = first_;
    }

private:
    string first_;
};

class ConditionNameLast : public Condition {
public:
    static bool isValid(const string &last) {
        if (last.length() == 0) {
            return false;
        }

        for (auto elem : last) {
            if (elem < 'A' || elem > 'Z') {
                return false;
            }
        }

        return true;
    }

    ConditionNameLast(const string &last) :
        last_(last) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return employee.name.last == last_;
    }

    virtual void set(Employee &employee) const override {
        employee.name.last = last_;
    }

private:
    string last_;
};

class ConditionName : public Condition {
public:
    static bool isValid(const string &name) {
        static const unsigned MAX_NAME_LENGTH = 15;

        if (name.length() > MAX_NAME_LENGTH) {
            return false;
        }

        size_t pos = name.find(' ');
        if (pos == string::npos) {
            return false;
        }

        string first = { name.c_str(), pos };
        string last  = { name.c_str() + pos + 1, name.length() - first.length() - 1};
        return ConditionNameFirst::isValid(first) && ConditionNameLast::isValid(last);
    }

    ConditionName(const string &first, const string &last) :
        nameFirst(first), nameLast(last) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return nameFirst.isEqual(employee) && nameLast.isEqual(employee);
    }

    virtual void set(Employee &employee) const override {
        nameFirst.set(employee);
        nameLast.set(employee);
    }

private:
    ConditionNameFirst nameFirst;
    ConditionNameLast nameLast;
};

class ConditionCl : public Condition {
public:
    static bool isValid(const string& cl) {
        return false;
    }

    ConditionCl(const CL &cl) :
        cl_(cl) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return employee.cl == cl_;
    }

    virtual void set(Employee &employee) const override {
        employee.cl = cl_;
    }

private:
    CL cl_;
};

class ConditionPhoneNumMid : public Condition {
public:
    ConditionPhoneNumMid(int mid) :
        mid_(mid) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return employee.phoneNum.mid == mid_;
    }

    virtual void set(Employee &employee) const override {
        employee.phoneNum.mid = mid_;
    }

private:
    int mid_;
};

class ConditionPhoneNumEnd : public Condition {
public:
    ConditionPhoneNumEnd(int end) :
        end_(end) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return employee.phoneNum.end == end_;
    }

    virtual void set(Employee &employee) const override {
        employee.phoneNum.end = end_;
    }

private:
    int end_;
};

class ConditionPhoneNum : public Condition {
public:
    ConditionPhoneNum(int mid, int end) :
        phoneNumMid_(mid), phoneNumEnd_(end) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return phoneNumMid_.isEqual(employee) && phoneNumEnd_.isEqual(employee);
    }

    virtual void set(Employee &employee) const override {
        phoneNumMid_.set(employee);
        phoneNumEnd_.set(employee);
    }

private:
    ConditionPhoneNumMid phoneNumMid_;
    ConditionPhoneNumEnd phoneNumEnd_;
};

class ConditionBirthdayYear : public Condition {
public:
    ConditionBirthdayYear(const int &year) :
        year_(year) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return employee.birthday.year == year_;
    }

    virtual void set(Employee &employee) const override {
        employee.birthday.year = year_;
    }

private:
    int year_;
};

class ConditionBirthdayMonth : public Condition {
public:
    ConditionBirthdayMonth(const int &month) :
        month_(month) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return employee.birthday.month == month_;
    }

    virtual void set(Employee &employee) const override {
        employee.birthday.month = month_;
    }

private:
    int month_;
};

class ConditionBirthdayDay : public Condition {
public:
    ConditionBirthdayDay(const int &day) :
        day_(day) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return employee.birthday.day == day_;
    }

    virtual void set(Employee &employee) const override {
        employee.birthday.day = day_;
    }

private:
    int day_;
};

class ConditionBirthday : public Condition {
public:
    ConditionBirthday(const int &year, const int &month, const int &day) :
        conditionBirthdayYear(year), conditionBirthdayMonth(month), conditionBirthdayDay(day) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return conditionBirthdayYear.isEqual(employee) && conditionBirthdayMonth.isEqual(employee) && conditionBirthdayDay.isEqual(employee);
    }

    virtual void set(Employee &employee) const override {
        conditionBirthdayYear.set(employee);
        conditionBirthdayMonth.set(employee);
        conditionBirthdayDay.set(employee);
    }

private:
    ConditionBirthdayYear  conditionBirthdayYear;
    ConditionBirthdayMonth conditionBirthdayMonth;
    ConditionBirthdayDay   conditionBirthdayDay;
};

class ConditionCerti : public Condition {
public:
    ConditionCerti(const Grade &certi) :
        certi_(certi) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return employee.certi == certi_;
    }

    virtual void set(Employee &employee) const override {
        employee.certi = certi_;
    }

private:
    Grade certi_;
};
