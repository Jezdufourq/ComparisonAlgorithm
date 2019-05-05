#include "headerFile.h"

void runTests(TEST_TYPE test,  PROGRAM_TYPE program)
{
    // Defining the input and the output vector
    vector<vector<int>> inputVector;
    vector<int> algoMedianVector;
    vector<int> actualMedianVector;
    vector<unsigned long long> numOpsVector;
    vector<double> execTimeVector;
    vector<int> arrayLength;

    // Creating the input vector
    inputVector = generateArray(test);
    createInputCsv(inputVector, test);

    for (int i = 0; i < inputVector.size(); i++)
    {
        arrayLength.push_back(inputVector[i].size());
    }

    // Printing the input vector to the console - Checks to see if the user wants to print to the console
//    if(INPUT_PRINT)
//    {
//        cout << "=========INPUT DATA=========\n" << endl;
//        printConsoleInput(inputVector, test);
//    }

    // Creating the output vector - Running the simulation
    switch(program) {
        case FUNCTIONALITY:
            for (auto &col : inputVector) // For the length of the input vector, run the test
            {
                // Running the tests, storing the results in a vector to compare
                algoMedianVector.push_back(BruteForceMedian(col));
                actualMedianVector.push_back(testMedian(col));
            }
            // Comparing the results and printing to the console
            cout << "========FUNCTIONALITY TESTING RESULTS========" << endl;
            cout << "=====THIS IS THE TEST (" << test << ")=====" << endl;
            printConsoleFunctionality(actualMedianVector, algoMedianVector, arrayLength);
            // Saving the results to a csv file
            createOutputCsvFunc(arrayLength, algoMedianVector, actualMedianVector, test);
            break;
        case OPERATIONS:
            for (auto &col : inputVector) {
                algoMedianVector.push_back(BruteForceMedian(col));
                numOpsVector.push_back(numOp);
            }
            // Comparing the results and printing to the console
            cout << "========OPERATION TESTING RESULTS========" << endl;
            cout << "=====THIS IS THE TEST (" << test << ")=====" << endl;
            printConsoleOperations(numOpsVector, algoMedianVector, arrayLength);
            // Saving the results to a csv file
            createOutputCsvOps(arrayLength, algoMedianVector, numOpsVector, test);
            numOp = 0; // Resetting the number of operations
            break;
        case TIMING:
            for (auto &col : inputVector)
            {

                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                int output = BruteForceMedianTime(col);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1);
                execTimeVector.push_back(nanoseconds.count());
                algoMedianVector.push_back(output);
            }
            cout << "========TIMING TESTING RESULTS========" << endl;
            cout << "=====THIS IS THE TEST (" << test << ")=====" << endl;
            printConsoleTiming(execTimeVector,algoMedianVector,arrayLength);
            // Saving the results to a csv file
            createOutputCsvTiming(arrayLength, algoMedianVector, execTimeVector, test);
            break;
        default:break;
    }
}