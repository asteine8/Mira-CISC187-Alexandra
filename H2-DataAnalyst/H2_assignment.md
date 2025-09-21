# Arrays - Honors contract

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
MonthStart MonthEnd AverageSalesPerMonth
Jan Mar 52
```

### Command Line Arguments
`-n [number of ranges] => Changes the number of optimal ranges that are returned`
`-m [max months in range] => Changes maximum number of months in a range`


### General Algorithm for Computing Optimal Advertisement Months
1. Calculate average value of array
2. Calculate distance from average for each month
3. Determine valid, continuous groups
4. Calculate sum of distances from average for each group to get group score
5. Select highest scoring group


**Other ideas:**
- Trend fitting: Calculate fit to standard distribution graph
  - Maybe not since sales data likely does not fit STD DIST
- 

Possible Edge Cases and Solutions:
- All months have the same sales
  - Return an error code
- Negative sales numbers
  - Negative sales numbers are invalid
- Not all months provided in dataset
  - We can't make assumptions on data we don't have so 
- Tied groups
  - Select group with the least months. This reduces advertising costs
  - For groups with the same number of months, select the first one to pre-load costs for flexibility near the end of the fiscal year
