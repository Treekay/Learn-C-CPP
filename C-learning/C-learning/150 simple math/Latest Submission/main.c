#include <stdio.h>

int main (){
	int num[10000];
	int i = 0;
	int sum = 0, max=0, min=0;
	double ave;
	while (scanf("%d",&num[i]) != EOF) {
			sum += num[i];
		
			if (i == 0) max =num[i];
			if (max < num[i]) max = num[i];
		
			if (i == 0) min = num[i];
			if (min > num[i]) min = num[i];
		
			i++;
	}
	ave = (double)sum/i;
	printf("%d\n%.2lf\n%d\n%d\n",sum,ave,max,min);
	return 0;
}
