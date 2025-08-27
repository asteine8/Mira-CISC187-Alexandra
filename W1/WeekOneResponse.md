# Week 1 Assignment - Arrays

Arrays are a type of data structure that contains ...

## How to Create an Array of 100 Elements
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

## What Will be the Size of Each Element in an Array?
The size of each array element is determined by the type of variable that the array contains. Additionally, the size of some variables can vary depending on the device that the code is run on. You can use the `sizeof()` function that is built into C++ to determine the size of an array element
```cpp
// Determining the size of an array element
int someArray[3] = {1,2,3};
cout << sizeof(someArray[1]);
```

## How Many Operations Would It Take to Make an Array With 100 Elements?

