#pragma once
#include <fstream>
#include <string>

#include "Employee.h"
#include "Result.h"

using namespace std;

class OutputManager {
public:
    OutputManager(const string& outputFileName)
        : outputFileName_(outputFileName) {
        outputFileStream_(outputFileName_);
    }

    void printResult(ResultCount result) {
        outputFile << result.toString() << endl;
    }

    void printResult(ResultTop result) {
        outputFile << result.toString() << endl;
    }
    
private:
    ofstream outputFileStream_;
    string outputFileName_;
};
