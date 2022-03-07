#include "Condition.h"
#include "Employee.h"

ConditionPtr Condition::make(const string& type, const string& value) {
    if (type == "employeeNum") {
        if (ConditionEmployeeNum::isValid(value)) {
            return ConditionEmployeeNum::make(value);
        }
    }
    else if (type == "name") {
        if (ConditionName::isValid(value)) {
            return ConditionName::make(value);
        }
    }
    else if (type == "nameFirst") {
        if (ConditionNameFirst::isValid(value)) {
            return ConditionNameFirst::make(value);
        }
    }
    else if (type == "nameLast") {
        if (ConditionNameLast::isValid(value)) {
            return ConditionNameLast::make(value);
        }
    }
    else if (type == "cl") {
        if (ConditionCl::isValid(value)) {
            return ConditionCl::make(value);
        }
    }
    else if (type == "phoneNum") {
        if (ConditionPhoneNum::isValid(value)) {
            return ConditionPhoneNum::make(value);
        }
    }
    else if (type == "phoneNumMid") {
        if (ConditionPhoneNumMid::isValid(value)) {
            return ConditionPhoneNumMid::make(value);
        }
    }
    else if (type == "phoneNumEnd") {
        if (ConditionPhoneNumEnd::isValid(value)) {
            return ConditionPhoneNumEnd::make(value);
        }
    }
    else if (type == "birthday") {
        if (ConditionBirthday::isValid(value)) {
            return ConditionBirthday::make(value);
        }
    }
    else if (type == "birthdayYear") {
        if (ConditionBirthdayYear::isValid(value)) {
            return ConditionBirthdayYear::make(value);
        }
    }
    else if (type == "birthdayMonth") {
        if (ConditionBirthdayMonth::isValid(value)) {
            return ConditionBirthdayMonth::make(value);
        }
    }
    else if (type == "birthdayDay") {
        if (ConditionBirthdayDay::isValid(value)) {
            return ConditionBirthdayDay::make(value);
        }
    }
    else if (type == "certi") {
        if (ConditionCerti::isValid(value)) {
            return ConditionCerti::make(value);
        }
    }

    return nullptr;
}

bool ConditionEmployeeNum::isEqual(const Employee &employee) const {
    return employee.employeeNum == *this;
}

void ConditionEmployeeNum::set(Employee &employee) const {
    employee.employeeNum = employeeNum_;
}

ConditionEmployeeNum::operator string() const {
    auto result = to_string(employeeNum_);
    return string(result.c_str() + 2, 8);
}

bool ConditionNameFirst::isEqual(const Employee &employee) const {
    return employee.name.first_.first_ == first_;
}

void ConditionNameFirst::set(Employee &employee) const {
    employee.name.first_ = first_;
}

bool ConditionNameLast::isEqual(const Employee &employee) const {
    return employee.name.last_.last_ == last_;
}

void ConditionNameLast::set(Employee &employee) const {
    employee.name.last_ = last_;
}

bool ConditionName::isEqual(const Employee &employee) const {
    return first_.isEqual(employee) && last_.isEqual(employee);
}

void ConditionName::set(Employee &employee) const {
    first_.set(employee);
    last_.set(employee);
}

bool ConditionCl::isEqual(const Employee &employee) const {
    return employee.cl.cl_ == cl_;
}

void ConditionCl::set(Employee &employee) const {
    employee.cl = cl_;
}

bool ConditionPhoneNumMid::isEqual(const Employee &employee) const {
    return employee.phoneNum.mid == mid_;
}

void ConditionPhoneNumMid::set(Employee &employee) const {
    employee.phoneNum.mid = mid_;
}

bool ConditionPhoneNumEnd::isEqual(const Employee &employee) const {
    return employee.phoneNum.end == end_;
}

void ConditionPhoneNumEnd::set(Employee &employee) const {
    employee.phoneNum.end = end_;
}

bool ConditionPhoneNum::isEqual(const Employee &employee) const {
    return phoneNumMid_.isEqual(employee) && phoneNumEnd_.isEqual(employee);
}

void ConditionPhoneNum::set(Employee &employee) const {
    phoneNumMid_.set(employee);
    phoneNumEnd_.set(employee);
}

bool ConditionBirthdayYear::isEqual(const Employee &employee) const {
    return employee.birthday.year == year_;
}

void ConditionBirthdayYear::set(Employee &employee) const {
    employee.birthday.year = year_;
}

bool ConditionBirthdayMonth::isEqual(const Employee &employee) const {
    return employee.birthday.month == month_;
}

void ConditionBirthdayMonth::set(Employee &employee) const {
    employee.birthday.month = month_;
}

bool ConditionBirthdayDay::isEqual(const Employee &employee) const {
    return employee.birthday.day == day_;
}

void ConditionBirthdayDay::set(Employee &employee) const {
    employee.birthday.day = day_;
}

bool ConditionBirthday::isEqual(const Employee &employee) const {
    return conditionBirthdayYear.isEqual(employee) && conditionBirthdayMonth.isEqual(employee) && conditionBirthdayDay.isEqual(employee);
}

void ConditionBirthday::set(Employee &employee) const {
    conditionBirthdayYear.set(employee);
    conditionBirthdayMonth.set(employee);
    conditionBirthdayDay.set(employee);
}

bool ConditionCerti::isEqual(const Employee &employee) const {
    return employee.certi == certi_;
}

void ConditionCerti::set(Employee &employee) const {
    employee.certi = certi_;
}
