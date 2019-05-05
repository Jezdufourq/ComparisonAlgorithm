////
//// Created by Jez Dufourq on 2019-04-06.
////
using namespace std;
using namespace std::chrono;

void createCsv3D(string &fileName, vector<vector<vector<int>>> const &input)
{
    ofstream newFile;
    newFile.open(fileName);
    newFile << "TestNumber, InputArray," << endl;

    int i = 0;
    for(auto &row: input) {
        for (auto &col: row) {
            newFile << i << ",";
            for (auto &depth: col) {
                newFile << depth << ",";
            }
            newFile << "," << endl;
            i++;
        }
    }
    newFile.close();
}

void createCsv2D(string &fileName, vector<vector<int>> const &input)
{
    ofstream newFile;
    newFile.open(fileName);
    newFile << "TestNumber, InputArray," << endl;

    int i = 0;
    for (auto &row: input) {
        newFile << i << ",";
        for (auto &col: row) {
            newFile << col << ",";
        }
        newFile << "," << endl;
        i++;
    }
    newFile.close();
}

void createCsv1D(string &fileName, vector<int> const &input)
{
    ofstream newFile;
    newFile.open(fileName);

    for (auto &col: input) {
        newFile << col << ",";
    }
    newFile << "," << endl;
    newFile.close();
}

void createCsvOutput(string &fileName, vector<tuple<long, long, long>> const &algoOp,
                     vector<tuple<long, long, float>> const &algoTime)
{
    ofstream newFile;
    newFile.open(fileName);
    newFile << "TestNumber, ArrayLength, MedianValue, NumberOperations, ExecutionTime"<< endl;
    for (int i = 0; i < algoOp.size(); i++)
    {
        newFile << i << ",";
        newFile << get<0>(algoOp[i]) << ",";
        newFile << get<1>(algoOp[i]) << ",";
        newFile << get<2>(algoOp[i]) << ",";
        newFile << get<2>(algoTime[i]) << "," << endl;
    }
    newFile.close();
}

