//
// Created by Jez Dufourq on 2019-04-06.
//
#include <vector>

vector<vector<vector<int>>>randArray(int numSims, int numArray);
vector<vector<int>>medianArray();

// TODO: Not really an efficient way of allocating a 3D vector
vector<vector<vector<int>>>randArray(int numSims, int numArray)
{
    vector<vector<vector<int>>> randomVector;
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    srand(ms.count());

    int count = 0;
    for(int i = 1; i < (numArray + 1); i++) {
        vector<vector<int>> temp;
        count++;
        for (int j = 0; j < numSims; j++) {
            vector<int> temp1;
            for (int k = 0; k < count; k++) {
                int random = rand() & 1000;
                temp1.push_back(random);
            }
            temp.push_back(temp1);
        }
        randomVector.push_back(temp);
    }
    return randomVector;
}

vector<vector<int>> randArrayNew(int numArray, int stepSize, int numSims)
{
    // vector<vector<vector<int>>>
    //  |       |       |
    //  |       |       +-This is the inner loop and stores all of the random ints
    //  |       +-This is the numSims (as in the number of the same length array in a simulation)
    //  +-This is the numArray as in the simulation number for a set of the same length arrays

    // To make a random loop in which we can specify the step size
    //
    vector<vector<int> > randomVector;

    int count = 0;
    int random;
//    int index = 0;
    for (int i = 1; i < (numArray + 1); i++) {
        count += stepSize;
        for(int j = 0; j < numSims; j++) {
            vector<int> temp;
            for (int k = 0; k < count; k++) {
                random = rand() % 100;
                temp.push_back(random);
            }
            randomVector.push_back(temp);
        }
    }
    return randomVector;
}


vector<vector<int>>oddArray()
{
    vector<vector<int>> oddLength;
    oddLength = {{1,2,3,4,5,6,7},
                {0,3,2,1,6},
                {87,100,-20}
    };
    return oddLength;
}

vector<vector<int>>evenArray()
{
    vector<vector<int>> evenLength;
    evenLength = {{1,2,3,4,5,6,7,8},
                 {0,3,2,1,2,4},
                 {87,100,-20,-185},
    };
    return evenLength;
}

vector<vector<int>>onelenArray()
{
    vector<vector<int>> oneLength;
    oneLength = {{1},
                  {1000},
                  {-300}
    };
    return oneLength;
}

vector<vector<int>>medianArray()
{
    vector<vector<int>> medianArray = {{1,2,3,4,5,6,7,8,9,10},
                                       {0,0,0,0,0,0,0,0,0,0},
                                       {1,1,1,1,1,1,1,1,1,1},
                                       {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                       {-5,-4,-3,-2,-1,0,1,2,3,4,5},
    };
    return medianArray;
}

vector<int>largeArray(int arrayNum)
{
    vector<int> randomVector;
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    srand(ms.count());

    for (int k = 0; k < arrayNum; k++) {
        int random = rand() & 1000;
        randomVector.push_back(random);
    }
    return randomVector;
}