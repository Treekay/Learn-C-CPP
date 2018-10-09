#include <stdio.h>

int  main () {
	int height;
	int num[10000];
	int i = 0, t = 0, m = 0, sum = 0;
	
	scanf("%d%d",&height,&t);
	for(i = 0;i < t;++i) {
	   scanf("%d",&m);
	   num[i] = m;
   }   
	for(i = 0;i < t;++i) {
	if (height >= num[i]) sum++;
   }
	
	printf ("%d\n",sum);
	return 0;
}