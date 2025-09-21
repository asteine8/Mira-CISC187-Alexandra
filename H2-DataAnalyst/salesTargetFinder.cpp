#include<iostream>
#include<vector>
#include<span>
#include<map>

const int NUM_MONTHS_IN_YEAR = 12;

// Map to convert month code to month index
std::map<std::string,int> month = {{"jan",0},
                        {"feb",1},
                        {"mar",2},
                        {"apr",3},
                        {"may",4},
                        {"jun",5},
                        {"jul",6},
                        {"aug",7},
                        {"sep",8},
                        {"oct",9},
                        {"nov",10},
                        {"dec",11}};
                        
// Stores sales data mapped to month index
std::vector<int> salesData = {100, 113, 110, 85, 81, 101, 94, 106, 105, 102, 86, 63};

struct monthRange
{
    int m_start;
    int m_end;
};

template<typename T>
void printOutVector(std::vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << "\n";
    }
}

std::vector<monthRange> findBestSalesMonthRange(std::vector<int> sales, int maxRangeSize) {
    std::vector<monthRange> bestRanges;

    // Check for edge cases
    if (sales.size() == 0) return bestRanges; // No sales data
    if (maxRangeSize <= 0) return bestRanges; // Can't find an ideal range with length < 1


    // Create an array with all possible month ranges
    std::vector<monthRange> possibleRanges;

    // Iterate through all possible sizes
    for (int r_size = 1; r_size < maxRangeSize; r_size++) {
        // Iterate through all possible start months given a size
        for (int startMonth = 0; (startMonth+r_size) < sales.size(); startMonth++) {

            // Add a new range into the array of all possible ranges
            possibleRanges.push_back(monthRange());
            possibleRanges[possibleRanges.size() - 1].m_start = startMonth;
            possibleRanges[possibleRanges.size() - 1].m_start = startMonth;
        }
    }

    // Calculate average sales per month
    float average = 0;
    for (int i = 0; i < sales.size(); i++) {
        average = average + static_cast<float>(sales[i]);
    }
    average /= sales.size();

    printOutVector(sales);
    // printOutVector(possibleRanges);
}


int main() {
    findBestSalesMonthRange(salesData, 12);
    return 0;
}

