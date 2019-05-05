#include "headerFile.h"

unsigned long long numOp = 0;

int BruteForceMedian(vector<int> &A)
{
    size_t size = A.size(); // Calculating the size fo the input array
    int k = (int) ceil(A.size() / 2.0); // Calculate the half-way index of the array.

    for (int i = 0; i <= (size-1); i++) {
        int numSmaller = 0; // Number of elements smaller than A[i];
        int numEqual = 0; // Number of elements equal to A[i];

        for (int j = 0; j <= (size-1); j++) {
            // Calculate number of array items that are smaller, and equal.
            if (A[j] < A[i]) {
                numSmaller+=1;
                numOp+=1;
            } else {
                if (A[j] == A[i]) {
                    numEqual+=1;
                    numOp+=1;
                }
            }
        }
        if ((numSmaller < k) && (k <= (numSmaller + numEqual))) {
            return A[i];
        }
    }
    return 0;
}
