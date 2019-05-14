#include "testInterface.h"

void testInterface::createInputFile()
{
    switch(testInterface::programType)
    {
        case FUNCTIONALITY:
            testInterface::inputStr = "FUNCTIONALITY TEST\n";
            break;
        case TIMING:
            testInterface::inputStr = "TIMING TEST\n";
            break;
        case OPERATIONS:
            testInterface::inputStr = "OPERATION TEST\n";
            break;
        default:break;
    }
}

void testInterface::populateInputFile()
{
    testInterface::inputStr.append("TEST: " + to_string(testType) + "\n");
    int i = 0;
    for (auto &row : testInterface::inputVector)
    {
        testInterface::inputStr.append(to_string(i) + ",");
        for (auto &col : row)
        {
            testInterface::inputStr.append(to_string(col) + ",");
        }
        testInterface::inputStr.append(",\n");
        i++;
    }
}

void testInterface::closeInputFile()
{
    switch(testInterface::programType) {
        case FUNCTIONALITY:
            testInterface::inputFile.open("FUNC_INPUT.csv");
            break;
        case TIMING:
            testInterface::inputFile.open("TIME_INPUT.csv");
            break;
        case OPERATIONS:
            testInterface::inputFile.open("OP_INPUT.csv");
            break;
        default:
            break;
    }
    testInterface::inputFile << testInterface::inputStr;
    testInterface::inputFile.close();
}

void testInterface::createOutputFile()
{
    switch(testInterface::programType)
    {
        case FUNCTIONALITY:
            testInterface::outputStr = "FUNCTIONALITY TEST\n";
            break;
        case TIMING:
            testInterface::outputStr = "TIMING TEST\n";
            break;
        case OPERATIONS:
            testInterface::outputStr = "OPERATION TEST\n";
            break;
        default:break;
    }
}

void testInterface::populateOutputFile()
{
    testInterface::outputStr.append("TEST: " + to_string(testType) + "\n");
    switch(testInterface::programType)
    {
        case FUNCTIONALITY:
            testInterface::outputStr.append("TestNumber, InputArrayLength, Algo1Distance, Algo2Distance, PASS/FAIL\n");
            for(int i = 0; i < testInterface::algorithm1Vector.size(); i++)
            {
                testInterface::outputStr.append(to_string(i) + ",");
                testInterface::outputStr.append(to_string(testInterface::inputArrayLength[i]) + ",");
                testInterface::outputStr.append(to_string(testInterface::algorithm1Vector[i]) + ",");
                testInterface::outputStr.append(to_string(testInterface::algorithm2Vector[i]) + ",\n");

                // TODO: Need to include the comparison to check if the actual distance is the expected distance
            }
            break;
        case TIMING:
            testInterface::inputFile << "TestNumber, InputArrayLength, Algo1Distance, Algo2Distance, Algo1ExecTime, Algo2ExecTime" << endl;
            for(int i = 0; i < testInterface::algorithm1Vector.size(); i++)
            {
                testInterface::outputStr.append(to_string(i) + ",");
                testInterface::outputStr.append(to_string(testInterface::inputArrayLength[i]) + ",");
                testInterface::outputStr.append(to_string(testInterface::algorithm1Vector[i]) + ",");
                testInterface::outputStr.append(to_string(testInterface::algorithm2Vector[i]) + ",");
                testInterface::outputStr.append(to_string(testInterface::algorithm1ExecTimeVector[i]) + ",");
                testInterface::outputStr.append(to_string(testInterface::algorithm2ExecTimeVector[i]) + ",\n");
            }
            break;
        case OPERATIONS:
            testInterface::inputFile << "TestNumber, InputArrayLength, Algo1Distance, Algo2Distance, Algo1NumOps, Algo1NumOps" << endl;
            for(int i = 0; i < testInterface::algorithm1Vector.size(); i++)
            {
                testInterface::outputStr.append(to_string(i) + ",");
                testInterface::outputStr.append(to_string(testInterface::inputArrayLength[i]) + ",");
                testInterface::outputStr.append(to_string(testInterface::algorithm1Vector[i]) + ",");
                testInterface::outputStr.append(to_string(testInterface::algorithm2Vector[i]) + ",");
                testInterface::outputStr.append(to_string(testInterface::algorithm1NumOpsVector[i]) + ",");
                testInterface::outputStr.append(to_string(testInterface::algorithm2NumOpsVector[i]) + ",\n");
            }
            break;
        default:break;
    }
}

void testInterface::closeOutputFile()
{
    switch(testInterface::programType) {
        case FUNCTIONALITY:
            testInterface::outputFile.open("FUNC_OUTPUT.csv");
            break;
        case TIMING:
            testInterface::outputFile.open("TIME_OUTPUT.csv");
            break;
        case OPERATIONS:
            testInterface::outputFile.open("OP_OUTPUT.csv");
            break;
        default:
            break;
    }
    testInterface::outputFile << testInterface::outputStr;
    testInterface::outputFile.close();
}

