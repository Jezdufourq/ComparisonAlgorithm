#include "headerFile.h"

void createInputCsv(vector<vector<int>> const &input, TEST_TYPE test)
{
    ofstream outputFile;
    switch(test)
    {
        case NEGATIVE:
            outputFile.open("INPUT_NEGATIVE_TEST.csv");
            break;
        case ODD:
            outputFile.open("INPUT_ODD_TEST.csv");
            break;
        case EVEN:
            outputFile.open("INPUT_EVEN_TEST.csv");
            break;
        case LARGE:
            outputFile.open("INPUT_LARGE_TEST.csv");
            break;
        case ONELEN:
            outputFile.open("INPUT_ONELEN_TEST.csv");
            break;
        case NOLEN:return;
        case RANDOM:
            outputFile.open("INPUT_RAND_TEST.csv");
            break;
        case REVERSED:
            outputFile.open("INPUT_REV_TEST.csv");
            break;
        case SORTED:
            outputFile.open("INPUT_SORTED_TEST.csv");
            break;
        default:break;
    }
    outputFile << "TestNumber, InputArray," << endl;
    int i = 0;
    for (auto &row: input) {
        outputFile << i << ",";
        for (auto &col: row) {
            outputFile << col << ",";
        }
        outputFile << "," << endl;
        i++;
    }
    outputFile.close();
}

void createOutputCsvFunc(vector<int> &arrayLen, vector<int> &algoMedian, vector<int> &actualMedian,TEST_TYPE test)
{
    ofstream outputFile;
    switch(test)
    {
        case NEGATIVE:
            outputFile.open("OUTPUT_NEGATIVE_FUNC_TEST.csv");
            break;
        case ODD:
            outputFile.open("OUTPUT_ODD_FUNC_TEST.csv");
            break;
        case EVEN:
            outputFile.open("OUTPUT_EVEN_FUNC_TEST.csv");
            break;
        case LARGE:
            outputFile.open("OUTPUT_LARGE_FUNC_TEST.csv");
            break;
        case ONELEN:
            outputFile.open("OUTPUT_ONELEN_FUNC_TEST.csv");
            break;
        case NOLEN:
            outputFile.open("OUTPUT_NOLEN_FUNC_TEST.csv");
            break;
        case RANDOM:
            outputFile.open("OUTPUT_RANDOM_FUNC_TEST.csv");
            break;
        case REVERSED:
            outputFile.open("OUTPUT_REVERSED_FUNC_TEST.csv");
            break;
        case SORTED:
            outputFile.open("OUTPUT_SORTED_FUNC_TEST.csv");
            break;
    }
    outputFile << "TestNumber, InputArrayLength, AlgoMedianValue, CalculatedMedianValue, PASS/FAIL" << endl;
    for (int i = 0; i < algoMedian.size(); i++)
    {
        outputFile << i << ",";
        outputFile << arrayLen[i] << ",";
        outputFile << algoMedian[i] << ",";
        outputFile << actualMedian[i] << ",";
        if(algoMedian[i]==actualMedian[i])
        {
            outputFile <<  "PASS" << endl;
        }else if (algoMedian[i]!=actualMedian[i]){
            outputFile << "FAIL" << endl;
        }
    }
    outputFile.close();
}

void createOutputCsvOps(vector<int> &arrayLen, vector<int> &algoMedian, vector<unsigned long long> &numOps,TEST_TYPE test)
{
    ofstream outputFile;
    switch(test)
    {
        case NEGATIVE:return;
        case ODD:return;
        case EVEN:return;
        case LARGE:return;
        case ONELEN:return;
        case NOLEN:return;
        case RANDOM:
            outputFile.open("OUTPUT_RANDOM_OPS_TEST.csv");
            break;
        case REVERSED:
            outputFile.open("OUTPUT_REVERSED_OPS_TEST.csv");
            break;
        case SORTED:
            outputFile.open("OUTPUT_SORTED_OPS_TEST.csv");
            break;
        default:return;
    }
    outputFile << "TestNumber, InputArrayLength, AlgoMedianValue, NumberOfOperations" << endl;
    for (int i = 0; i < algoMedian.size(); i++)
    {
        outputFile << i << ",";
        outputFile << arrayLen[i] << ",";
        outputFile << algoMedian[i] << ",";
        outputFile << numOps[i] << endl;
    }
    outputFile.close();
}

void createOutputCsvTiming(vector<int> &arrayLen, vector<int> &algoMedian, vector<double> &execTime,TEST_TYPE test)
{
    ofstream outputFile;
    switch(test)
    {
        case NEGATIVE:return;
        case ODD:return;
        case EVEN:return;
        case LARGE:return;
        case ONELEN:return;
        case NOLEN:return;
        case RANDOM:
            outputFile.open("OUTPUT_RANDOM_TIME_TEST.csv");
            break;
        case REVERSED:
            outputFile.open("OUTPUT_REVERSED_TIME_TEST.csv");
            break;
        case SORTED:
            outputFile.open("OUTPUT_SORTED_TIME_TEST.csv");
            break;
        default:return;
    }
    outputFile << "TestNumber, InputArrayLength, AlgoMedianValue, ExecutionTime" << endl;
    for (int i = 0; i < algoMedian.size(); i++)
    {
        outputFile << i << ",";
        outputFile << arrayLen[i] << ",";
        outputFile << algoMedian[i] << ",";
        outputFile << execTime[i] << endl;
    }
    outputFile.close();
}

