# Arrays - Honors contract
Alexandra 9-22-25

Video Link: https://youtu.be/CVxUeEjeJgg

## Approach
To diversify the range of possible inputs, I plan to make this tool a command line tool that takes `std::cin` that can be piped directly from text on the command line, or piped from an existing file. Output will be through `std::cout` that can be either printed to the console or piped to anything else.

**Input: std::istream**
Input is read as a space delimitated table. The first row is discarded. Table format is expected to be:

```
Month Sales in USD (Millions)
Jan	100
Feb	113
Mar	110
Apr	85
May	81
Jun	101
Jul	94
Aug	106
Sep	105
Oct	102
Nov	86
Dec	63
```

**Output: std::ostream**
Output is formatted as a space delimitated table

```
"Month Start" "Month End" "Total Sales Above Average" 
Jan Mar 52
```


### General Algorithm for Computing Optimal Advertisement Months
1. Calculate average value of array
2. Determine all valid month ranges
3. Calculate sum of distances from average for each group to get group score
4. Sort month ranges by group score then range
5. Return any number of now ranked month ranges

Possible Edge Cases and Solutions:
- All months have the same sales
  - Selects a single month
- Negative sales numbers
  - Negative sales numbers are invalid
- Not all months provided in dataset
  - We can't make assumptions on data we don't have so assume sales in that month is 0
- Tied groups
  - Select group with the least months. This reduces advertising costs

## Psuedocode and Time Complexity Analysis

### Psuedocode:
My method has O_(N^2) time complexity. This wasn't preferable, but it shouldn't be an issue due to the small dataset having a maximum of 78 possible month ranges in a single year.

```
sales[12] := input
calculatePossibleRanges(sales, 12, 1)

structure monthRange {
  st,
  end,
  score
}

function calculatePossibleRanges(sales[], maxRangeSize, numRangesToReturn):

  // Calculate average sales
  average := 0
  for (s in sales):
    average += s
  average := average / sales.size

  possibleRanges[] := new array<type monthRange>

  // Calculate score for all possible ranges < O_(N^2)
  for (rangeSize in range(1,maxRangeSize)):
    for (startMonth := 0; (startMonth + rangeSize) < sales.size; startMonth ++):
      score := 0;
      for (s in sales):
        score += s - average

      possibleRanges.push(
        new MonthRange(
          st := startMonth,
          end := startMonth + rangeSize,
          score := score
        )
      )

  // Perform Selection Sort O_(N^2)
  for (r in range(0, possibleRanges.size)):
    highScore := possibleRanges[r].score
    lowRange := possibleRanges[r].end - possibleRanges[0].st
    bestIndex := r

    for (s in range(i+1, possibleRanges.size)):
      if (possibleRanges[s].score > highScore):
        bestIndex := s
        highScore := possibleRanges[s].score
        lowRange  := possibleRanges[s].end - possibleRanges[s].st

      else if (possibleRanges[s].score == highScore):
        if (possibleRanges[s].end - possibleRanges[s].st) < lowRange):
          bestIndex := s
          highScore := possibleRanges[s].score
          lowRange  := possibleRanges[s].end - possibleRanges[s].st
    
    possibleRanges.swap(bestIndex, r)
  
  // Only return as many ranked month ranges as asked for
  return possibleRanges.subset(0, numRangesToReturn)
```

## Limitations
My approach is limited in a few ways
- It does not consider sales ranges over the new year
- It assumes that the shortest range with the highest total sales is preferable

To build a better model of what constitutes a good period over which to advertise, it would be good to know what had worked previously in terms of advertising. For example, if starting ads a few months before peak seasons were preferable it might be best to find all peaks and calculate ranges to account for advertisement effectivness delay.