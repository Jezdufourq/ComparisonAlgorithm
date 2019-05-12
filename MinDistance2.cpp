//
// Created by Jez Dufourq on 2019-05-09.
//
#include "headerFile.h"
unsigned long long basicOp2 = 0;

// BasicOp implementation of the algorithm
int MinDistance2(vector<int> &A)
{
    // Input: Array A[]
    // Output: Minimum distance d between two of its elements
    int size = A.size();
    int dmin = INT_MAX;
    int temp;

    for (int i = 0; i <= (size - 2); i++)
    {
        for(int j = i + 1; j <= (size - 1); j++)
        {
            temp = abs(A[i] - A[j]);
            if ((++basicOp2 > 0) && (temp < dmin))
            {
                dmin = temp;
            }
        }
    }
    return dmin;
}

// Timing implementation of the algorithm
int MinDistance2Timing(vector<int> &A)
{
    // Input: Array A[]
    // Output: Minimum distance d between two of its elements
    int size = A.size();
    int dmin = INT_MAX;
    int temp;

    for (int i = 0; i <= (size - 2); i++)
    {
        for(int j = i + 1; j <= (size - 1); j++)
        {
            temp = abs(A[i] - A[j]);
            if (temp < dmin)
            {
                dmin = temp;
            }
        }
    }
    return dmin;
}