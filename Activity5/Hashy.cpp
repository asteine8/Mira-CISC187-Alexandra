#include <unordered_map>
#include <iostream>
#include <string>

std::size_t generateHash(std::string s) {
    std::size_t h = 0;
    for (int i = 0; i < s.length(); i++) {
        h += (int)s[i]; // Add the ASCII value of each character
    }
    return h;
}

int main() {
    // Write a code in C++/Python to improve the search operation efficiency from $O(N)$ to $O(1)$
    /*
    std::unordered_map is an associative container that contains key-value pairs with unique keys. Search, insertion, and removal of elements have average constant-time complexity. - https://en.cppreference.com/w/cpp/container/unordered_map.html
    */
    std::unordered_map<int, int> array = {{200,0},{400,1},{100,2},{50,3},{350,4}}; // <value, index>

    std::cout << array[100] << std::endl; // prints the index of 100 (2)

    // Generate a hash of your name
    std::string myName = "Alexandra C Steiner";
    auto h = generateHash(myName);
    std::cout << "Hash of " << myName << " is: " << h << std::endl;

    return 0;
}