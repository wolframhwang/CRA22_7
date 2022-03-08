#include <fstream>
#include <iostream>
#include <string>

#include "cmd.h"
#include "InputManager.h"
#include "OutputManager.h"
#include "IDataBase.h"

enum ErrorType {
    ERROR_TYPE_SUCCESS = 0,
    ERROR_TYPE_INVALID_ARGUMENT_COUNT = 1,
};

const unsigned VALID_ARGUMENT_COUNT = 3;

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != VALID_ARGUMENT_COUNT) {
        cerr << "Error: Invalid argument count" << endl;
		exit(ERROR_TYPE_INVALID_ARGUMENT_COUNT);
	}

    const char* inputFileName = argv[1];
    const char* outputFileName = argv[2];

    InputManager* im = new InputManager(inputFileName);
    OutputManager* om = new OutputManager(outputFileName);
    shared_ptr<IDataBase> database = make_shared<DataBase>();

    while (im->isEndOfFile() == false) {
        vector<string> parsedCmd = im->getParsed();
        shared_ptr<ICmd> cmd = ICmd::getCmd(parsedCmd);
        if (cmd == nullptr) continue;

        cmd->execute(database);
        om->printResult(cmd->result_);
    }

    return ERROR_TYPE_SUCCESS;
}
