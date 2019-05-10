//
// Created by Jez Dufourq on 2019-05-09.
//
#include "headerFile.h"
unsigned long long basicOp2 = 0;

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
            if (temp < dmin)
            {
                basicOp2++;
                dmin = temp;
            }
        }
    }
    return dmin;
}
