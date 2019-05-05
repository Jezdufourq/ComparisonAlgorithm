//
// Created by Jez Dufourq on 2019-04-06.
//
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

tuple<long,long,long> BruteForceMedianOperations(vector<int> &A);

tuple<long,long,long> BruteForceMedianOperations(vector<int> &A)
{
    float n = A.size();
    double k = ceil(n/2.0);
    int basicOp = 0;
    tuple<long,long> outputArray;

    for (int i = 0; i <= (n - 1); i++)
    {
        long numSmaller = 0;
        long numEqual = 0;
        for(int j = 0; j <= (n - 1); j++)
        {
            if (A[j] < A[i])
            {
                basicOp++;
                numSmaller++;
            }
            else
            {
                if(A[j] == A[i])
                {
                    basicOp++;
                    numEqual++;
                }
                basicOp++;
            }
        }
        basicOp++;
        if(numSmaller < k and k <= (numSmaller+numEqual))
        {
            return make_tuple(A.size(), A[i],basicOp);
        }
    }
    return tuple<long, long, long>();
}