#include "cmd.h"

shared_ptr<ICmd> ICmd::getCmd(const vector<string>& params) {
    auto type = params[0];

    if (type == "ADD") {
        if (ConditionEmployeeNum::isValid(params[4]) &&
            ConditionName::isValid(params[5]) &&
            ConditionCl::isValid(params[6]) &&
            ConditionPhoneNum::isValid(params[7]) &&
            ConditionBirthday::isValid(params[8]) &&
            ConditionCerti::isValid(params[9])) {
        
            Employee *employee = new Employee(vector<string>(params.begin() + 4, params.end()));
            Result *result = new ResultNone(type);
            return make_shared<CmdAdd>(CmdAdd{ employee, result });
        }
        throw std::invalid_argument("getCmd() : ADD");
    }
    else {
        auto targetType = params[4];
        Result *result = nullptr;
        if (params[1] == "-p") {
            result = new ResultTop(type, 5);
        }
        else {
            result = new ResultCount(type);
        }

        if (targetType == "name") {
            if (params[2] == "-f") {
                targetType += "First";
            }
            else if (params[2] == "-l") {
                targetType += "Last";
            }
        }
        else if (targetType == "phoneNum") {
            if (params[2] == "-m") {
                targetType += "Mid";
            }
            else if (params[2] == "-l") {
                targetType += "End";
            }
        }
        else if (targetType == "birthday") {
            if (params[2] == "-y") {
                targetType += "Year";
            }
            if (params[2] == "-m") {
                targetType += "Month";
            }
            if (params[2] == "-d") {
                targetType += "Day";
            }
        }

        if (type == "SCH") {
            auto targetValue = params[5];
            auto targetCondition = Condition::make(targetType, targetValue);
            return make_shared<CmdSearch>(CmdSearch{ targetCondition, result });
        }
        else if (type == "DEL") {
            auto targetValue = params[5];
            auto targetCondition = Condition::make(targetType, targetValue);
            return make_shared<CmdErase>(CmdErase{ targetCondition, result });
        }
        else if (type == "MOD") {
            auto targetValue = params[5];
            auto targetCondition = Condition::make(targetType, targetValue);
            auto modifyType = params[6];
            auto modifyValue = params[7];
            auto modifyCondition = Condition::make(modifyType, modifyValue);
            return make_shared<CmdModify>(CmdModify{ targetCondition, modifyCondition, result });
        }
    }
    
    return nullptr;
}
