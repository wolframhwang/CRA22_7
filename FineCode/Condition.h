#pragma once

#include "common.h"

class Condition {
public:
    virtual bool isEqual(const Employee &employee) const = 0;
};

class ConditionEmployeeNum : public Condition {
public:
    ConditionEmployeeNum(const unsigned long &employeeNum) :
        employeeNum_(employeeNum) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return employee.employeeNum == employeeNum_;
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

private:
    string last_;
};

class ConditionName : public Condition {
public:
    ConditionName(string first, string last) :
        nameFirst(first), nameLast(last) {
    }

    virtual bool isEqual(const Employee &employee) const override {
        return nameFirst.isEqual(employee) && nameLast.isEqual(employee);
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

private:
    Grade certi_;
};
