#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "common.h"

using namespace std;

class InputManager {
private:
	string inputFileName_;

public:
	void cmdParser(string inputFileName) {
		ifstream inputFileStream;
		char inputArr[MAX_LINE_SIZE] = {};

		// load file
		inputFileStream.open(inputFileName);
		if (inputFileStream.is_open())
			while (!inputFileStream.eof())
				inputFileStream.getline(inputArr, MAX_LINE_SIZE);
		inputFileStream.close();

		cout << inputArr << endl;

		string inputStr = +inputArr;

		vector<string> values;
		string::size_type Fpos = inputStr.find_first_not_of(',', 0);
		string::size_type Lpos = inputStr.find_first_of(',', Fpos);

		while (string::npos != Fpos || string::npos != Lpos) {
			values.push_back(inputStr.substr(Fpos, Lpos - Fpos));
			Fpos = inputStr.find_first_not_of(',', Lpos);
			Lpos = inputStr.find_first_of(',', Fpos);
		}

		// fill cmd by its form

		for (auto value : values) cout << value << endl;
	}

	void getCmd() {
		cmdParser("input_test.txt");
	}
};