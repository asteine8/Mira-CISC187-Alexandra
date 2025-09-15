# Arrays - Honors contract
## Task
You are a data analyst for a company that sells residential computers. The manager shared with you a dataset of the year 2023 sales.

Month	Sales in USD (Millions)
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
A manager is planning an advertising campaign and needs to identify the stretch of consecutive months with the highest total sales. The goal is to target ads immediately before and after that peak run of months.

Using the provided dataset of monthly sales, complete the following:

## a. Approach (no code or pseudocode):
Describe, in plain language, how you would determine which consecutive months produce the highest total sales. Clearly state the inputs, the desired output (start month, end month, and total), and how you’ll handle ties, all-negative values, or multiple peak segments.

## b. Implementation (C++):
Implement your approach so it can detect the highest-sales consecutive months for any similar dataset (not just the given one). Your program should:

Read a sequence of monthly sales values,

Output the start and end month indices (or names) and the maximum total,

Be robust to edge cases (e.g., all negatives, single month, ties).

## c. Pseudocode + Complexity:
Provide pseudocode for your algorithm and analyze its time and space complexity using Big-O notation. Target an O(N) time solution.

## d. Limitations:
Discuss limitations of your approach (e.g., sensitivity to noise/outliers, tie-breaking choices, single peak assumption, lack of seasonality handling, etc.) and when a different method might be preferable.