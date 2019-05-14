#pragma once
#ifndef ASSIGNMENT1_TESTINTERFACE_H
#define ASSIGNMENT1_TESTINTERFACE_H

class testInterface {
private:
    vector<vector<int>> inputVector;
    vector<int> inputArrayLength;
    vector<int> algorithm1Vector;
    vector<int> algorithm2Vector;
    vector<int> algorithm1NumOpsVector;
    vector<int> algorithm2NumOpsVector;
    vector<double> algorithm1ExecTimeVector;
    vector<double> algorithm2ExecTimeVector;
    vector<int> testSolutions;
    string inputStr, outputStr;
    PROGRAM_TYPE programType;
    TEST_TYPE testType;
    ofstream inputFile, outputFile;

public:
    void createInputFile();
    void populateInputFile();
    void closeInputFile();
    void createOutputFile();
    void populateOutputFile();
    void closeOutputFile();
    void printConsoleInput(TEST_TYPE test);
    void printConsoleFunc();
    void printConsoleOp();
    void printConsoleTime();
    void clearValues();
    // Setters
    void setInputVector(const vector<vector<int>> &inputVector);
    void setAlgorithm2Vector(const vector<int> &algorithm2Vector);
    void setAlgorithm1ExecTimeVector(const vector<double> &algorithm1ExecTimeVector);
    void setAlgorithm2ExecTimeVector(const vector<double> &algorithm2ExecTimeVector);
    void setInputArrayLength(const vector<int> &inputArrayLength);
    void setProgramType(PROGRAM_TYPE programType);
    void setTestType(TEST_TYPE testType);
    void setAlgorithm1Vector(const vector<int> &algorithm1Vector);
    void setAlgorithm1NumOpsVector(const vector<int> &algorithm1NumOpsVector);
    void setAlgorithm2NumOpsVector(const vector<int> &algorithm2NumOpsVector);

    void setTestSolutions(const vector<int> &testSolutions);
};


#endif //ASSIGNMENT1_TESTINTERFACE_H
