# Operator Overloading 2

# Description
 Design a safe calculator by overloading the operator`++` and `--`. The counter is not allowed to be less than 0 or greater than 99. If it is out of the range, the counter will be set to 0.  
You need to implement only the prefix one, i.e. "++I".
 
main program:  
**PS**: you should submit the whole implementation of class Calculator.
``` 
//You need to implement the class Calculator. 
#include <iostream>
using namespace std;
 
class Calculator
{
public:
	Calculator(int v = 0){value = v;}

	//...
 
private:
	unsigned int value;
 
};
 

 
int main(){
	int value;
	cin>>value;
	Calculator counter(value);
	int i;
	for (i = 0;i < 5;i++)
	{
		++counter;

		
	}
	for (i = 0;i <= 7;i++)
	{
		--counter;

	} 
}
```

# Input
```
3
```

# Output
```
counter = 4
counter = 5
counter = 6
counter = 7
counter = 8
counter = 7
counter = 6
counter = 5
counter = 4
counter = 3
counter = 2
counter = 1
counter = 0
```