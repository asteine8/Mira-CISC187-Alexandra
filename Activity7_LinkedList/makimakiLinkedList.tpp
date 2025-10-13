

/**
 * Adds a new node to the front of the linked list (O_(1) time)
 */
template<typename T>
void MakiMakiLinkedList<T>::addNode(T newData) {
    
    // Instantiate a new node
    MakiNode<T> *newNode = new MakiNode<T>(newData);

    // Check if the LL is empty
    if (firstNode == NULL) {
        firstNode = newNode;
        return;
    }

    // Insert the new node at the beginning of the list
    // Link it to the next node
    newNode->nextNode = firstNode;
    firstNode = newNode;

}

/**
 * Deletes the first node
 */
template<typename T>
void MakiMakiLinkedList<T>::deleteNode() {
    // If the LL is empty, do nothing
    if (firstNode == NULL) return;

    MakiNode<T> *secondNode = firstNode->nextNode; // Store the address of the second node

    delete firstNode; // Delete the first node from memory

    firstNode = secondNode; // Set the first node pointer to point to the new first node
}

/**
 * Returns the number of nodes in the linked list in O_(N) time
 */
template<typename T>
int MakiMakiLinkedList<T>::length() {
    int l = 1; // Number of nodes in the LL

    // Check for an empty list
    if (firstNode == NULL) return 0; 

    // Follow the linked list back until we reach a node without a referent to the next node
    else {
        MakiNode<T>* n = firstNode;
        while (n->nextNode != NULL) {
            l++;
            n = n->nextNode;
        }
    }
    
    // Return the calculated length
    return l;
}

template<typename T>
MakiMakiLinkedList<T>::MakiMakiLinkedList() {
    firstNode = NULL;
}