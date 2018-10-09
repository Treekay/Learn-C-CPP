#include <stdio.h>
int main(void)
{
	int t;
	scanf("%d",&t);
	int i=0,j=0;
	for(i=1;i<=t;++i){
		
		for(j=1;j<=i;++j){
			printf("*");
		}
		printf("\n");
       
	    }
	return 0;
}