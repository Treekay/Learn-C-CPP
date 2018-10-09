# Find Actual Number of Miles


You are given a car odometer which displays the miles traveled as an integer. The odometer has a defect, however: it proceeds from the digit 2 to the digit 4 and from the digit 7 to the digit 9, always skipping over the digit 3 and 8. This defect shows up in all positions (the one's, the ten's, the hundred's, etc.). For example, if the odometer displays 15229 and the car travels one mile, odometer reading changes to 15240 (instead of 15230).

## Input

Each line of input contains a positive integer in the range 1..999999999 which represents an odometer reading. (Leading zeros will not appear in the input.) The end of input is indicated by a line containing a single 0. You may assume that no odometer reading will contain the digit 3 and 8.

## Output

Each line of input will produce exactly one line of output, which will contain: the odometer reading from the input, a colon, one blank space, and the actual number of miles traveled by the car. 

## Sample Input

15

250

0

## Sample Output

15: 12

250: 160


