#include <fstream>
#include <iostream>
#include <string>

#include "InputManager.h"
#include "OutputManager.h"

using namespace std;

int main(void)
{
	/* = > �����δ� EmployeeManager �����ڿ��� Input.txt / Output.txt �Է� ���� ���� */

// while(eof) {
//  cmd = inputManager.getCmd()
//  database.execute(cmd)
// }

	Cmd* c = new Cmd();

	InputManager* im = new InputManager();
	im->getCmd();

	OutputManager* om = new OutputManager();
	om->printResult(*c);

	return 0;
}