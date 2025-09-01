# Week 1 Assignment - Arrays
Alexandra Steiner August 31st, 2025


## 1. How to Create an Array of 100 Elements
Use the format `<datatype> <arrayName>[<number of elements>]` to create an empty array. If you want to create an array of 100 elements then use 100 for `<number of elements>`
```cpp
// Empty, 100 element integer array
int emptyArray[100];

// Populating an array of 100 elements with shit
int notEmptyArray[100];
for (int i = 0; i < 100; i++) {
    notEmptyArray[i] = i;
}
```

## 2. What Will be the Size of Each Element in an Array?
The size of each array element is determined by the type of variable that the array contains. Additionally, the size of some variables can vary depending on the device that the code is run on. You can use the `sizeof()` function that is built into C++ to determine the size of an array element in bytes
```cpp
// Determining the size of an array element
int someArray[3] = {1,2,3};
cout << sizeof(someArray[1]);
```

## 3. For an array containing 100 elements, provide the number of steps the following operations would take:
For each of the following operation types, assume that the following has already been defined and is in scope
```cpp
int array[100] = {0};
```

### Reading
To read a single value from an array, simply use `array[n]` where `n` is the element index. This will take **one operation**

### Searching for a value not contained within the array
If you search for a value that isn't in the array, you end up having to iterate through every array element to check each one. Since our array has 100 elements, this will take **100 operations**

### Insertion at the beginning of the array
Since you need to shift each element up by one and add the new element, it would take **101 operations**

### Insertion at the end of the array
Since you don't need to shift any elements, it would only take **one operation**

### Deletion at the beginning of the array
If you delete the first element of an array, it takes one operation for the deletion and 99 to shift every other element down to compensate for a total of **100 operations**

### Deletion at the end of the array
There is no need to shift any of the other elements of the array so this would only take **one operation** for the deletion

## 4 - How many steps to find all instances of something in an array?
If you want to count the number of instances of something in an array, you need to check each element in the array to see if it matches. This means that it would take N operations

## 5 - How do you find the memory address of an array
You can use the `addressof` function to get the address of an array. Some code to determine the memory address of an array might look like:
```cpp
int array[100];
cout << addressof(array)
```



