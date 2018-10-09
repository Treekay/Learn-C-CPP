#include <stdio.h>

int main (void) {
	int N, x, y, sum = 1,test = 0;
	scanf ("%d %d %d",&N,&x,&y);
	int num[51] = {0};
	printf ("%d ",x);
	num[x] = 1;
	while (sum != N) {
		x ++;
		x %= N;
		if (num[x] == 0) {
			test++;
		}
		if (test == y) {
			test = 0;
			printf("%d ",x);
			num[x] = 1;
			sum++;
		}
	}
	printf("\n");
	return 0;
} 