void testInterface::printConsoleInput(TEST_TYPE test)
{
    setfill('=');
    switch(test)
    {
        case LARGE_DIST:
            cout << "==LARGE DISTANCE TEST INPUT==" << endl;
            break;
        case NO_DIST:
            cout << "==NO DISTANCE TEST INPUT==" << endl;
            break;
        case ONE_DIST:
            cout << "==ONE DISTANCE TEST INPUT==" << endl;
            break;
        case LARGE_INPUT:
            cout << "==LARGE TEST INPUT==" << endl;
            break;
        case ZERO_INPUT:
            cout <<  "==ZERO TEST INPUT==" << endl;
            break;
        case EVEN_INPUT:
            cout <<  "==EVEN TEST INPUT==" << endl;
            break;
        case ODD_INPUT:
            cout <<  "==ODD TEST INPUT==" << endl;
            break;
        case RANDOM:
            cout << "==RANDOM TEST INPUT==" << endl;
            break;
        case REVERSED:
            cout << "==REVERSED TEST INPUT==" << endl;
            break;
        case SORTED:
            cout << "==SORTED TEST INPUT==" << endl;
            break;
        default:break;
    }
    cout << setfill('=')<< endl;

    //TODO: Fix up the comma issue at the end of the input array when printing to the console.
    int i = 0;
    cout << "| TestNumber | InputArray                                                   |" << endl;
    cout << "|------------|--------------------------------------------------------------|" << endl;
    for (auto &row: testInterface::inputVector)
    {
        cout << "| " << i << setfill(' ') << setw(12) << "| " << "{";
        for (auto col: row) {
            cout << col << ",";
        }
        i++;
        cout << "}" << endl;
    }
}

void testInterface::printConsoleFunc()
{
    cout << "| TestNumber | ArrayLength | Algo1Distance | Algo2Distance | PASS/FAIL |"<< endl;
    cout << "|------------|-------------|---------------|---------------|-----------|"<< endl;

    for (int i = 0; i < testInterface::algorithm1Vector.size(); i++)
    {
        cout << "| " << i <<setw(12);
        cout << " | " << testInterface::inputArrayLength[i] <<setw(13);
        cout << " | " << testInterface::algorithm1Vector[i]  <<setw(16);
        cout << " | " << testInterface::algorithm2Vector[i]  <<setw(16) << endl;
        // TODO: Need to implement the pass and fail functionality
//            if(algo[i]==actual[i])
//            {
//                cout << " | " << "PASS" << endl;
//            }else if (algo[i]!=actual[i]){
//                cout << " | " << "FAIL" << endl;
//            }
    }
}

void testInterface::printConsoleOp()
{
    cout << "| TestNumber | ArrayLength | Algo1NumOps | Algo2NumOps |"<< endl;
    cout << "|------------|-------------|-------------|-------------|"<< endl;

    for (int i = 0; i < testInterface::algorithm1Vector.size(); i++)
    {
        cout << "| " << i <<setw(12);
        cout << " | " << testInterface::inputArrayLength[i] <<setw(13);
        cout << " | " << testInterface::algorithm1NumOpsVector[i]  <<setw(16);
        cout << " | " << testInterface::algorithm2NumOpsVector[i] << setw(24) << endl;
    }
}

void testInterface::printConsoleTime()
{
    cout << "| TestNumber | ArrayLength | Algo1ExecTime | Algo2ExecTime |"<< endl;
    cout << "|------------|-------------|---------------|---------------|"<< endl;

    for (int i = 0; i < testInterface::algorithm1Vector.size(); i++)
    {
        cout << "| " << i << setw(12);
        cout << " | " << testInterface::inputArrayLength[i] <<setw(11);
        cout << " | " << testInterface::algorithm1ExecTimeVector[i]  <<setw(11);
        cout << " | " << testInterface::algorithm2ExecTimeVector[i] << setw(21) << endl;
    }
}

void testInterface::clearValues()
{
    testInterface::inputVector.clear();
    testInterface::inputArrayLength.clear();
    testInterface::algorithm1Vector.clear();
    testInterface::algorithm2Vector.clear();
    testInterface::algorithm1NumOpsVector.clear();
    testInterface::algorithm2NumOpsVector.clear();
    testInterface::algorithm1ExecTimeVector.clear();
    testInterface::algorithm2ExecTimeVector.clear();
}

// Setters
void testInterface::setInputVector(const vector<vector<int>> &inputVector) {testInterface::inputVector = inputVector;}
void testInterface::setAlgorithm2Vector(const vector<int> &algorithm2Vector) {testInterface::algorithm2Vector = algorithm2Vector;}
void testInterface::setAlgorithm1ExecTimeVector(const vector<double> &algorithm1ExecTimeVector) {
    testInterface::algorithm1ExecTimeVector = algorithm1ExecTimeVector;
}
void testInterface::setAlgorithm2ExecTimeVector(const vector<double> &algorithm2ExecTimeVector) {
    testInterface::algorithm2ExecTimeVector = algorithm2ExecTimeVector;
}
void testInterface::setInputArrayLength(const vector<int> &inputArrayLength) {testInterface::inputArrayLength = inputArrayLength;}
void testInterface::setProgramType(PROGRAM_TYPE programType) {testInterface::programType = programType;}
void testInterface::setTestType(TEST_TYPE testType) {testInterface::testType = testType;}
void testInterface::setAlgorithm1Vector(const vector<int> &algorithm1Vector) {testInterface::algorithm1Vector = algorithm1Vector;}
void testInterface::setAlgorithm1NumOpsVector(const vector<int> &algorithm1NumOpsVector) {
    testInterface::algorithm1NumOpsVector = algorithm1NumOpsVector;
}
void testInterface::setAlgorithm2NumOpsVector(const vector<int> &algorithm2NumOpsVector) {
    testInterface::algorithm2NumOpsVector = algorithm2NumOpsVector;
}

