#pragma once
#include <fstream>
#include <string>

#include "Employee.h"

using namespace std;

class OutputManager {
public:
    void printResult(ICmd cmd) {
        // Not implemented yet
        ofstream outputFile("output_test.txt");

        // case 1
        outputFile << "SCH, 1" << endl;
        // case 2
        outputFile << "MOD, 17112609, FB NTAWR, CL4, 010 - 5645 - 6122, 20050520, PRO" << endl;
    }
    
private:
    string outputFileName_;
};
