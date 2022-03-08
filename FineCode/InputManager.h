#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Employee.h"
#include "cmd.h"

using namespace std;

enum InputManagerType {
    INPUT_EMPLOYEENUM = 4,
    INPUT_NAME,
    INPUT_CL,
    INPUT_PHONENUM,
    INPUT_BIRTHDAY,
    INPUT_CERTI,
};

class InputManager {
public:
    InputManager(const string& inputFileName)
        : inputFileName_(inputFileName) {
        inputFileStream_.open(inputFileName_);
    }

    ~InputManager() {
        inputFileStream_.close();
    }

    bool isEndOfFile() {
        return inputFileStream_.eof();
    }

    void cmdParser(string inputFileName) {
        string line;

        // TODO: Using try/catch exception
        if (!inputFileStream_.is_open())
        {
            cout << "Can't open the file" << endl;
            return;
        }

        getline(inputFileStream_, line);
        cout << "cmdParser called!!!   " + line << endl;

        vector<string> values;
        string::size_type Fpos = line.find_first_not_of(',', 0);
        string::size_type Lpos = line.find_first_of(',', Fpos);

        if (string::npos == Lpos) {
            return;
        }

        while (string::npos != Fpos || string::npos != Lpos) {
            values.push_back(line.substr(Fpos, Lpos - Fpos));
            Fpos = line.find_first_not_of(',', Lpos);
            Lpos = line.find_first_of(',', Fpos);
        }

        parsedCmd_ = values;
    }

    vector<string> getParsed() {
        cmdParser(inputFileName_);
        return parsedCmd_;
    }

    bool isAddCmd() {
        return parsedCmd_.at(0) == "ADD";
    }

    shared_ptr<Employee> setEmployee() {
        return nullptr;
    }

private:
    ifstream inputFileStream_;
    string inputFileName_;
    vector<string> parsedCmd_;

    void setEmployeeNum(shared_ptr<Employee> employee) {
        // REMIND: Need to append "19" or "20" for easy sorting.
        employee->employeeNum = stoi(parsedCmd_.at(INPUT_EMPLOYEENUM));
    }

    void setName(shared_ptr<Employee> employee) {
        string fullName = parsedCmd_.at(INPUT_NAME);
        istringstream ss(fullName);
        vector <string> parsedFullName;
        string word;

        while (getline(ss, word, ' '))
            parsedFullName.push_back(word);

        employee->name.first = parsedFullName.at(0);
        employee->name.last = parsedFullName.at(1);
    }

    void setCl(shared_ptr<Employee> employee) {
        if (parsedCmd_.at(INPUT_CL) == "CL1") employee->cl = CL::CL1;
        else if (parsedCmd_.at(INPUT_CL) == "CL2") employee->cl = CL::CL2;
        else if (parsedCmd_.at(INPUT_CL) == "CL3") employee->cl = CL::CL3;
        else if (parsedCmd_.at(INPUT_CL) == "CL4") employee->cl = CL::CL4;
    }

    void setPhoneNum(shared_ptr<Employee> employee) {
        string fullPhoneNum = parsedCmd_.at(INPUT_PHONENUM);
        istringstream ss(fullPhoneNum);
        vector <string> parsedPhoneNum;
        string word;

        while (getline(ss, word, '-'))
            parsedPhoneNum.push_back(word);

        employee->phoneNum.mid = stoi(parsedPhoneNum.at(1));
        employee->phoneNum.end = stoi(parsedPhoneNum.at(2));
    }

    void setBirthDay(shared_ptr<Employee> employee) {
        int birthDayWithEightDigits = stoi(parsedCmd_.at(INPUT_BIRTHDAY));

        employee->birthday.year = birthDayWithEightDigits / 10000;
        employee->birthday.month = (birthDayWithEightDigits / 100) % 100;
        employee->birthday.day = birthDayWithEightDigits % 100;
    }

    void setCerti(shared_ptr<Employee> employee) {
        if (parsedCmd_.at(INPUT_CERTI) == "ADV") employee->certi = Grade::ADV;
        else if (parsedCmd_.at(INPUT_CERTI) == "PRO") employee->certi = Grade::PRO;
        else if (parsedCmd_.at(INPUT_CERTI) == "EX") employee->certi = Grade::EX;
    }
};
