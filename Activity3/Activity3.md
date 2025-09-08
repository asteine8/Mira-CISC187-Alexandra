# Week 3 Activity - Sorting 1
Alexnadra Steiner - 9/8/25

## 1 - Use Big O Notation to describe the time complexity of an algorithm that takes 4N + 16 steps
An algorithm that takes 4N + 16 steps has a time complexity of O(N)
## 2 - Use Big O Notation to describe the time complexity of an algorithm that takes 2N^2
An algorithm that takes 2N^2 steps has a time complexity of O(N^2)
## 3 - Use Big O Notation to describe the time complexity of the following function, which returns the sum of all numbers of an array after the numbers have been doubled:
```
def double_then_sum(array) 
	doubled_array = []

	array.each do |number| 
		doubled_array << number *= 2
	end

	sum = 0

	doubled_array.each do |number| 
		sum += number
	end
	return sum 
end
```

The above function takes 2N + C steps which means that it operates in O(N) time complexity

## 4 - Use Big O Notation to describe the time complexity of the following function, which accepts an array of strings and prints each string in multiple cases:
```
def multiple_cases(array) 
	array.each do |string|
		puts string.upcase 
		puts string.downcase 
		puts string.capitalize
	end 
end
```

The above function takes 3N + C steps which means that it operates in O(N) time complexity
## 5 - The next function iterates over an array of numbers, and for each number whose index is even, it prints the sum of that number plus every number in the array. What is this function’s efficiency in terms of Big O Notation?-
```
def every_other(array) 
	array.each_with_index do |number, index|
		if index.even?
			array.each do |other_number|
            	puts number + other_number
			end 
		end
	end 
end
```

The above function takes N^2/2 + C steps which means it operates in O(N^2) time complexity
