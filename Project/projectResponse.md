# Final Project
Alexandra Steiner

Video Link: https://youtu.be/_ML8bwgXDy4


## Task 1

```cpp
struct Player {
    std::string firstName;
    std::string lastName;
    std::string team;

    Player(std::string fn, std::string ln, std::string tm) {
        firstName = fn;
        lastName = ln;
        team = tm;
    }
};


class PlayerRoster {
    public:
        // key = first name+last name
        std::unordered_map<std::string, Player> players;

        void addPlayer(Player player) {
            std::string fullName = player.firstName + " " + player.lastName;
            players.insert({fullName, player});
        }

        void addPlayers(std::vector<Player> ps) {
            for (auto p : ps) {
                std::string fullName = p.firstName + " " + p.lastName;
                players.insert({fullName, p});
            }
        }

        void appendRoster(PlayerRoster roster) {
            // players.merge(roster.players);
            for (auto p : roster.players) {
                players.insert(p);
            }
        }

        void printRoster() {
            std::cout << "[" << std::endl;
            for (auto player : players) {
                std::cout << "{first_name: ";
                std::cout << player.second.firstName << ", last_name: ";
                std::cout << player.second.lastName << ", team: ";
                std::cout << player.second.team;
                std::cout << "}" << std::endl;
            }
            std::cout << "]";
        }
};

class Task1 {
    public:

        static PlayerRoster findSharedPlayers(PlayerRoster roster1, PlayerRoster roster2) {

            // Operates in O(N+M) time
            PlayerRoster allPlayers;
            allPlayers.appendRoster(roster1);
            allPlayers.appendRoster(roster2);

            std::unordered_map<std::string, bool> playerMap;

            // Also in O(N+M) time
            for (auto it: allPlayers.players) {
                playerMap.insert({it.first, false});
            }

            // Operates in O(N)
            for (auto it: roster1.players) {
                playerMap[it.first] = true;
            }

            PlayerRoster sharedPlayers;

            // Operates in O(M)
            for (auto it: roster2.players) {
                if (playerMap[it.first] == true) {
                    sharedPlayers.addPlayer(it.second);
                }
            }

            return sharedPlayers;
        }
};
```

## Task 2
```cpp

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
```

## Task 3
```cpp

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
```

## Task 4
```cpp
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
```

## Task 5
```cpp
class Task5 {
    public:
        static std::vector<double> sortBodyTemperatures(std::vector<double> temps) {
            std::vector<double> sortedTemps;

            // Checks a finite number of cases that do not scale with N
            for (double t = 97.05; t <= 99.1; t += 0.1) {
                for (double temp : temps) { // Iterate through temperatures
                    if (temp < t && temp > (t-0.1)) {
                        sortedTemps.push_back(temp);
                    }
                }
            }

            return sortedTemps;
        }
};
```

## Task 6
```cpp
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
```

## Test Code
```cpp
#include <iostream>
#include <vector>

#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"


/**
 * Prints out an array with commas between members
 */
template<typename T>
void printOutArray(T* arr, int arrLength) {
    std::cout << "[";
    for (int i = 0; i < arrLength-1; i++) {
        std::cout << arr[i] << ",";
    }
    std::cout << arr[arrLength-1];
    std::cout << "]";
}

/**
 * Prints out a vector with commas between members
 */
template<typename T>
void printOutVector(std::vector<T> v) {
    std::cout << "[";
    for (int i = 0; i < v.size()-1; i++) {
        std::cout << v[i] << ",";
    }
    std::cout << v[v.size()-1];
    std::cout << "]";
}

/**
 * Run unit tests
 */
int main() {

    // Test Task 1
    std::cout << "Running Task 1" << std::endl;
    PlayerRoster basketball_players;
    basketball_players.addPlayer(Player("Jill","Huang","Gators"));
    basketball_players.addPlayer(Player("Janko","Barton","Sharks"));
    basketball_players.addPlayer(Player("Wanda","Vakulskas","Sharks"));
    basketball_players.addPlayer(Player("Jill","Moloney","Gators"));
    basketball_players.addPlayer(Player("Luuk","Watkins","Gators"));

    std::cout << "Basketball Players: ";
    basketball_players.printRoster();
    std::cout << std::endl;

    PlayerRoster football_players;
    football_players.addPlayer(Player("Hanzla","Radosti","32ers"));
    football_players.addPlayer(Player("Tina","Watkins","Barleycorns"));
    football_players.addPlayer(Player("Alex","Patel","32ers"));
    football_players.addPlayer(Player("Jill","Huang","Barleycorns"));
    football_players.addPlayer(Player("Wanda","Vakulskas","Barleycorns"));

    std::cout << "Football Players: ";
    football_players.printRoster();
    std::cout << std::endl;

    PlayerRoster sharedPlayers = Task1::findSharedPlayers(basketball_players, football_players);
    std::cout << "Shared Players: ";
    sharedPlayers.printRoster();
    
    std::cout << std::endl << std::endl;

    // Test Task 2
    int array2[] = {1,2,5,3,6,7}; // Missing a 4
    std::cout << "Running Task 2 with ";
    printOutArray<int>(array2, 6);
    std::cout << std::endl << "Found missing number: ";
    std::cout << Task2::getMissingNumber(array2, 6) << std::endl << std::endl;

    // Test Task 3
    int array3[] = {10, 7, 5, 8, 11, 2, 6};
    std::cout << "Running Task 3 with ";
    printOutArray<int>(array3, 7);
    std::cout << std::endl << "Found highest profit to be: ";
    std::cout << Task3::findMostProfitableSale(array3, 7) << std::endl << std::endl;

    // Test Task 4
    int array4[] = {-20,-5,0,12,4,-1};
    std::cout << "Running Task 4 with ";
    printOutArray<int>(array4, 6);
    std::cout << std::endl << "Found highest product to be: ";
    std::cout << Task4::findHighestProduct(array4, 6) << std::endl << std::endl;

    // Test Task 5
    std::vector<double> vector5 = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};
    std::cout << "Running Task 5 with ";
    printOutVector<double>(vector5);
    std::cout << std::endl << "Sorted Array to get: ";
    printOutVector<double>(Task5::sortBodyTemperatures(vector5));
    std::cout << std::endl << std::endl;

    // Test Task 6
    int array6a[] = {10, 5, 12, 3, 55, 30, 4, 11, 2};
    int array6b[] = {19, 13, 15, 12, 18, 14, 17, 11};

    std::cout << "Running Task 6 with ";
    printOutArray<int>(array6a, 9);
    std::cout << std::endl << "Found longest sequence to be: ";
    std::cout << Task6::findLargestConsecutiveSequence(array6a, 9) <<std::endl;

    std::cout << "Running Task 6 with ";
    printOutArray<int>(array6b, 8);
    std::cout << std::endl << "Found longest sequence to be: ";
    std::cout << Task6::findLargestConsecutiveSequence(array6b, 8) <<std::endl << std::endl;


    return 0;
}

```