#include <fstream>
#include <iostream>
#include <string>

#include "cmd.h"
#include "InputManager.h"
#include "OutputManager.h"
#include "IDataBase.h"

const unsigned MAX_LINE_SIZE = 512;

using namespace std;

int main(void)
{
    // TODO: need to implement these in 'employeeManager'
    InputManager* im = new InputManager("../input.txt");
    OutputManager* om = new OutputManager("../output.txt");
    shared_ptr<IDataBase> database = make_shared<DataBase>();

    while (im->isEndOfFile() == false) {
        vector<string> parsedCmd = im->getParsed();
        shared_ptr<ICmd> cmd = ICmd::getCmd(parsedCmd);

        cmd->execute(database);
        om->printResult(cmd->result_);
    }

    return 0;
}
