# Arrays - Honors contract

## Approach
1. Calculate average value of array
2. Calculate distance from average for each month
3. Determine valid, continuous groups
4. Calculate sum of distances from average for each group to get group score
5. Select highest score

Possible Edge Cases and Solutions:
- All months have the same sales
  - 
- Negative sales numbers
  - Negative sales numbers are invalid
- Not all months provided in dataset
  - We can't make assumptions on data we don't have so 
- Tied groups
  - Select group with the least months. This reduces advertising costs
  - For groups with the same number of months, select the first one to pre-load costs for flexibility near the end of the fiscal year
