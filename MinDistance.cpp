//
// Created by Jez Dufourq on 2019-05-09.
//
#include "headerFile.h"
unsigned long long basicOp = 0;

int MinDistance(vector<int> &A) {
    // Input: Array of ints
    // Output: Minimum distance between two of its elements
    int size = A.size();
    int dmin = INT_MAX;

    for (int i = 0; i <= (size - 1); i++)
    {
        for(int j = 0; j <= (size - 1); j++)
        {
            if((++basicOp > 0) && (i != j) && (abs(A[i] - A[j]) < dmin))
            {
//                basicOp++;
                dmin = abs(A[i] - A[j]);
            }
        }
    }
    return dmin;
}




