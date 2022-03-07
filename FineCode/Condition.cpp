#include "Condition.h"

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
