# Space constraints
Alexandra Steiner - 11/23/25

Video Link: https://youtu.be/bg_b0Eh7E_s

1. Following is the 'Word Builder' algorithm. Describe its space complexity in terms of Big O.

```js
function wordBuilder(array) { 
		let collection = [];
		for(let i = 0; i < array.length; i++) { 
				for(let j = 0; j < array.length; j++) {
						if (i !== j) {
								collection.push(array[i] + array[j]);
						}
				}
		}
		return collection; 
}
```

The space complexity is O(N^2)

2. Following is a function that reverses an array. Describe its *space* complexity in terms of Big O:

```js
function reverse(array) { 
		let newArray = [];
		for (let i = array.length - 1; i >= 0; i--) { 
				newArray.push(array[i]);
		}
		return newArray;
}
```

The Space complexity is also O(N)

3. Create a new function to reverse an array that takes up just $O(1)$ extra space.
```js
function reverse(array) {
    var e1;
    var e2;
    for (var i = 0; i < array.length/2; i++) {
        // swap elements
        e1 = array[i];
        e2 = array[array.length-i-1];
        array[i] = e2;
        array[array.length-i-1] = e1;
    }
    return array;
}

console.log(reverse([1,2,3,4,5]));
console.log(reverse([1,2,3,4]));
```
4. Following are three different implementations of a function that accepts an array of numbers and returns an array containing those numbers multiplied by 2. For example, if the input is [5, 4, 3, 2, 1], the output will be [10, 8, 6, 4, 2].

````js
function doubleArray1(array) { 
	let newArray = [];

	for(let i = 0; i < array.length; i++) { 
		newArray.push(array[i] * 2);
	}
	return newArray; 
}


function doubleArray2(array) {
	for(let i = 0; i < array.length; i++) {
  	array[i] *= 2;
  }
	return array; 
}


function doubleArray3(array, index=0) { 
	if (index >= array.length) { return; }
  array[index] *= 2;
  doubleArray3(array, index + 1);
	return array; 
}
````

Fill in the table that follows to describe the efficiency of these three versions in terms of both time and space:

| Version    | Time complexity | Space complexity |
| ---------- | --------------- | ---------------- |
| Version #1 | O(N)            | O(N)             |
| Version #2 | O(N)            | O(1)             |
| Version #3 | O(N)            | O(1)             |

The space complexity of v#3 depends on if the array is being passed by reference or copied into the function. Given the syntax, it appears that these functions are written in javascript which would mean that the array is being passed by reference. Consequently, the O(1) space complexity is what you'd get.

