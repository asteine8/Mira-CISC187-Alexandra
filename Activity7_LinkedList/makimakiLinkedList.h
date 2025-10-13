#ifndef MAKIMAKILINKEDLIST_H
#define MAKIMAKILINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/**
 * Helper struct for LL nodes
 */
template<typename T>
struct MakiNode {
    T data;
    MakiNode<T> *nextNode;

    MakiNode() {
        nextNode = NULL;
    }

    MakiNode(T d) {
        nextNode = NULL;
        data = d;
    }
};

/**
 * Linked list implementation made by my cat Maki (long may she rule)
 */
template<typename T> class MakiMakiLinkedList {
    private:

        MakiNode<T> *firstNode;

    public:
        MakiMakiLinkedList();
        void addNode(T newData); // Adds a node to the front of the linked list
        void deleteNode(); // Deletes the first node
        // T get(int i);
        // void set(T d);

        int length();

        /**
         * prints out the linked list to std::cout
         */
        void printOutLL() {
            std::cout << "[";
            MakiNode<T>* n = firstNode;
            int index = 0;

            while (n != NULL) {
                std::cout << n->data;
                if (n->nextNode != NULL) std::cout << ",";
                n = n->nextNode;
            }
            std::cout << "]" << std::endl;
        }
};

#include "makimakiLinkedList.tpp"
#endif
