#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <tuple>
#include <ctime>
#include <ratio>
#include <chrono>
#include <cstdlib>


using namespace std;
using namespace std::chrono;

//declaring a type of vector to hold tuples
typedef vector < tuple<int, int,float> >listOfTuples;

//method to fill a dummy csv
void populateCsv(int numValues);
tuple<long, long, float> bruteForceMedian();



int main()
{
    cout << "Assessment 1: BruteForceMedian | Sai Whiley n9454829" << endl;
    int numValues = 0;
    float runtime;
    long operationsTotal;
    int arrayLength;
    float meanRuntime;
    long meanOperations;

    listOfTuples tuples;

    ofstream results;
    results.open("results.csv", fstream::app);
    results << "Array Size,MeanOperations,MeanRuntime";
    for(int i = 0; i < 100; i++){
        numValues += 10;
        tuples.clear();

        for(int j = 0; j < 100; j++){
            populateCsv(numValues);
            tuples.emplace_back(bruteForceMedian());
        }

        for(auto &n : tuples){
            arrayLength = get<0>(n);
            operationsTotal += get<1>(n);
            runtime += get<2>(n);
        }

        meanRuntime = runtime/100;
        meanOperations = operationsTotal/100;

        results << "\r" << arrayLength << "," << meanOperations << "," << meanRuntime;


        //reset
        meanOperations = 0;
        meanRuntime = 0;
        operationsTotal = 0;
        runtime = 0;


    }
    results.close();
}

//populateCsv - populates a csv with random values to have the median found
void populateCsv(int numValues){
    ofstream output;
    output.open("input.csv");
    //seed srand with time in ms
    milliseconds ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    srand(ms.count());
    for(int i=0; i<numValues; i++){
        output << rand()%100 << "\r\n";
    }
    output.close();
}

tuple<long,long,float> bruteForceMedian(){
    int numsmaller;
    int numequal;
    vector<int> A;
    string inputString;
    duration<double> timeTaken;

    //open
    ifstream input;
    input.open("input.csv");
    //make sure it opens, print error if doesnt
    if(!input.is_open()){
        cout << "stream did not open" <<endl;
        int wait;
        cin >> wait;
    }

    for (string line; getline(input,line);){
        //stream line number to int
        int lineInt;
        istringstream(line) >> lineInt;
        //add to vector
        A.push_back(lineInt);
    }

    steady_clock::time_point timeAtStart  = steady_clock::now();

    int arrayLength  = A.size();
    int k = arrayLength/2;
    int basicOperations = 0;

    //manage odd array halves
    if(arrayLength%2 == 1){
        k++;
    }
    cout << "Array of size: " << A.size() << " k = " << k << " ";

    for(int i = 0;  i < arrayLength-1; i++){
        numsmaller = 0;
        numequal = 0;
        for(int j = 0; j < arrayLength-1; j++){
            basicOperations++;
            if(A[i] > A[j]){
                numsmaller++;
            }else{
                basicOperations++;
                if(A[i] == A[j]){
                    numequal++;
                }
            }
        }
        if(numsmaller < k && k <= (numsmaller + numequal)){
            steady_clock::time_point timeFinished = steady_clock::now();
            timeTaken = duration_cast<duration<double>>(timeFinished - timeAtStart);

            cout << "median:" << A[i];
            cout << " basic operations: " << basicOperations << " for array size " << arrayLength << endl;

            return make_tuple(arrayLength, basicOperations, timeTaken.count());

        }

    }
    return tuple<long, long, float>();
}