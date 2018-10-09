#include <stdio.h>

int main (void){
	int first=0,left=0,sum=0,num=0;
	scanf ("%d",&num);
	
	if  (num / 10 == 0){
	printf("%d\n",num);
	return 0;
    }	
	
	else while (num / 10 != 0){
		for (first = 0,sum = 0,left = 0;num > 0;++first){
			left = num % 10;
			num /= 10;
			sum += left;	
		}
		num = sum;
	}
	
	printf ("%d\n",sum);
	return 0;
}