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
    // TODO: need to implement in 'employeeManager'
    // while (input is done) {
    InputManager* im = new InputManager("../input.txt");
    ICmd c = im->getCmd(); // TODO: Can't return (pure) virtual function, need to fix
    // call output manager
    // }

    return 0;
}
