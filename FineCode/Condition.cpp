#include "Condition.h"

ConditionPtr Condition::make(const string& type, const string& value) {
    if (type == "employeeNum") {
        return ConditionEmployeeNum::checkAndMake(value);
    }
    else if (type == "name") {
        return ConditionName::checkAndMake(value);
    }
    else if (type == "nameFirst") {
        return ConditionNameFirst::checkAndMake(value);
    }
    else if (type == "nameLast") {
        return ConditionNameLast::checkAndMake(value);
    }
    else if (type == "cl") {
        return ConditionCl::checkAndMake(value);
    }
    else if (type == "phoneNum") {
        return ConditionPhoneNum::checkAndMake(value);
    }
    else if (type == "phoneNumMid") {
        return ConditionPhoneNumMid::checkAndMake(value);
    }
    else if (type == "phoneNumEnd") {
        return ConditionPhoneNumEnd::checkAndMake(value);
    }
    else if (type == "birthday") {
        return ConditionBirthday::checkAndMake(value);
    }
    else if (type == "birthdayYear") {
        return ConditionBirthdayYear::checkAndMake(value);
    }
    else if (type == "birthdayMonth") {
        return ConditionBirthdayMonth::checkAndMake(value);
    }
    else if (type == "birthdayDay") {
        return ConditionBirthdayDay::checkAndMake(value);
    }
    else if (type == "certi") {
        return ConditionCerti::checkAndMake(value);
    }

    return nullptr;
}
