#pragma once
#ifndef ASSIGNMENT1_HEADERFILE_H
#define ASSIGNMENT1_HEADERFILE_H

/********************************************
 *        HEADER FILES DECLERATION          *
 * ******************************************/
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <random>
#include <ctime>
#include <iterator>
#include <chrono>
#include <iomanip>
#include <tuple>

using namespace std;
using namespace std::chrono;


/********************************************
 *        PREPROCESSOR DECLERATION          *
 * ******************************************/
#define LARGE_ARRAY_DIST (INT_MAX) // Defining the value for the large array generator
#define LARGE_ARRAY_SIMS (1) // Defining the value for the large array number of sims
// These ARRAY_* are for all ARRAY'S which are used to test the operations and also the execution time of the algorithm
#define ARRAY_STEP_SIZE (501) // Defining the step size for the random array
#define ARRAY_NUM_SIMS (20) // Defining the number of same length arrays for the random implementation
#define RANDOM_RANGE (100000) // Range of the random variable
#define SIMULATIONS (13) // How many simulations that the program will run
#define ZERO_ELEMENTS (10) // The number for each element in the zero elements functional test


enum TEST_TYPE{
    EVEN_INPUT = 0,
    ODD_INPUT = 1,
    PAIR_ELEM = 2,
    SINGLE_ELEM = 3,
    REPEAT_ELEM = 4,
    LARGE_ORDERED = 5,
    LARGE_REVERSE_ORDERED = 6,
    LARGE_UNORDERED = 7,
    NEG_UNORDERED = 8,
    MIX_UNORDERED = 9,
    NO_DIST = 10,
    LARGE_DIST = 11,
    RANDOM = 12,
    REVERSED = 13,
    SORTED = 14,
};

enum PROGRAM_TYPE{
    FUNCTIONALITY = 0,
    OPERATIONS = 1,
    TIMING = 2,
};

extern PROGRAM_TYPE programType;
extern TEST_TYPE testType;
/********************************************
 *          FUNCTION DECLERATION            *
 * ******************************************/
// generateData.cpp
vector<vector<int>> generateArray(TEST_TYPE type);
// testInterface.cpp
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
// MinDistance.cpp
int MinDistance(vector<int> &A);
int MinDistanceTiming(vector<int> &A);
// MinDistance2.cpp
int MinDistance2(vector<int> &A);
int MinDistance2Timing(vector<int> &A);
// runTests.cpp
void runFuncTest();



#endif //ASSIGNMENT1_HEADERFILE_H


