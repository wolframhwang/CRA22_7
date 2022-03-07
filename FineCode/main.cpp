#include <fstream>
#include <iostream>
#include <string>

#include "cmd.h"
#include "InputManager.h"
#include "OutputManager.h"

const unsigned MAX_LINE_SIZE = 512;

using namespace std;

int main(void)
{
    // TODO: need to implement these in 'employeeManager'
    InputManager* im = new InputManager("../input.txt");
    OutputManager* om = new OutputManager("../output.txt");

    while (im->isEndOfFile() == false) {
        vector<string> parsedCmd = im->getParsed();
        string queryType = parsedCmd.at(0);
        shared_ptr<ICmd> cmd = ICmd::getCmd(parsedCmd.at(0));
        cmd->setParsedCmd(parsedCmd);

        // Set Employee, if query is ADD
        if (im->isAddCmd()) Employee employee = im->setEmployee();

        // TODO: Run database, get result
        om->printResult(/* Result */);
    }

    return 0;
}
