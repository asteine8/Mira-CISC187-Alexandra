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