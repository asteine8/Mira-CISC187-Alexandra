#include <vector>

class Task3 {
    public:
        static int findMostProfitableSale(int* arr, int arrayLength) {

            int largestProfit = 0;
            int lowestPrice = arr[0];

            for (int i = 1; i < arrayLength; i++) {
                if (arr[i] < lowestPrice) { // Update lowest price so far
                    lowestPrice = arr[i];
                }
                else if ((arr[i] - lowestPrice) > largestProfit) { // Calculate profit and update largest profit
                    largestProfit = arr[i] - lowestPrice;
                }
            }

            return largestProfit;

        }
};