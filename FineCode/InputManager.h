#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "cmd.h"

using namespace std;

class InputManager {
public:
    InputManager(const string& inputFileName)
        : inputFileName_(inputFileName) {
        inputFileStream_.open(inputFileName_);
    }

    ~InputManager() {
        inputFileStream_.close();
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

        while (string::npos != Fpos || string::npos != Lpos) {
            values.push_back(line.substr(Fpos, Lpos - Fpos));
            Fpos = line.find_first_not_of(',', Lpos);
            Lpos = line.find_first_of(',', Fpos);
        }
        parsedCmd_ = values;
    }

    ICmd getCmd() {
        shared_ptr<ICmd> c = make_shared<ICmd>();
        cmdParser(inputFileName_);
        c->setParsedCmd(parsedCmd_);

        return *c;
    }

private:
    ifstream inputFileStream_;
    string inputFileName_;
    vector<string> parsedCmd_;
};
