////
//// Created by Jez Dufourq on 2019-04-03.
////
//#include <iostream>
//#include <vector>
//#include <iterator>
//#include <algorithm>
//#include <limits>
//#include <random>
//#include <ctime>
//#include <ratio>
//#include <chrono>
//#include <tuple>
//#include <sstream>
//#include <fstream>
//
//using namespace std;
//using namespace std::chrono;
//
//tuple<long,long, float> BruteForceMedian(vector<int> A);
//int testArray(vector<int>);
//
//int testArray(vector<int> testArray)
//{
//    auto[median, basicOp, timeTaken] = BruteForceMedian(testArray);
//
//    cout << "This is the test array" <<
//    endl;
//    print(testArray);
//    cout << "This is the output" << endl;
//    cout << median << ',' << basicOp << ',' << timeTaken << endl;
//    return 0;
//}
//
//
//tuple<long,long, float> BruteForceMedian(vector<int> A)
//{
//    int n = A.size();
//    int k = ceil(n/2.0);
//    int basicOp = 0;
//    tuple<int,int> outputArray;
//    duration<double> timeTaken;
//
//    for (int i = 0; i < (n - 1); i++ )
//    {
//        auto startTime = chrono::high_resolution_clock::now();
//
//        int numSmaller = 0;
//        int numEqual = 0;
//        for(int j = 0; j < (n - 1); j++)
//        {
//            if (A[j] < A[i])
//            {
//                basicOp++;
//                numSmaller++;
//            }
//            else
//            {
//                if(A[j] == A[i])
//                {
//                    basicOp++;
//                    numEqual++;
//                }
//            }
//        }
//        if(numSmaller < k and k <= (numSmaller+numEqual))
//        {
//            auto endTime = chrono::high_resolution_clock::now();
//            timeTaken = duration_cast<duration<double>>(endTime - startTime);
//
//            return make_tuple(A[i],basicOp, timeTaken.count());
//        }
//    }
//    return tuple<long, long, float>();
//}
//
//void print(vector<int> const &input)
//{
//    cout <<  "[";
//    // Auto in this case is used to cut down on writing vector each time
//    // Auto is implemented when the program is built
//    // It sets the input value automatically to a vector value
//    // TODO: Need to research this.
//    for (auto v: input)
//    {
//        cout << v << ",";
//    }
//    cout <<  "]" << endl;
//}
