#include "headerFile.h"

void runFuncTest()
{
    vector<vector<int>> inputVector;
    vector<int> algo1Distance ;
    vector<int> algo2Distance;
    vector<int> arrayLength;

    auto funcObj = new testInterface();
    funcObj->setProgramType(PROGRAM_TYPE::FUNCTIONALITY);
    funcObj->createInputFile();
    funcObj->createOutputFile();

    for (int i = TEST_TYPE::LARGE_DIST; i <= TEST_TYPE::ODD_INPUT; i++)
    {
        // TODO: Include the generateArray function which will be in the testgeneratedata file
        inputVector = generateArray((TEST_TYPE)i);
        // TODO: Function below is not correct
        for (int j = 0; j < inputVector.size(); j++)
        {
            arrayLength.push_back(inputVector[j].size());
        }

        funcObj->setInputArrayLength(arrayLength);
        funcObj->setInputVector(inputVector); // Saving the input vector too the class
        funcObj->setTestType((TEST_TYPE )i);
        for (auto &col : inputVector) // For the length of the input vector, run the test
        {
            // Running the tests, storing the results in a vector to compare
            algo1Distance.push_back(MinDistance(col));
            algo2Distance.push_back(MinDistance2(col));
        }
        funcObj->setAlgorithm1Vector(algo1Distance);
        funcObj->setAlgorithm2Vector(algo2Distance);
        // TODO: Print to the console the results
        // Populating the input vector
        funcObj->populateInputFile();
        // Populating the output vector
        funcObj->populateOutputFile();
        // Printing the results to the console
        funcObj->printConsoleFunc();
        // TODO: Clear everything in the object besides the input and output file streaming
        funcObj->clearValues();

        inputVector.clear();
        algo1Distance.clear();
        algo2Distance.clear();
        arrayLength.clear();
    }
    // Saving the input and output files
    funcObj->closeInputFile();
    funcObj->closeOutputFile();
}

void runTimeTest()
{
    vector<vector<int>> inputVector;
    vector<double> algo1ExecTime;
    vector<double> algo2ExecTime;
    vector<int> algo1Distance;
    vector<int> algo2Distance;
    vector<int> arrayLength;

    auto timeObj = new testInterface;
    timeObj->setProgramType(PROGRAM_TYPE::TIMING);
    timeObj->createInputFile();
    timeObj->createOutputFile();

    for (int i = TEST_TYPE::RANDOM; i <= TEST_TYPE::SORTED; i++)
    {
        // TODO: Include the generateArray function which will be in the testgeneratedata file
        inputVector = generateArray((TEST_TYPE)i);
        for (int j = 0; j < inputVector.size(); j++)
        {
            arrayLength.push_back(inputVector[j].size());
        }
        // Printing the input vector to the console
        timeObj->printConsoleInput((TEST_TYPE)i);

        timeObj->setInputArrayLength(arrayLength);
        timeObj->setInputVector(inputVector); // Saving the input vector too the class
        timeObj->setTestType((TEST_TYPE )i);
        for (auto &col : inputVector) // For the length of the input vector, run the test
        {
            // Running the tests, storing the results in a vector to compare
            high_resolution_clock::time_point a1t1 = high_resolution_clock::now();
            int algo1 = MinDistanceTiming(col);
            high_resolution_clock::time_point a1t2 = high_resolution_clock::now();
            auto algo1TimeOutput = std::chrono::duration_cast<std::chrono::nanoseconds>(a1t2-a1t1);

            algo1ExecTime.push_back(algo1TimeOutput.count());
            algo1Distance.push_back(algo1);

            high_resolution_clock::time_point a2t1 = high_resolution_clock::now();
            int algo2 = MinDistance2Timing(col);
            high_resolution_clock::time_point a2t2 = high_resolution_clock::now();
            auto algo2TimeOutput = std::chrono::duration_cast<std::chrono::nanoseconds>(a1t2-a1t1);

            algo2ExecTime.push_back(algo2TimeOutput.count());
            algo2Distance.push_back(algo2);
        }
        timeObj->setAlgorithm1Vector(algo1Distance);
        timeObj->setAlgorithm2Vector(algo2Distance);

        timeObj->setAlgorithm1ExecTimeVector(algo1ExecTime);
        timeObj->setAlgorithm2ExecTimeVector(algo2ExecTime);
        // TODO: Print to the console the results
        // Saving and populating the input vector
        timeObj->populateInputFile();

        // Saving and populating the output vector
        timeObj->populateOutputFile();

        // Printing the output results to the console
        timeObj->printConsoleTime();
    }
    timeObj->closeInputFile();
    timeObj->closeOutputFile();

}


void runOpsTest()
{
    vector<vector<int>> inputVector;
    vector<int> inputArrayLength;
    vector<int> algorithm1Vector;
    vector<int> algorithm2Vector;
    vector<int> algorithm1NumOpsVector;
    vector<int> algorithm2NumOpsVector;
    vector<int> arrayLength;

    auto opObj = new testInterface;
    opObj->setProgramType(PROGRAM_TYPE::OPERATIONS);
    opObj->createInputFile();
    opObj->createOutputFile();

    for (int i = TEST_TYPE::RANDOM; i <= TEST_TYPE::SORTED; i++)
    {
        // TODO: Include the generateArray function which will be in the testgeneratedata file
        inputVector = generateArray((TEST_TYPE)i);
        for (int j = 0; j < inputVector.size(); j++)
        {
            arrayLength.push_back(inputVector[i].size());
        }
        opObj->setInputArrayLength(arrayLength);
        opObj->setInputVector(inputVector); // Saving the input vector too the class
        opObj->setTestType((TEST_TYPE )i);
        for (auto &col : inputVector) // For the length of the input vector, run the test
        {
            algorithm1NumOpsVector.push_back(basicOp);
            algorithm2NumOpsVector.push_back(basicOp2);
            // Running the tests, storing the results in a vector to compare
            algorithm1Vector.push_back(MinDistance(col));
            algorithm2Vector.push_back(MinDistance2(col));
        }
        opObj->setAlgorithm1Vector(algorithm1Vector);
        opObj->setAlgorithm2Vector(algorithm2Vector);
        opObj->setAlgorithm1NumOpsVector(algorithm1NumOpsVector);
        opObj->setAlgorithm2NumOpsVector(algorithm2NumOpsVector);
        // TODO: Print to the console the results
        // Saving and populating the input vector
        opObj->populateInputFile();

        // Saving and populating the output vector
        opObj->populateOutputFile();

        // Printing the results to the console
        opObj->printConsoleOp();
    }
    opObj->closeOutputFile();
    opObj->closeInputFile();
}


