#include <stdio.h>

int main (void){
	int year;
	int num;
	int t;
	scanf("%d",&num);
	for(t=0;t<num;++t){
		scanf("%d",&year);
		if((year%4==0&&year%100!=0)||(year%400==0)) 
		printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}