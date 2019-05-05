#include "headerFile.h"

void printConsoleInput(vector<vector<int>> const &input, TEST_TYPE test)
{
    setfill('=');
    switch(test)
    {
        case NEGATIVE:
            cout << "==NEGATIVE TEST INPUT==" << endl;
            break;
        case ODD:
            cout << "==ODD TEST INPUT==" << endl;
            break;
        case EVEN:
            cout << "==EVEN TEST INPUT==" << endl;
            break;
        case LARGE:
            cout << "==LARGE TEST INPUT==" << endl;
            break;
        case ONELEN:
            cout <<  "==ONELENGTH TEST INPUT==" << endl;
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
    for (auto &row: input)
    {
        cout << "| " << i << setfill(' ') << setw(12) << "| " << "{";
        for (auto col: row) {
            cout << col << ",";
        }
        i++;
        cout << "}" << endl;
    }
}

void printConsoleFunctionality(vector<int> &actual, vector<int> &algo, vector<int> &arrayLength)
{
    cout << "| TestNumber | ArrayLength | AlgoMedianValue | CalculatedMedianValue | PASS/FAIL |"<< endl;
    cout << "|------------|-------------|-----------------|-----------------------|-----------|"<< endl;

    for (int i = 0; i < actual.size(); i++)
    {
        cout << "| " << i <<setw(12);
        cout << " | " << arrayLength[i] <<setw(13);
        cout << " | " << algo[i]  <<setw(16);
        cout << " | " << actual[i] << setw(24);
        if(algo[i]==actual[i])
        {
            cout << " | " << "PASS" << endl;
        }else if (algo[i]!=actual[i]){
            cout << " | " << "FAIL" << endl;
        }
    }
}

void printConsoleOperations(vector<unsigned long long> &numOps, vector<int> &algo, vector<int> &arrayLength)
{
    cout << "| TestNumber | ArrayLength | AlgoMedianValue | NumberOfOperations |"<< endl;
    cout << "|------------|-------------|-----------------|--------------------|"<< endl;

    for (int i = 0; i < algo.size(); i++)
    {
        cout << "| " << i <<setw(12);
        cout << " | " << arrayLength[i] <<setw(13);
        cout << " | " << algo[i]  <<setw(16);
        cout << " | " << numOps[i] << setw(24) << endl;
    }
}

void printConsoleTiming(vector<double> &execTime, vector<int> &algo, vector<int> &arrayLength)
{
    cout << "| TestNumber | ArrayLength | AlgoMedianValue | ExecutionTime |"<< endl;
    cout << "|------------|-------------|-----------------|---------------|"<< endl;

    for (int i = 0; i < algo.size(); i++)
    {
        cout << "| " << i << setw(12);
        cout << " | " << arrayLength[i] <<setw(11);
        cout << " | " << algo[i]  <<setw(11);
        cout << " | " << execTime[i] << setw(21) << endl;
    }
}




