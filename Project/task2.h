#include <unordered_map>

class Task2 {
    public:

        /**
         * Returns the missing number from an array. Operates in O_(N) time complexity
         * @param arr Integer array to check
         * @param arrLength Length of the array
         * @return the missing number if found, -1 if no integer missing found
         */
        static int getMissingNumber(int* arr, int arrLength) {
            int missingNum = 0;

            // Find lowest number and highest number
            // O(N)
            int lowestNum = arr[0];
            int highestNum = arr[0];
            for (int i = 1; i < arrLength; i++) {
                if (arr[i] < lowestNum) lowestNum = arr[i];
                if (arr[i] > highestNum) highestNum = arr[i];
            }

            // Generate a map from the lowest to highest number
            // roughly O(N-1)
            std::unordered_map<int,bool> numberMap;
            for (int i = lowestNum; i <= highestNum; i++) {
                numberMap.insert({i, false});
            }

            // Set numberMap keys with existing numbers in the array to true
            // O(N)
            for (int i = 0; i < arrLength; i++) {
                numberMap[arr[i]] = true;
            }

            // Check for the first missing number
            // roughly O(N-1)
            for (int i = lowestNum; i <= highestNum; i++) {
                if (numberMap[i] == false) {
                    return i;
                }
            }

            // If no missing number found, return -1;
            return -1;
            
        }
};
