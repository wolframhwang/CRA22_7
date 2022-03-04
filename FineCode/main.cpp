#include <fstream>
#include <iostream>
#include <string>

#include "InputManager.h"
#include "OutputManager.h"

using namespace std;

int main(void)
{
	/* = > 실제로는 EmployeeManager 생성자에서 Input.txt / Output.txt 입력 받을 예정 */

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