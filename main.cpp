#include "headerFile.h"
//#include "generateData.cpp"
#include "MinDistance.cpp"
#include "MinDistance2.cpp"
#include "testGenerateData.cpp"
#include "hashTable.cpp"
#include "hashTable.h"

// Calling the main method with the following arguments
// ./main.out TESTTYPE (As an integer)
int main(int argc, char *argv[]) {

    for(auto &col : oneDist())
    {
        cout << col << ", ";
    }
    cout << endl;
    vector<int> test = oneDist();
    int value = MinDistance(test);

    if (value == 1)
    {
        cout << "===PASSED===" << endl;
        cout << "Algo: " << value << endl;
    }
    return 0;
}

