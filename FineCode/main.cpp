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
    InputManager* im = new InputManager("input.txt");
    while (im->isEndOfFile() == false) {
        //ICmd c = im->getCmd(); // TODO: Can't return (pure) virtual function, need to fix
        im->getCmd();
        if (im->isAddCmd()) {
            Employee e = im->setEmployee();
        }
        OutputManager* om = new OutputManager();
        //om->printResult(c); // TODO: Can't input (pure) virtual function, need to fix
    }

    return 0;
}
