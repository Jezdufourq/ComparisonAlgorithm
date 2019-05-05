#include "headerFile.h"

vector<vector<int>> generateArray(TEST_TYPE type)
{
    vector<vector<int>> outputArray;
    vector<int> innerArray;
    int Count = 0;
    int random = 0;

    srand(time(0));
    switch (type) {
        case NEGATIVE:
            for (int i = 0; i < SIMULATIONS; i++)
            {
                for (int j = 0; j >= -((int) SIMULATIONS); j--)
                {
                    innerArray.push_back(j);
                }
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case ODD:
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
        case EVEN:
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
        case LARGE:
            for (int i = 0; i < LARGE_ARRAY_SIMS; i++)
            {
                for (int j = 1; j < LARGE_ARRAY_VALUE; j++)
                {
                    innerArray.push_back(j);
                }
                outputArray.push_back(innerArray);
                innerArray.clear();
            }
            break;
        case ONELEN:
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
            // TODO: NEED TO INCLUDE NO LENGTH IN HERE SO IT RETURNS 0
        case NOLEN:
            for (int i = 0; i < SIMULATIONS; i++)
            {
                outputArray.push_back(innerArray);
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