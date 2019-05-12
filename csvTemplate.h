//
// Created by Jez Dufourq on 2019-05-12.
//

#ifndef ASSIGNMENT1_CSVTEMPLATE_H
#define ASSIGNMENT1_CSVTEMPLATE_H


class csvTemplate {
private:
    vector<vector<int>> inputVector;
    vector<int> inputArrayLength;
    vector<int> algorithm1Vector;
    vector<int> algorithm2Vector;
    vector<int> algorithm1NumOpsVector;
    vector<int> algorithm2NumOpsVector;
    vector<double> algorithm1ExecTimeVector;
    vector<double> algorithm2ExecTimeVector;
    PROGRAM_TYPE programType;
    TEST_TYPE testType;
    ofstream inputFile, outputFile;

public:

    void createInputFile()
    {
        switch(csvTemplate::programType)
        {
            case FUNCTIONALITY:
                csvTemplate::inputFile.open("FUNCTIONALITY_INPUT.csv");
                csvTemplate::inputFile << "FUNCTIONALITY TEST" << endl;
                break;
            case TIMING:
                csvTemplate::inputFile.open("TIMING_INPUT.csv");
                csvTemplate::inputFile << "TIMING TEST" << endl;
                break;
            case OPERATIONS:
                csvTemplate::inputFile.open("OPERATIONS_INPUT.csv");
                csvTemplate::inputFile << "OPERATIONS TEST" << endl;
                break;
            default:break;
        }
    }

    void populateInputFile()
    {
        csvTemplate::inputFile << "TEST: " << testType << endl;
        csvTemplate::inputFile << "TestNumber, InputArray" << endl;
        int i = 0;
        for (auto &row : csvTemplate::inputVector)
        {
            csvTemplate::inputFile << i << ",";
            for (auto &col : row)
            {
                csvTemplate::inputFile << col << ",";
            }
            csvTemplate::inputFile << "," << endl;
            i++;
        }
    }

    void closeInputFile()
    {
        csvTemplate::inputFile.close();
    }

    void createOutputFile()
    {
        switch(csvTemplate::programType)
        {
            case FUNCTIONALITY:
                csvTemplate::inputFile.open("FUNCTIONALITY_OUTPUT.csv");
                break;
            case TIMING:
                csvTemplate::inputFile.open("TIMING_OUTPUT.csv");
                break;
            case OPERATIONS:
                csvTemplate::inputFile.open("OPERATIONS_OUTPUT.csv");
                break;
            default:break;
        }
    }

    void populateOutputFile()
    {
        csvTemplate::inputFile << "TEST: " << testType << endl;
        switch(csvTemplate::programType)
        {
            case FUNCTIONALITY:
                csvTemplate::inputFile << "TestNumber, InputArrayLength, Algo1Distance, Algo2Distance, PASS/FAIL" << endl;
                for(int i = 0; i < csvTemplate::algorithm1Vector.size(); i++)
                {
                    csvTemplate::outputFile << i << ",";
                    csvTemplate::outputFile << csvTemplate::inputArrayLength[i] << ",";
                    csvTemplate::outputFile << csvTemplate::algorithm1Vector[i] << ",";
                    csvTemplate::outputFile << csvTemplate::algorithm2Vector[i] << ",";
                    // TODO: Need to include the comparison to check if the actual distance is the expected distance
                }
                break;
            case TIMING:
                csvTemplate::inputFile << "TestNumber, InputArrayLength, Algo1Distance, Algo2Distance, Algo1ExecTime, Algo2ExecTime" << endl;
                for(int i = 0; i < csvTemplate::algorithm1Vector.size(); i++)
                {
                    csvTemplate::outputFile << i << ",";
                    csvTemplate::outputFile << csvTemplate::inputArrayLength[i] << ",";
                    csvTemplate::outputFile << csvTemplate::algorithm1Vector[i] << ",";
                    csvTemplate::outputFile << csvTemplate::algorithm2Vector[i] << ",";
                    csvTemplate::outputFile << csvTemplate::algorithm1ExecTimeVector[i] << ",";
                    csvTemplate::outputFile << csvTemplate::algorithm2ExecTimeVector[i] << endl;
                }
                break;
            case OPERATIONS:
                csvTemplate::inputFile << "TestNumber, InputArrayLength, Algo1Distance, Algo2Distance, Algo1NumOps, Algo1NumOps" << endl;
                for(int i = 0; i < csvTemplate::algorithm1Vector.size(); i++)
                {
                    csvTemplate::outputFile << i << ",";
                    csvTemplate::outputFile << csvTemplate::inputArrayLength[i] << ",";
                    csvTemplate::outputFile << csvTemplate::algorithm1Vector[i] << ",";
                    csvTemplate::outputFile << csvTemplate::algorithm2Vector[i] << ",";
                    csvTemplate::outputFile << csvTemplate::algorithm1NumOpsVector[i] << ",";
                    csvTemplate::outputFile << csvTemplate::algorithm2NumOpsVector[i] << endl;
                }
                break;
            default:break;
        }
    }

    void closeOutputFile()
    {
        csvTemplate::outputFile.close();
    }


    // Setters
    void setInputVector(const vector<vector<int>> &inputVector) {csvTemplate::inputVector = inputVector;}
    void setAlgorithm2Vector(const vector<int> &algorithm2Vector) {csvTemplate::algorithm2Vector = algorithm2Vector;}
    void setAlgorithm1ExecTimeVector(const vector<double> &algorithm1ExecTimeVector) {
        csvTemplate::algorithm1ExecTimeVector = algorithm1ExecTimeVector;
    }
    void setAlgorithm2ExecTimeVector(const vector<double> &algorithm2ExecTimeVector) {
        csvTemplate::algorithm2ExecTimeVector = algorithm2ExecTimeVector;
    }
    void setInputArrayLength(const vector<int> &inputArrayLength) {csvTemplate::inputArrayLength = inputArrayLength;}
    void setProgramType(PROGRAM_TYPE programType) {csvTemplate::programType = programType;}
    void setTestType(TEST_TYPE testType) {csvTemplate::testType = testType;}
    void setAlgorithm1Vector(const vector<int> &algorithm1Vector) {csvTemplate::algorithm1Vector = algorithm1Vector;}
    void setAlgorithm1NumOpsVector(const vector<int> &algorithm1NumOpsVector) {
        csvTemplate::algorithm1NumOpsVector = algorithm1NumOpsVector;
    }
    void setAlgorithm2NumOpsVector(const vector<int> &algorithm2NumOpsVector) {
        csvTemplate::algorithm2NumOpsVector = algorithm2NumOpsVector;
    }
    void setInputFile(const ofstream &inputFile) {csvTemplate::inputFile = inputFile;}
    void setOutputFile(const ofstream &outputFile) {csvTemplate::outputFile = outputFile;}
};


#endif //ASSIGNMENT1_CSVTEMPLATE_H
