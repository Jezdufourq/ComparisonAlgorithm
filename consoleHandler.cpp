//
// Created by Jez Dufourq on 2019-04-06.
//
#include <iomanip>
using namespace std;

void print3D(vector<vector<vector<int>>> const &input);
void print2D(vector<vector<int>> const &input);
void print(vector<int> const &input);
void printOutput(vector<tuple<long,long,long>> const &algoOp, vector<tuple<long,long,float>>const &algoTime);
void printResults(vector<tuple<long,long, long>> results, long solutions, vector<bool> outcome);

void print3D(vector<vector<vector<int>>> const &input)
{
    // Auto in this case is used to cut down on writing vector each time
    // Auto is implemented when the program is built
    // It sets the input value automatically to a vector value
    // TODO: Need to research this.
    int i = 0;
    cout << "| TestNumber | InputArray                                                   |" << endl;
    cout << "|------------|--------------------------------------------------------------|" << endl;

    for(auto &row: input) {
        for (auto &col: row) {
            cout << "| " << i << setfill(' ') << setw(12) << "| " << "{";
            for (auto &depth: col) {
                cout << depth << ",";
            }
            i++;
            cout << "}" << endl;
        }
    }
}

void print2D(vector<vector<int>> const &input)
{
    // Auto in this case is used to cut down on writing vector each time
    // Auto is implemented when the program is built
    // It sets the input value automatically to a vector value
    // TODO: Need to research this.
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

void print(vector<int> const &input)
{
    // Auto in this case is used to cut down on writing vector each time
    // Auto is implemented when the program is built
    // It sets the input value automatically to a vector value
    // TODO: Need to research this.
    int i = 0;
    cout << "| TestNumber | InputArray                                                   |" << endl;
    cout << "|------------|--------------------------------------------------------------|" << endl;

    cout << "| " << i << setfill(' ') << setw(12) << "| " << "{";
    for (auto &row: input)
    {
        cout << row << ",";
    }
    cout << "}" << endl;
}

void printOutput(vector<tuple<long,long,long>> const &algoOp, vector<tuple<long,long,float>>const &algoTime, int choice)
{
    // choice = 1(both), choice = 2(execution), choice = 3(operation)
    if(choice == 1){
        cout << "| TestNumber | ArrayLength | MedianValue | NumberOperations | ExecutionTime |"<< endl;
        cout << "|------------|-------------|-------------|------------------|---------------|"<< endl;
    }else if(choice == 2){
        cout << "| TestNumber | ArrayLength | MedianValue | ExecutionTime |"<< endl;
        cout << "|------------|-------------|-------------|---------------|"<< endl;
    }else if(choice == 3){
        cout << "| TestNumber | ArrayLength | MedianValue | NumberOperations |"<< endl;
        cout << "|------------|-------------|-------------|-------------------|"<< endl;
    }
    for (int i = 0; i < algoOp.size(); i++)
    {
        cout << "| " << i << setfill(' ') <<setw(11) << "|";
        cout << get<0>(algoOp[i]) << setfill(' ') << setw(13) << "|";
        cout << get<1>(algoOp[i]) << setfill(' ') << setw(13) << "|";
        if(choice == 1){
            cout << get<2>(algoOp[i]) << setfill(' ') << setw(17) << "|";
            cout << get<2>(algoTime[i]) << endl;
        }else if (choice == 2){
            cout << get<2>(algoTime[i]) << endl;
        }else if(choice  == 3){
            cout << get<2>(algoOp[i]) << endl;
        }
    }

}

void printResults(vector<tuple<long,long, long>> results, long *solutions, vector<string> outcome)
{
    bool failCond = false;
    cout << "| TestNumber | MedianOutput | ExpectedValue | TestOutcome |" << endl;
    cout << "|------------|--------------|---------------|-------------|" << endl;
    for (int i = 0; i < results.size(); i++)
    {
        cout << "| " << i << setw(12);
        cout << " | " << get<1>(results[i]) << setw(14);
        cout << " | " << solutions[i] << setw(15);
        cout << " | " << outcome[i] << endl;
        if(outcome[i] == "FAILED")
        {
            failCond = true;
        }
    }
    cout << "\n*" << setfill('*') << setw(60) << "*" << endl;
    cout << "*" << setw(40) << " [OVERALL TEST RESULT] " << setw(20) << "*" << endl;
    if(failCond)
    {
        cout << "*" << setw(40) << " [TEST = FAILED] " << setw(20) << "*" << endl;
    }else{
        cout << "*" << setw(40) << " [TEST = PASSED] " << setw(20) << "*" << endl;
     }
    cout << "*" << setw(60) << "*" << endl;
}


