#include "makimakiLinkedList.h"
#include <iostream>

// Create a linked list
MakiMakiLinkedList<int> *testLL = new MakiMakiLinkedList<int>();

int main() {
    // Add nodes to the start of the list
    testLL->addNode(4);
    testLL->addNode(5);
    testLL->addNode(14);
    testLL->addNode(24);

    // Print out the current LL
    testLL->printOutLL();

    // Delete the first node
    testLL->deleteNode();

    // Print out the current LL
    testLL->printOutLL();
    
    return 1;
}