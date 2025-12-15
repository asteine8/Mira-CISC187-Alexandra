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

