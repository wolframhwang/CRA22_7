#pragma once

#include <memory>
#include <string>

using namespace std;

enum class CL {
    CL1,
    CL2,
    CL3,
    CL4,
    INVALID
};

enum class Grade {
    ADV,
    PRO,
    EX,
    INVALID
};

struct PhoneNum {
    int mid;
    int end;
};

struct Name {
    string first;
    string last;
};

struct Date {
    int year;
    int month;
    int day;
};

class Condition;
using ConditionPtr = shared_ptr<Condition>;
struct Employee;

class Condition {
public:
    static ConditionPtr make(const string &type, const string &value);
    
    virtual bool isEqual(const Employee &employee) const = 0;
    virtual void set(Employee &employee) const = 0;
    virtual operator string() const { return ""; };
};

class ConditionEmployeeNum : public Condition {
public:
    static ConditionPtr make(const string& employeeNum) {
        return make_shared<ConditionEmployeeNum>(employeeNum);
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

    ConditionEmployeeNum() : employeeNum_(0) {}

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

    operator unsigned long() const {
        return employeeNum_;
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;
    virtual operator string() const override;

private:
    unsigned long employeeNum_;
};

class ConditionNameFirst : public Condition {
public:
    static ConditionPtr make(const string& first) {
        return make_shared<ConditionNameFirst>(first);
    }

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

    ConditionNameFirst() {}
    ConditionNameFirst(const string &first) :
        first_(first) {
    }

    operator string() const {
        return first_;
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

private:
    string first_;
};

class ConditionNameLast : public Condition {
public:
    static ConditionPtr make(const string& last) {
        return make_shared<ConditionNameLast>(last);
    }

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

    ConditionNameLast() {}
    ConditionNameLast(const string &last) :
        last_(last) {
    }

    operator string() const {
        return last_;
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

private:
    string last_;
};

class ConditionName : public Condition {
public:
    static ConditionPtr make(const string& name) {
        return make_shared<ConditionName>(name);
    }

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

    ConditionName(const string &_first, const string &_last) :
        first(_first), last(_last) {
    }

    ConditionName(const Name &name) :
        first(name.first), last(name.last) {
    }

    ConditionName(const string &name) {
        size_t pos = name.find(' ');
        string _first = { name.c_str(), pos};
        string _last  = { name.c_str() + pos + 1, name.length() - _first.length() - 1};

        first = _first;
        last  = _last;
    }

    operator string() const {
        return string(first) + " " + string(last);
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

    ConditionNameFirst first;
    ConditionNameLast last;
};

class ConditionCl : public Condition {
public:
    static ConditionPtr make(const string& clString) {
        CL cl;

        switch (clString[2]) {
        case '1':
            cl = CL::CL1;
            break;
        case '2':
            cl = CL::CL2;
            break;
        case '3':
            cl = CL::CL3;
            break;
        case '4':
            cl = CL::CL4;
            break;
        }

        return make_shared<ConditionCl>(cl);
    }

    static bool isValid(const string& cl) {
        if (cl.length() != 3) {
            return false;
        }

        if (cl[0] != 'C' || cl[1] != 'L') {
            return false;
        }

        if (cl[2] < '1' || cl[2] > '4') {
            return false;
        }

        return true;
    }

    ConditionCl(const CL &cl) :
        cl_(cl) {
    }

    ConditionCl(const string& cl) : cl_(CL::INVALID) {
        switch (cl[2]) {
        case '1':
            cl_ = CL::CL1;
            break;
        case '2':
            cl_ = CL::CL2;
            break;
        case '3':
            cl_ = CL::CL3;
            break;
        case '4':
            cl_ = CL::CL4;
            break;
        }
    }

    operator string() const {
        switch (cl_) {
        case CL::CL1:
            return "CL1";
        case CL::CL2:
            return "CL2";
        case CL::CL3:
            return "CL3";
        case CL::CL4:
            return "CL4";
        default:
            return "INVALID";
        }
    }

    operator CL() const {
        return cl_;
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

private:
    CL cl_;
};

class ConditionPhoneNumMid : public Condition {
public:
    static ConditionPtr make(const string& mid) {
        return make_shared<ConditionPhoneNumMid>(stoi(mid));
    }

    static bool isValid(const string& mid) {
        const unsigned PHONE_NUM_MID_LENGTH = 4;

        if (mid.length() != PHONE_NUM_MID_LENGTH) {
            return false;
        }

        for (auto elem : mid) {
            if (elem < '0' || elem > '9') {
                return false;
            }
        }

        return true;
    }

    ConditionPhoneNumMid() :
        ConditionPhoneNumMid(0) {
    }

    ConditionPhoneNumMid(int mid) :
        mid_(mid) {
    }

    ConditionPhoneNumMid(const string& mid) :
        mid_(stoi(mid)) {
    }

    operator int() const {
        return mid_;
    }

    operator string() const {
        auto result = to_string(mid_);
        while (result.length() < 4) {
            result = "0" + result;
        }
        return result;
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

private:
    int mid_;
};

class ConditionPhoneNumEnd : public Condition {
public:
    static ConditionPtr make(const string& end) {
        return make_shared<ConditionPhoneNumEnd>(stoi(end));
    }

    static bool isValid(const string& end) {
        const unsigned PHONE_NUM_END_LENGTH = 4;

        if (end.length() != PHONE_NUM_END_LENGTH) {
            return false;
        }

        for (auto elem : end) {
            if (elem < '0' || elem > '9') {
                return false;
            }
        }

        return true;
    }

    ConditionPhoneNumEnd() :
        ConditionPhoneNumEnd(0) {
    }

    ConditionPhoneNumEnd(int end) :
        end_(end) {
    }

    ConditionPhoneNumEnd(const string& end) :
        end_(stoi(end)) {
    }

    operator int() const {
        return end_;
    }

    operator string() const {
        auto result = to_string(end_);
        while (result.length() < 4) {
            result = "0" + result;
        }
        return result;
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

private:
    int end_;
};

class ConditionPhoneNum : public Condition {
public:
    static ConditionPtr make(const string& phoneNum) {
        return make_shared<ConditionPhoneNum>(phoneNum);
    }

    static bool isValid(const string& phoneNum) {
        const unsigned PHONE_NUM_LENGTH = 13;

        if (phoneNum.length() != PHONE_NUM_LENGTH) {
            return false;
        }

        if (phoneNum[3] != '-' || phoneNum[8] != '-') {
            return false;
        }

        if (phoneNum[0] != '0' || phoneNum[1] != '1' || phoneNum[2] != '0') {
            return false;
        }

        string phoneNumMid = string(phoneNum.c_str() + 4, 4);
        string phoneNumEnd = string(phoneNum.c_str() + 9, 4);
        return ConditionPhoneNumMid::isValid(phoneNumMid) && ConditionPhoneNumEnd::isValid(phoneNumEnd);
    }

    ConditionPhoneNum(int _mid, int _end) :
        mid(_mid), end(_end) {
    }

    ConditionPhoneNum(const PhoneNum& phoneNum) :
        mid(phoneNum.mid), end(phoneNum.end) {
    }

    ConditionPhoneNum(const string& phoneNum) {
        mid = string(phoneNum.c_str() + 4, 4);
        end = string(phoneNum.c_str() + 9, 4);
    }

    operator string() const {
        return "010-" + string(mid) + "-" + string(end);
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

public:
    ConditionPhoneNumMid mid;
    ConditionPhoneNumEnd end;
};

class ConditionBirthdayYear : public Condition {
public:
    static ConditionPtr make(const string& year) {
        return make_shared<ConditionBirthdayYear>(stoi(year));
    }

    static bool isValid(const string& year) {
        static const unsigned BIRTHDAY_YEAR_LENGTH = 4;

        if (year.length() != BIRTHDAY_YEAR_LENGTH) {
            return false;
        }

        for (auto elem : year) {
            if (elem < '0' || elem > '9') {
                return false;
            }
        }

        return true;
    }

    ConditionBirthdayYear(const int &year) :
        year_(year) {
    }

    ConditionBirthdayYear(const string &year) :
        ConditionBirthdayYear(stoi(year)) {
    }

    operator int() const {
        return year_;
    }

    operator string() const {
        auto result = to_string(year_);
        while (result.length() < 4) {
            result = "0" + result;
        }
        return result;
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

private:
    int year_;
};

class ConditionBirthdayMonth : public Condition {
public:
    static ConditionPtr make(const string& month) {
        return make_shared<ConditionBirthdayMonth>(stoi(month));
    }

    static bool isValid(const string& month) {
        static const unsigned BIRTHDAY_MONTH_LENGTH = 2;

        if (month.length() != BIRTHDAY_MONTH_LENGTH) {
            return false;
        }

        for (auto elem : month) {
            if (elem < '0' || elem > '9') {
                return false;
            }
        }

        auto value = std::stoul(month);
        if (value < 1 || value > 12) {
            return false;
        }

        return true;
    }

    ConditionBirthdayMonth(const int &month) :
        month_(month) {
    }

    ConditionBirthdayMonth(const string &month) :
        ConditionBirthdayMonth(stoi(month)) {
    }

    operator int() const {
        return month_;
    }

    operator string() const {
        auto result = to_string(month_);
        while (result.length() < 2) {
            result = "0" + result;
        }
        return result;
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

private:
    int month_;
};

class ConditionBirthdayDay : public Condition {
public:
    static ConditionPtr make(const string& day) {
        return make_shared<ConditionBirthdayDay>(stoi(day));
    }

    static bool isValid(const string& day) {
        static const unsigned BIRTHDAY_DAY_LENGTH = 2;

        if (day.length() != BIRTHDAY_DAY_LENGTH) {
            return false;
        }

        for (auto elem : day) {
            if (elem < '0' || elem > '9') {
                return false;
            }
        }

        auto value = std::stoul(day);
        if (value < 1 || value > 31) {
            return false;
        }

        return true;
    }

    ConditionBirthdayDay(const int &day) :
        day_(day) {
    }

    ConditionBirthdayDay(const string &day) :
        ConditionBirthdayDay(stoi(day)) {
    }

    operator int() const {
        return day_;
    }

    operator string() const {
        auto result = to_string(day_);
        while (result.length() < 2) {
            result = "0" + result;
        }
        return result;
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

private:
    int day_;
};

class ConditionBirthday : public Condition {
public:
    static ConditionPtr make(const string& birthday) {
        return make_shared<ConditionBirthday>(birthday);
    }

    static bool isValid(const string& birthday) {
        static const unsigned BIRTHDAY_LENGTH = 8;

        if (birthday.length() != BIRTHDAY_LENGTH) {
            return false;
        }

        string year  = string(birthday.c_str(), 4);
        string month = string(birthday.c_str() + 4, 2);
        string day   = string(birthday.c_str() + 6, 2);
        return ConditionBirthdayYear::isValid(year) && ConditionBirthdayMonth::isValid(month) && ConditionBirthdayDay::isValid(day);
    }

    ConditionBirthday(const int &_year, const int &_month, const int &_day) :
        year(_year), month(_month), day(_day) {
    }

    ConditionBirthday(Date birthday) :
        ConditionBirthday(birthday.year, birthday.month, birthday.day) {
    }

    ConditionBirthday(const string& birthday) :
        year(string(birthday.c_str(), 4)),
        month(string(birthday.c_str() + 4, 2)),
        day(string(birthday.c_str() + 6, 2)) {
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

    operator string() const {
        return string(year) + string(month) + string(day);
    }

public:
    ConditionBirthdayYear  year;
    ConditionBirthdayMonth month;
    ConditionBirthdayDay   day;
};

class ConditionCerti : public Condition {
public:
    static ConditionPtr make(const string& certiString) {
        Grade certi;
        if (certiString == "ADV") {
            certi = Grade::ADV;
        }
        else if (certiString == "PRO") {
            certi = Grade::PRO;
        }
        else if (certiString == "EX") {
            certi = Grade::EX;
        }

        return make_shared<ConditionCerti>(certi);
    }

    static bool isValid(const string& certi) {
        return certi == "ADV" || certi == "PRO" || certi == "EX";
    }

    ConditionCerti(const Grade& certi) :
        certi_(certi) {
    }

    ConditionCerti(const string& certi) {
        if (certi == "ADV") {
            certi_ = Grade::ADV;
        }
        else if (certi == "PRO") {
            certi_ = Grade::PRO;
        }
        else if (certi == "EX") {
            certi_ = Grade::EX;
        }
        else {
            certi_ = Grade::INVALID;
        }
    }

    operator Grade() const {
        return certi_;
    }

    operator string() const {
        switch (certi_) {
        case Grade::ADV:
            return "ADV";
        case Grade::PRO:
            return "PRO";
        case Grade::EX:
            return "EX";
        }
        return "INVALID";
    }

    virtual bool isEqual(const Employee &employee) const override;
    virtual void set(Employee &employee) const override;

private:
    Grade certi_;
};
