# Activity 7 - Linked lists
Alexandra Steiner 10-12-25

Video Link: https://youtu.be/tCIajMvYf3A

## Assignment
```
Create a linked list in C++, add nodes and delete nodes at the start of the list.
```

## Test code for implementation
See other files in folder for class implementation

```cpp
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
```

**OUTPUT:**
```
[24,14,5,4]
[14,5,4]
```