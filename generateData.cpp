#include  "headerFile.h"

vector<vector<int>> generateArray(TEST_TYPE type)
{
    vector<vector<int>> outputArray;
    vector<int> innerArray;
    int Count = 0;
    int random = 0;
    srand(time(0));

    switch (type) {
        case EVEN_INPUT:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {1,2,3,4,5,6,7,8,9,10};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case ODD_INPUT:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {1,2,3,4,5,6,7,8,9,10,11};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case PAIR_ELEM:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {10,100};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case SINGLE_ELEM:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {1};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case REPEAT_ELEM:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {1,1,1,2,2,2,3,3,4,4,4,4,5,5,5,6,6,6,7,8,9,10,10};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case LARGE_ORDERED:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case LARGE_REVERSE_ORDERED:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case LARGE_UNORDERED:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {50,62,85,40,3,520,56,52,1,62,2,35,6,56,4,8,7,1,10,56};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case NEG_UNORDERED:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {-5,-9,-6,-1,-2,-40,-5,-20};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case MIX_UNORDERED:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {5,20,-5,26,4,-2,0,1,-4};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case NO_DIST:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {1,1,1,1,1,1,1,1,1,1};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case LARGE_DIST:
            for (int i = 0; i < 1; i++)
            {
                innerArray = {0,2147483647};
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case RANDOM:
            for(int i = 0; i < SIMULATIONS; i++)
            {
                Count+=ARRAY_STEP_SIZE;
                for(int j = 0;j < ARRAY_NUM_SIMS; j++)
                {
                    for (int k = 0; k < Count; k++)
                    {
                        random = rand() % RANDOM_RANGE;
                        innerArray.push_back(random);
                    }
                    outputArray.push_back(innerArray);
                    innerArray.clear();
                }
            }
            break;
        case REVERSED:
            for(int i = 0; i < (SIMULATIONS + 1); i++)
            {
                Count+=ARRAY_STEP_SIZE;
                for(int j = 0;j < ARRAY_NUM_SIMS; j++)
                {
                    for (int k = 0; k < Count; k++)
                    {
                        innerArray.push_back((int) ((Count) - k - 1));
                    }
                    outputArray.push_back(innerArray);
                    innerArray.clear();
                }
            }
            break;
        case SORTED:
            for(int i = 0; i < (SIMULATIONS + 1); i++)
            {
                Count+=ARRAY_STEP_SIZE;
                for(int j = 0;j < ARRAY_NUM_SIMS; j++)
                {
                    for (int k = 0; k < Count; k++)
                    {
                        innerArray.push_back(k);
                    }
                    outputArray.push_back(innerArray);
                    innerArray.clear();
                }
            }
            break;
    }
    return outputArray;
}