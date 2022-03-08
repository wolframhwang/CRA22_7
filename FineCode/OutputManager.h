#pragma once
#include <fstream>
#include <string>

#include "Employee.h"
#include "Result.h"

using namespace std;

class OutputManager {
public:
    OutputManager(const string& outputFileName)
        : outputFileName_(outputFileName), outputFileStream_(outputFileName) {
    }

    void printResult(ResultPtr result) {
        auto output = result->toString();
        if (output != "") {
            outputFileStream_ << output;
        }
    }

private:
    ofstream outputFileStream_;
    string outputFileName_;
};
