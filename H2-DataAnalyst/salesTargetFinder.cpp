#include<iostream>
#include<string>
#include<sstream>

#include<vector>
#include<span>
#include<map>

const int NUM_MONTHS_IN_YEAR = 12;

// Map to convert month code to month index
std::map<std::string,int> monthToIndexMap = {{"Jan",0},
                        {"Feb",1},
                        {"Mar",2},
                        {"Apr",3},
                        {"May",4},
                        {"Jun",5},
                        {"Jul",6},
                        {"Aug",7},
                        {"Sep",8},
                        {"Oct",9},
                        {"Nov",10},
                        {"Dec",11}};

std::map<int,std::string> indexToMonthMap = {{0,"Jan"},
                        {1,"Feb"},
                        {2,"Mar"},
                        {3,"Apr"},
                        {4,"May"},
                        {5,"Jun"},
                        {6,"Jul"},
                        {7,"Aug"},
                        {8,"Sep"},
                        {9,"Oct"},
                        {10,"Nov"},
                        {11,"Dec"}};
                        
// Stores sales data mapped to month index
std::vector<int> testSalesData = {100, 113, 110, 85, 81, 101, 94, 106, 105, 102, 86, 63};
std::vector<int> salesData;

struct monthRange
{
    int m_start;
    int m_end;
    float m_score;
};

template<typename T>
void printOutVector(std::vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << "\n";
    }
}

void printOutVectorOfMonthRanges(std::vector<monthRange> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << "[" << v.at(i).m_start << "," << v.at(i).m_end << "] | " << v.at(i).m_score << "\n";
    }
}

void printOutVectorOfMonthRanges_PRETTY(std::vector<monthRange> v) {
    std::cout << "\"Month Start\" \"Month End\" \"Total Sales Above Average\"" << std::endl;
    for (int i = 0; i < v.size(); i++) {
        std::string m_start = indexToMonthMap.at(v.at(i).m_start);
        std::string m_end = indexToMonthMap.at(v.at(i).m_end);

        std::cout << m_start << " " << m_end << " " << v.at(i).m_score << std::endl;
    }
}

/**
 * Calculates all possible month ranges and how much each range differs from average sales
 * @param sales a vector of sales per month
 * @param maxRangeSize the maximum size a month range can be in number of months
 * @return std::vector<monthRange> a vector of all possible month ranges sorted by monthRange.m_score
 */
std::vector<monthRange> calculatePossibleRanges(std::vector<int> sales, int maxRangeSize, int numRangesToReturn) {
    std::vector<monthRange> bestRanges;

    // Check for edge cases
    if (sales.size() == 0) return bestRanges; // No sales data
    if (maxRangeSize <= 0) return bestRanges; // Can't find an ideal range with length < 1

    // Calculate average sales per month
    float averageSales = 0;
    for (int i = 0; i < sales.size(); i++) {
        averageSales += static_cast<float>(sales[i]);
    }
    averageSales = averageSales / sales.size();

    // Create an array with all possible month ranges
    std::vector<monthRange> possibleRanges;

    // Iterate through all possible range sizes
    for (int r_size = 1; r_size < maxRangeSize; r_size++) {
        // Iterate through all possible start months given a size
        for (int startMonth = 0; (startMonth+r_size) < sales.size(); startMonth++) {

            // Add a new range into the array of all possible ranges
            possibleRanges.push_back(monthRange());

            // Calculate end month
            int thisIndex = possibleRanges.size() - 1;
            int endMonth = startMonth + r_size - 1;

            // Calculate score
            float m_score = 0;
            for (int m = startMonth; m <= endMonth; m++) {
                m_score += static_cast<float>(sales[m]) - averageSales;
            }

            // Assign data to this month's range
            possibleRanges[thisIndex].m_start = startMonth;
            possibleRanges[thisIndex].m_end = endMonth;
            possibleRanges[thisIndex].m_score = m_score;
        }
    }

    // Sort month ranges from best to worst m_score, and in the case of a tie, from shortest to longest months in range
    // Use insertion sort since its highly unlikely that we have a best case scenario
    for (int i = 0; i < possibleRanges.size(); i++) {
        float highScore = possibleRanges[i].m_score;
        int lowRange = possibleRanges[i].m_end - possibleRanges[i].m_start;
        int highScoreIndex = i;

        for (int s = i+1; s < possibleRanges.size(); s++) {
            if (possibleRanges[s].m_score > highScore) { // Check to see if this range scores higher
                // Update high score values
                highScore = possibleRanges[s].m_score;
                highScoreIndex = s;
                lowRange = possibleRanges[s].m_end - possibleRanges[s].m_start;
            }
            else if (possibleRanges[s].m_score == highScore) { // If we have a score tie, check months in range
                if ((possibleRanges[s].m_end - possibleRanges[s].m_start) < lowRange) {
                    // Update high score values
                    highScore = possibleRanges[s].m_score;
                    highScoreIndex = s;
                    lowRange = possibleRanges[s].m_end - possibleRanges[s].m_start;
                }
            }
        }
        
        // Insert the best element to the beginning of the selection range by swapping it with the value currently
        // there
        monthRange bestRange = possibleRanges[highScoreIndex];
        possibleRanges[highScoreIndex] = possibleRanges[i];
        possibleRanges[i] = bestRange;
    }
    
    // Copy numRangesToReturn monthRanges from the now sorted possible ranges
    for (int i = 0; i < numRangesToReturn; i++) {
        bestRanges.push_back(possibleRanges[i]);
    }

    return bestRanges;
}

std::stringstream testInput("Month Sales in USD (Millions)\nJan 100\nFeb 113\nMar 110\nApr 85\nMay 81\nJun 101\nJul 94\nAug 106\nSep 105\nOct 102\nNov 86\nDec 63");


int main() {
    salesData = std::vector<int>(NUM_MONTHS_IN_YEAR, 0);

    // Read in input
    std::string line;
    int lineNumber = 0;
    while (std::getline(std::cin, line, '\n')) {
        if (lineNumber == 0) {
            lineNumber++;
            continue;
        }

        std::stringstream l(line);
        std::string val;

        int monthIndex = -1;

        while (std::getline(l, val, ' ') && monthIndex != -2) {
            
            if (monthIndex >= 0) {
                int salesInMonth = 0;
                try { // Try to convert to int
                    salesInMonth = std::stoi(val);
                } catch(std::invalid_argument const& ex) { // If conversion fails because it couldn't convert to int
                    std::cout << "Error: '" << line << "' does not contain a valid integer";
                    return 2;
                } catch (std::out_of_range const& ex) { // If conversion fails because the sales was too big
                    std::cout << "Error: '" << line << "' sales too big";
                    return 2;
                }
                if (salesInMonth < 0) {
                    std::cout << "Error: '" << line << "' contains negative sales";
                    return 1;
                }
                salesData[monthIndex] = std::stoi(val);
            }

            if (monthToIndexMap.count(val) != 0) {
                monthIndex = monthToIndexMap.at(val);
            }
            else {
                monthIndex = -2;
            }

        }
        lineNumber++;
    }

    printOutVectorOfMonthRanges_PRETTY(calculatePossibleRanges(salesData, NUM_MONTHS_IN_YEAR, 1));
    return 0;
}

