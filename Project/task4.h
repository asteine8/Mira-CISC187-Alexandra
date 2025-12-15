#include <cstdlib>
#include <iostream>


class Task4 {
    public:
        static int findHighestProduct(int *arr, int arrayLength) {
            int highestNum = arr[0];
            int lowestNum = arr[0];

            // Find highest and lowest numbers in array
            for (int i = 1; i < arrayLength; i++) {
                if (arr[i] > highestNum) highestNum = arr[i];
                if (arr[i] < lowestNum) lowestNum = arr[i];
            }

            int secondHighestNum = lowestNum;
            int secondLowestNum = highestNum;

            // Find second highest and lowest numbers in array
            for (int i = 0; i < arrayLength; i++) {
                if (arr[i] > secondHighestNum && arr[i] < highestNum) secondHighestNum = arr[i];
                if (arr[i] < secondLowestNum && arr[i] > lowestNum) secondLowestNum = arr[i];
            }

            // The highest product will either be the product of the two highest numbers or the
            // two lowest numbers if both are negative

            int p1 = highestNum * secondHighestNum;
            int p2 = lowestNum * secondLowestNum;

            // std::cout << p1 << "," << p2 << std::endl;

            return (p1 > p2) ? p1 : p2; // Return the greatest of the two products
        }

};