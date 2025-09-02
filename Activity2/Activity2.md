# Week 2 Activity - Search
Alexandra Steiner September 1st, 2025

## 1 - How many steps would it take to perform a linear search for the number 8 in the ordered array, [2, 4, 6, 8, 10, 12, 13]?
Given a linear search algorithm, it would take **4 steps** to find the number 8 in the provided array

## 2 - How many steps would binary search take for the previous example?
A binary search algorithm would take **one step** to find the number 8

## 3 - What is the maximum number of steps it would take to perform a binary search on an array of size 100,000?
The maximum number of steps a binary search would take is given by $log_2(n)$. For an array of size 100,000 it should take $log_2(100,000)$ steps which comes out to 17 steps

## 4 - Write a C++ code that implements the linear and binary search algorithms. The algorithm should be able to calculate the number of steps against the given search
See `searchTest.cpp`

```cpp
#include <iostream>

using namespace std;

/**
 * Does a linear search for targetValue in array. Returns how many steps it took to find the target value.
 * 
 * @param array array to search through
 * @param arraySize size of the array
 * @param targetValue the value to search for
 * @param index the index of the element found. Will be -1 if none found
 * 
 * @return the number of steps it took to find the targetValue
 */
int benchmarkedLinearSearch(int array[], int arraySize, int targetValue, int *index) {
    int numOperations = 0;
    for (int i = 0; i < arraySize; i++) {
        numOperations ++;
        if (array[i] == targetValue) {
            *index = i;
            return numOperations;
        }
    }

    // No targetValue found, set index to -1 and return
    *index = -1;
    return numOperations;
}

/**
 * Does a binary search for targetValue in array. Returns how many steps it took to find the target value.
 * 
 * @param array array to search through
 * @param arraySize size of the array
 * @param targetValue the value to search for
 * @param index the index of the element found. Will be -1 if none found
 * 
 * @return the number of steps it took to find the targetValue
 */
int benchmarkedBinarySearch(int array[], int arraySize, int targetValue, int *index) {
    int numOperations = 0;

    int L,R,m;
    L = 0;
    R = arraySize - 1;

    while (L <= R) {
        numOperations ++;
        m = (L + R) / 2; // Integer division is floored

        if (array[m] < targetValue) {
            L = m + 1;
        }
        else if (array[m] > targetValue) {
            R = m - 1;
        }
        else { // Found it!
            *index = m;
            return numOperations;
        }
    }

    // No targetValue found, set index to -1 and return
    *index = -1;
    return numOperations;
}

int main() {
    int testArray[7] = {2, 4, 6, 8, 10, 12, 13};
    int testArraySize = sizeof(testArray) / sizeof(testArray[0]);
    int t = 8;

    // Print out the array
    cout << "Searching through the array: [";
    for (int i = 0; i < testArraySize-1; i++) {
        cout << testArray[i] << ",";
    }
    cout << testArray[testArraySize - 1] << "]" << endl;

    cout << endl;

    // Run linear search algorithm
    int linearSearchedIndexOft;
    int numLinearOperations = benchmarkedLinearSearch(testArray, testArraySize, t, &linearSearchedIndexOft);

    cout << "Linear Search:" << endl;
    cout << "Found target value " << t << " at index " << linearSearchedIndexOft << endl;
    cout << "It took " << numLinearOperations << " operations" << endl;

    cout << endl;
    // Run binary search algorithm
    int binarySearchedIndexOft;
    int numBinaryOperations = benchmarkedBinarySearch(testArray, testArraySize, t, &binarySearchedIndexOft);

    cout << "Binary Search:" << endl;
    cout << "Found target value " << t << " at index " << binarySearchedIndexOft << endl;
    cout << "It took " << numBinaryOperations << " operations" << endl;

}
```