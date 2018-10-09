# [2016 C Midterm A] Alan's loving journey

## Description

&emsp;Alan recently have got a girl friend. So he planned a loving travel with N cities on a straight line. 

&emsp;But he has only a car with a fixed volumn tank(固定容积的油箱).

&emsp;Fortunately, every city has an oil station for him to fill his tank. 

&emsp;He starts his journey from city 0,1,2,3,..., N-1. When he starts, **the tank is filled**. 

&emsp;**One unit of distance need one unit of oil !**


## Input

&emsp;N, V 

> 0< N <=100 and 10< V <=500
> 
> means that Alan will **visit N cities** and begin his journey with **V unit of oil**

> then follow N lines with：

&emsp;distance, max_oil

> 0 < distance <= 800, 0 < max_oil <= 500
> 
> means distance bewteen two cities and the max unit of oil that can be filled in this station
    
## Output

You just only have to print Yes or No ('\n' is necessary)

 > means whether Alan can finish the journey.




## Sample input:

3 30

10 20

20 10

20 0

## Sample output:

Yes

 

## Sample input:

3 40

10 300

45 40

10 0

## Sample output:

No
