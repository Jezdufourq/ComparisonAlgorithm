#include "headerFile.h"

unsigned long long basicOp = 0;

// NumOps implementation of the algorithm
int MinDistance(vector<int> &A) {
    // Input: Array of ints
    // Output: Minimum distance between two of its elements
    int size = A.size();
    int dmin = INT_MAX;

    for (int i = 0; i <= (size - 1); i++)
    {
        for(int j = 0; j <= (size - 1); j++)
        {
            if((i != j) && (++basicOp > 0) && (abs(A[i] - A[j]) < dmin))
            {
                dmin = abs(A[i] - A[j]);
            }
        }
    }
    return dmin;
}

// Timing implementation of the algorithm
int MinDistanceTiming(vector<int> &A) {
    // Input: Array of ints
    // Output: Minimum distance between two of its elements
    int size = A.size();
    int dmin = INT_MAX;

    for (int i = 0; i <= (size - 1); i++)
    {
        for(int j = 0; j <= (size - 1); j++)
        {
            if((i != j) && (abs(A[i] - A[j]) < dmin))
            {
                dmin = abs(A[i] - A[j]);
            }
        }
    }
    return dmin;
}









