#include <unordered_map>

class Task6 {
    public:

        static int findLargestConsecutiveSequence(int* arr, int arrayLength) {

            // Find bounds of array
            int lowestNum = arr[0];
            int highestNum = arr[0];

            // O(N)
            for (int i = 1; i < arrayLength; i++) {
                if (arr[i] < lowestNum) lowestNum = arr[i];
                if (arr[i] > highestNum) highestNum = arr[i];
            }

            std::unordered_map<int, bool> numberMap;

            // Create map spanning all integers contained in array
            // Value stored at integer is false
            // Technically O(1), but likely O(N + C) in reality due to no repeat
            // numbers in the test arrays
            for (int i = lowestNum; i <= highestNum; i++) {
                numberMap.insert({i, false});
            }

            // Set values found in the array true on the map
            // O(N) since all keys should exist
            for (int i = 1; i < arrayLength; i++) {
                numberMap[arr[i]] = true;
            }

            // Find longest sequence on map
            int longestSequence = 1;
            int startNum = lowestNum;
            int currentSequenceLength = 1;
            for (int i = lowestNum+1; i <= highestNum; i++) {
                if (numberMap[i] == true) { // This number is in our array
                    if (startNum == (i-currentSequenceLength)) { // In sequence
                        currentSequenceLength++;
                    }
                    else { // Out of sequence, restart count
                        currentSequenceLength = 1;
                        startNum = i;
                    }


                }
                else { // End of sequence, update longestSequence if bigger one found
                    if (currentSequenceLength > longestSequence) {
                        longestSequence = currentSequenceLength;
                    }
                    currentSequenceLength = 1;
                }
            }

            // Set longest sequence to currentSequenceLength if sequence ends at largest number
            if (currentSequenceLength > longestSequence) {
                longestSequence = currentSequenceLength;
            }

            return longestSequence;
        }
};