//
// Created by Jez Dufourq on 2019-05-09.
//
// == FUNCTIONAL TESTS ==
    // == DISTANCE TESTING ==
        // ~ Large Element Distance
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
    // ~ Random distance
    // ~ Random sorted distance
    // ~ Random reversed distance

// == OPERATIONAL TESTS ==
    // ~ Random distance
    // ~ Random sorted distance
    // ~ Random reversed distance



// THINGS TO ADD IN THE ASSIGMENT
    // ~ TREND BETWEEN BOTH OF THE ALGORITHMS COMPARISON
    // ~ THEORETICAL COMPARISON USING MATHS

// TESTING
    // ~ DISTANCE BETWEEN EACH OF THE ELEMENTS
    // ~ LENGTH OF THE ARRAY

// EMAIL
    // c.wickramage@qut.edu.au
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








