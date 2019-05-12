//
// Created by Jez Dufourq on 2019-05-09.
//

// == FUNCTIONAL TESTS ==
// ~ Large distance
// ~ No distance (all of the same elements)
// ~ One distance (distance of one between all of the elements)
// ~ Large input (Large size input array)
// ~ Zero input (No input array)
// ~ Even input (array length is even)
// ~ Odd input (array length is odd)
// ~ Negative ints in array (some of the elements in the array have negative integers)
// ~ Random length input array, random distance between the elements
// ~ Random reversed sorted input array, random reversed sorted distance between the elements
// ~ Random sorted input array, random sorted distance between elements

// == TIMING TESTS ==
// ~ Random length input array, random distance between the elements
// ~ Random reversed sorted input array, random reversed sorted distance between the elements
// ~ Random sorted input array, random sorted distance between elements

// == OPERATIONAL TESTS ==
// ~ Random length input array, random distance between the elements
// ~ Random reversed sorted input array, random reversed sorted distance between the elements
// ~ Random sorted input array, random sorted distance between elements


// == FUNCTIONAL TESTS ==
    // == DISTANCE TESTING ==
        // ~ Large Element Distance (Distance is greater then INT_MAX)
        // ~ 0 Element Distance (All the same value)
        // ~ Random distance
        // ~ 1 Array length
        // ~ Elements are greater then the INT_MAX value
    // == INPUT SIZE TESTING ==
        // ~ Large input size array
        // ~ 0 input size array
        // ~ Even length array
        // ~ Odd length array
        // ~ Positive elements (DO WE NEED THIS?)
        // ~ Negative elements (DO WE NEED THIS?)

// == TIMING TESTS ==
    // ~ Random distance, Random length
    // ~ Random sorted distance, random length
    // ~ Random reversed distance, random length

// == OPERATIONAL TESTS ==
    // ~ Random distance, random length
    // ~ Random sorted distance, random length
    // ~ Random reversed distance, random length

// THINGS TO ADD IN THE ASSIGMENT
    // ~ TREND BETWEEN BOTH OF THE ALGORITHMS COMPARISON
    // ~ THEORETICAL COMPARISON USING MATHS

// TESTING
    // ~ DISTANCE BETWEEN EACH OF THE ELEMENTS
    // ~ LENGTH OF THE ARRAY

// EMAIL
    // c.wickramage@qut.edu.au

// RESOURCES
    //https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new


#include "headerFile.h"

// ==FUNCTIONAL TESTS==
// Large element distance
vector<int> largeDist()
{
    vector<int> innerArray;
    for (int i = 0; i < SIMULATIONS; i++)
    {
        innerArray.push_back(i*LARGE_ARRAY_DIST);
    }

    return innerArray;
}

// 0 Element distance (All elements are the same value)
vector<int> zeroDist()
{
    vector<int> innerArray;
    for (int i = 0; i < SIMULATIONS; i++)
    {
        innerArray.push_back(ZERO_ELEMENTS);
    }
    return innerArray;
}

// ~ Random distance
vector<int> randomDist()
{
    srand(time(0));
    vector<int> innerArray;
    for (int i = 0; i < SIMULATIONS; i++)
    {
        int random = rand() % RANDOM_RANGE;
        innerArray.push_back(i * random);
    }
    return innerArray;
}

// ~ 1 Array length
vector<int> oneDist()
{
    vector<int> innerArray;
    for (int i = 0; i < SIMULATIONS; i++)
    {
        innerArray.push_back(i);
    }
    return innerArray;
}








