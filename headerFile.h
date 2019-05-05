#pragma once
#ifndef ASSIGNMENT1_HEADERFILE_H
#define ASSIGNMENT1_HEADERFILE_H
#endif //ASSIGNMENT1_HEADERFILE_H
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

//#include "algorithmOps.cpp"
//#include "generateData.cpp"
//#include "csvGenerator.cpp"
//#include "consoleGenerator.cpp"
//#include "comparisonAlgorithm.cpp"
//#include "algorithmTime.cpp"
//#include "runTests.cpp"

/********************************************
 *        PREPROCESSOR DECLERATION          *
 * ******************************************/
#define LARGE_ARRAY_VALUE (20000) // Defining the value for the large array generator
#define LARGE_ARRAY_SIMS (1)
// These ARRAY_* are for all ARRAY'S which are used to test the operations and also the execution time of the algorithm
#define ARRAY_STEP_SIZE (501) // Defining the step size for the random array
#define ARRAY_NUM_SIMS (250) // Defining the number of same length arrays for the random implementation
#define RANDOM_RANGE (100000) // Range of the random variable
#define SIMULATIONS (10) // How many simulations that the program will run

enum TEST_TYPE{
    NEGATIVE = 0,
    ODD = 1,
    EVEN = 2,
    LARGE = 3,
    ONELEN = 4,
    NOLEN = 5,
    RANDOM = 6,
    REVERSED = 7,
    SORTED = 8,
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

// consoleGenerator.cpp
void printConsoleInput(vector<vector<int>> const &input, TEST_TYPE test);
void printConsoleFunctionality(vector<int> &actual, vector<int> &algo, vector<int> &arrayLength);
void printConsoleOperations(vector<unsigned long long> &numOps, vector<double> &algo, vector<int> &arrayLength);
void printConsoleTiming(vector<double> &execTime, vector<double> &algo, vector<int> &arrayLength);

// runTests.cpp
void runTests(TEST_TYPE test,  PROGRAM_TYPE program);

// generateData.cpp
vector<vector<int>> generateArray(TEST_TYPE type);

// csvGenerator.cpp
void createInputCsv(vector<vector<int>> const &input, TEST_TYPE test);
void createOutputCsvFunc(vector<int> &arrayLen, vector<int> &algoMedian, vector<int> &actualMedian,TEST_TYPE test);
void createOutputCsvOps(vector<int> &arrayLen, vector<int> &algoMedian, vector<unsigned long long> &numOps,TEST_TYPE test);
void createOutputCsvTiming(vector<int> &arrayLen, vector<int> &algoMedian, vector<double> &execTime,TEST_TYPE test);

// algorithmOps.cpp
int BruteForceMedian(vector<int> &A);

// comparisonAlgorithm.cpp
int testMedian(vector<int> &input);

// algorithmTime.cpp
int BruteForceMedianTime(vector<int> &A);






