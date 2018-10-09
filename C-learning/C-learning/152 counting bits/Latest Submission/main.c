#include <stdio.h>
int main(void)
{
	int num;
	int i;
	int a,b,c;
	int t;
	scanf("%d",&num);
	for(i=0;i<=num;i++){
		a=i/2;
		b=i%2;
		
	    if(b!=0)
	    c++;
	    else
	    c=0;
	    
	    while(a/2!=0)
		{
		b=a%2;	
		a/=2;
		if(b!=0)
		c++;
		else
		c=c;
		}
		if(a==1)
		c++;

		printf("%d",c);
		if(i!=num)
		printf(",");
		else
		printf("\n");
		c=0;a=0;b=0;
	}
	return 0;
}