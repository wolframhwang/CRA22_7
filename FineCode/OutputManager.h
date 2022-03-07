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
    }

    void printResult(ResultCount result) {
        ofstream outputFile(outputFileName_);
        outputFile << result.toString() << endl;
    }

    void printResult(ResultTop result) {
        ofstream outputFile(outputFileName_);
        outputFile << result.toString() << endl;
    }
    
private:
    string outputFileName_;
};
