#include <iostream>
using namespace std;

int main() {
    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = i;
    }

    cout << "The size of one element of 'array' is ";
    cout << sizeof(array[1]) << "bytes" << endl;

    cout << "The address of the array is ";
    cout << addressof(array) << endl;

    return 0;
}