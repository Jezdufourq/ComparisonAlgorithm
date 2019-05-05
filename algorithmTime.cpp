#include "headerFile.h"

int BruteForceMedianTime(vector<int> &A)
{
    // Calculate the half-way index of the array.
    size_t size = A.size(); // Storing the size as size_t (unsigned int)
    int k = (int) ceil(size/ 2.0);

    for (int i = 0; i <= (A.size()-1); i++) {
        int numSmaller = 0; // Number of elements smaller than A[i];
        int numEqual = 0; // Number of elements equal to A[i];

        for (int j = 0; j <= (A.size()-1); j++) {
            // Calculate number of array items that are smaller, and equal.
            if (A[j] < A[i]) {
                numSmaller+=1;

            } else {
                if (A[j] == A[i]) {
                    numEqual+=1;
                }
            }
        }
        if ((numSmaller < k) && (k <= (numSmaller + numEqual))) {
            return A[i];
        }
    }
    return 0;
}


