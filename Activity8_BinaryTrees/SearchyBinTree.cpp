#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template<typename T>
struct Node {
    Node *rightNode; // Bigger value
    Node *leftNode; // Smaller value
    T value;
    Node (T val) {
        value = val;
    }
};

template<typename T>
class SearchyBinTree {
    public:
    Node<T> *root;

    SearchyBinTree() {
        root = NULL;
    }

    void Insert(T val) {
        // Instantiate and allocate for a new node with the expected value
        Node<T> *newNode = new Node<T>(val);

        // If this tree is empty, put the value at the root
        if (root == NULL) {
            root = newNode;
            return;
        }

        Node<T> *currentNode = root;
        while (val != currentNode->value) { // If we find the exact same value, the insert fails
            if (val > currentNode->value) { // Greater Than
                if (currentNode->rightNode != NULL) currentNode = currentNode->rightNode;
                else {
                    currentNode->rightNode = newNode;
                    return;
                }
            }
            else { // Less Than
                if (currentNode->leftNode != NULL) currentNode = currentNode->leftNode;
                else {
                    currentNode->leftNode = newNode;
                    return;
                }
            }
        }
    }
};


SearchyBinTree<int> *myTree = new SearchyBinTree<int>();
//[1, 5, 9, 2, 4, 10, 6, 3, 8]
int main() {
    myTree->Insert(1);
    myTree->Insert(5);
    myTree->Insert(9);
    myTree->Insert(2);
    myTree->Insert(4);
    myTree->Insert(10);
    myTree->Insert(6);
    myTree->Insert(3);
    myTree->Insert(8);

    return 1;
}
