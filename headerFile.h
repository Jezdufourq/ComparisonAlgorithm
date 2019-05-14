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

//#include "MinDistance.cpp"
//#include "MinDistance2.cpp"
//#include "generateData.cpp"
//#include "runTests.cpp"

/********************************************
 *        PREPROCESSOR DECLERATION          *
 * ******************************************/
#define LARGE_ARRAY_DIST (2000) // Defining the value for the large array generator
#define LARGE_ARRAY_SIMS (1) // Defining the value for the large array number of sims
// These ARRAY_* are for all ARRAY'S which are used to test the operations and also the execution time of the algorithm
#define ARRAY_STEP_SIZE (501) // Defining the step size for the random array
#define ARRAY_NUM_SIMS (250) // Defining the number of same length arrays for the random implementation
#define RANDOM_RANGE (100000) // Range of the random variable
#define SIMULATIONS (10) // How many simulations that the program will run
#define ZERO_ELEMENTS (10) // The number for each element in the zero elements functional test


enum TEST_TYPE{
    ODD_INPUT = 0,
    EVEN_INPUT = 1,
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

// MinDistance.cpp
int MinDistance(vector<int> &A);

// testGenerationData.cpp
vector<int> largeDist();
vector<int> zeroDist();




#endif //ASSIGNMENT1_HEADERFILE_H


