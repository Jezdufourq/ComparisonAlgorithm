#include  "headerFile.h"

vector<vector<int>> generateArray(TEST_TYPE type)
{
    vector<vector<int>> outputArray;
    vector<int> innerArray;
    int Count = 0;
    int random = 0;
    srand(time(0));

    switch (type) {
        case LARGE_DIST:
            for (int i = 0; i < SIMULATIONS; i++)
            {
                for (int j= 0; j < SIMULATIONS; j++)
                {
                    innerArray.push_back(j*LARGE_ARRAY_DIST);
                }
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case NO_DIST:
            for (int i = 0; i < SIMULATIONS; i++)
            {
                for (int j = 0; j < SIMULATIONS; j++)
                {
                    innerArray.push_back(ZERO_ELEMENTS);
                }
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case ONE_DIST:
            for (int i = 0; i < SIMULATIONS; i++)
            {
                for (int j = 1; j <= 1; j++)
                {
                    innerArray.push_back(j);
                }
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case LARGE_INPUT:
            for (int i = 0; i < SIMULATIONS; i++)
            {
                for (int j = 1; j < LARGE_ARRAY_DIST; j++)
                {
                    innerArray.push_back(j);
                }
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case ZERO_INPUT:
            for (int i = 0; i < SIMULATIONS; i++)
            {
                outputArray.push_back(innerArray);
            }
            break;
        case EVEN_INPUT:
            for (int i = 0; i < SIMULATIONS; i++)
            {
                for (int j = 1; j < (i*2)+1; j++)
                {
                    innerArray.push_back(j);
                }
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case ODD_INPUT:
            for (int i = 0; i < SIMULATIONS; i++)
            {
                for (int j = 1; j < (i*2)+2; j++)
                {
                    innerArray.push_back(j);
                }
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