#include <fstream>
#include <iostream>
#include <string>

const unsigned MAX_LINE_SIZE = 512;

using namespace std;

int main(void)
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	while (inputFile.eof() == false) {
		char line[MAX_LINE_SIZE];

		inputFile.getline(line, MAX_LINE_SIZE, '\n');
		outputFile << line << endl;
	}

	return 0;
}