#include <iostream>
#include <iterator>
#include <array>

using namespace std;


/**
 * Does a linear search for targetValue in array. Returns how many steps it took to find the target value.
 * 
 * @param array array to search through
 * @param targetValue the value to search for
 * @param index the index of the element found. Will be -1 if none found
 * 
 * @return the number of steps it took to find the targetValue
 */
template<size_t SIZE>
int benchmarkedLinearSearch(array<int, SIZE> array, int targetValue, int *index) {
    int numOperations = 0;
    for (int i = 0; i < array.size(); i++) {
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
template<size_t SIZE>
int benchmarkedBinarySearch(array<int, SIZE> array, int targetValue, int *index) {
    int numOperations = 0;

    int L,R,m;
    L = 0;
    R = array.size() - 1;

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
    array<int, 7> testArray{2, 4, 6, 8, 10, 12, 13};
    int t = 8;

    // Print out the array
    cout << "Searching through the array: [";
    for (int i = 0; i < testArray.size()-1; i++) {
        cout << testArray[i] << ",";
    }
    cout << testArray[testArray.size() - 1] << "]" << endl;
    cout << "Array size = " << testArray.size() << endl;


    cout << endl;

    // Run linear search algorithm
    int linearSearchedIndexOft;
    int numLinearOperations = benchmarkedLinearSearch<testArray.size()>(testArray, t, &linearSearchedIndexOft);

    cout << "Linear Search:" << endl;
    cout << "Found target value " << t << " at index " << linearSearchedIndexOft << endl;
    cout << "It took " << numLinearOperations << " operations" << endl;

    cout << endl;
    // Run binary search algorithm
    int binarySearchedIndexOft;
    int numBinaryOperations = benchmarkedBinarySearch<testArray.size()>(testArray, t, &binarySearchedIndexOft);

    cout << "Binary Search:" << endl;
    cout << "Found target value " << t << " at index " << binarySearchedIndexOft << endl;
    cout << "It took " << numBinaryOperations << " operations" << endl;

}