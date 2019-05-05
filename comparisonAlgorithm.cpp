
// sourced from - https://stackoverflow.com/questions/2114797/compute-median-of-values-stored-in-vector-c/2114817#2114817
#include "headerFile.h"

int testMedian(vector<int> &input)
{
    vector<int> sortedVect(input); // Storing the sorted vector in the local scope
    sort(sortedVect.begin(), sortedVect.end()); // Sort the vector
    size_t size = sortedVect.size(); // Storing the size of the vector in size_t (basically an unsigned int)
    if(size == 0)
    {
        return 0; // This is the null case when the array is 0;
    }else{
        sort(input.begin(), input.end()); // Sorting the vector
        // Checking condition of an even array
        // If is is an even array, we return the element which is half the array size + 1 divided by two
        // If it is not an even array, we return the element which is indexed as  half of the size of the array
        return size % 2 == 0 ? ceil((input[size / 2.0 - 1] + input[size / 2.0]) / 2.0) : input[size / 2];
    }
}