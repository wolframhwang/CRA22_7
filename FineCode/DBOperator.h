#pragma once
#include <fstream>
#include <vector>

#include "common.h"
using namespace std;

class DBOperator {
public:
	DBOperator();
	~DBOperator();
	bool ADD(Employee& employee);
	int DEL(EInfoType einfotype, string target);
	int SCH(EInfoType einfotype, string target);
	int MOD(EInfoType einfotype, string from, string to);

private:
	void print(vector<Employee> employee);
	bool isValidFormat();
	void parser();
	void loadInput();
private:
	ifstream input;
	vector<Employee> retrievedEmployee;
};