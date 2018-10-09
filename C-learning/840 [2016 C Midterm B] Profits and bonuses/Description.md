# [2016 C Midterm B] Profits and bonuses

# Description

There are some rule between profit P and bonus B in a company

1. When P <= 100,000, a employee can get 10% of the profit as his bonus

2. When 100,000 < P <= 200,000, it is divided into two parts. For the part < 100,000, the rule is the same as THE RULE 1. For the part higher than 100,000, the employee can add 7.5% of this part to his bonus.

3. When 200,000 < P <= 400,000, it is divided into three parts, and for the part higher than 200,000, the employee can add 5% of this part to his bonus.

4. When 400,000 < P <= 600,000, it is divided into four parts, and for the part higher than 400,000, the employee can add 3% of this part to his bonus.

5. When 600,000 < P <= 1,000,000, it is divided into five parts, and for the part higher than 600,000, the employee can add 1.5% of this part to his bonus.

6. When 1,000,000 < P, it is divided into six parts, and for the part higher than 1,000,000, the employee can add 1% of this part to his bonus.

Given P, you're asked to answer the corresponding B

## **For example**, if one employee gets Profit 250,000(100,000+100,000+50,000), he will get 100,000\*10% + 100,000\*7.5% + 50,000\*5% as his bonus.

# Input

1. the first line is **n**, meaning the number of input

2. the next n line are all profit P

# Output

output the corresponding B according to the profit P

# Sample Input
```
3
910342
1578879
463236

```

# Sample Output
```
38155
45289
29397

```
