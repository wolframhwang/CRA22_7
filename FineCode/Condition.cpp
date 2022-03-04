#include "Condition.h"

class ConditionEmployeeNum : public Condition {
public:
    static ConditionPtr checkAndMake(const string& employeeNum) {
        if (isValid(employeeNum)) {
            return make_shared<ConditionEmployeeNum>(employeeNum);
        }
        return nullptr;
    }

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

    ConditionEmployeeNum(const string &employeeNum) {
        unsigned year = (employeeNum[0] - '0') * 10 + (employeeNum[1] - '0');
        if (year >= 69) {
            employeeNum_ = stoul("19" + employeeNum);
        }
        else
        {
            employeeNum_ = stoul("20" + employeeNum);
        }
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
    static ConditionPtr checkAndMake(const string& name) {
        if (ConditionName::isValid(name)) {
            size_t pos = name.find(' ');

            if (pos > 0 && pos < name.length() - 1) {
                string first = { name.c_str(), pos};
                string last  = { name.c_str() + pos + 1, name.length() - first.length() - 1};

                return make_shared<ConditionName>(first, last);
            }
        }

        return nullptr;
    }

    static bool isValid(const string &name) {
        static const unsigned MAX_NAME_LENGTH = 15;
        static const unsigned MIN_NAME_LENGTH = 3;

        if (name.length() > MAX_NAME_LENGTH || name.length() < MIN_NAME_LENGTH) {
            return false;
        }

        unsigned countSpace = 0;
        for (auto elem : name) {
            if (elem == ' ') {
                if (countSpace > 0) {
                    return false;
                }
                countSpace++;
                continue;
            }

            if (elem < 'A' || elem > 'Z') {
                return false;
            }
        }
        if (countSpace == 0) {
            return false;
        }

        if (name[0] == ' ' || name[name.length() - 1] == ' ') {
            return false;
        }

        return true;
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

ConditionPtr Condition::make(const string& type, const string& value) {
    ConditionPtr result = nullptr;

    if (type == "employeeNum") {
        return ConditionEmployeeNum::checkAndMake(value);
    }
    else if (type == "name") {
        return ConditionName::checkAndMake(value);
    }

    return result;
}
