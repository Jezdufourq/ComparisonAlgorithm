#include "headerFile.h"
#include "testInterface.h"
#include "MinDistance.cpp"
#include "MinDistance2.cpp"
#include "generateData.cpp"
#include "runTests.cpp"
#include "testInterface.cpp"


// Calling the main method with the following arguments
// ./main.out TESTTYPE (As an integer)
int main(int argc, char *argv[]) {
    int userInput;
    cout << "============[! WELCOME TO ALGOCRUNCH !]=============" << endl;
    cout << "Enter the program that you would like to run" << endl;
    cout << "FUNCTIONALITY=0, OPERATIONS=1, TIMING=2" << endl;
    cin >> userInput;
    cout << "This program is executing with the following variables:" << endl;
    cout << "+-- LARGE_ARRAY_VALUE: " << LARGE_ARRAY_DIST << endl;
    cout << "+-- LARGE_ARRAY_SIMS: " << LARGE_ARRAY_SIMS << endl;
    cout << "+-- ARRAY_STEP_SIZE: " << ARRAY_STEP_SIZE << endl;
    cout << "+-- ARRAY_NUM_SIMS: " << ARRAY_NUM_SIMS << endl;
    cout << "+-- RANDOM_RANGE: " << RANDOM_RANGE << endl;
    cout << "+-- SIMULATIONS: " << SIMULATIONS << endl;

    cout << "Initilizing and completing the selected tests: " << endl;

    duration<double> timeTaken;

    auto startTime = chrono::high_resolution_clock::now();
    switch (userInput) {
        case FUNCTIONALITY:
            runFuncTest();
        case OPERATIONS:
            runOpsTest();
        case TIMING:
            runTimeTest();
        default: break;
    }

    auto endTime = chrono::high_resolution_clock::now();
    timeTaken = duration_cast<duration<double>>(endTime - startTime);
    cout << "\n=====The execution time for the program is: " << timeTaken.count() << "=====" << endl;

    return 0;
}

