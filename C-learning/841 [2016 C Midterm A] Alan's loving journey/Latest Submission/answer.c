#include <stdio.h>

int main (void) {
	int N = 0, V = 0;
	int judge = 0;
	int max = 0;
	int distance = 0, max_oil = 0;
	scanf("%d%d",&N,&V);
	max = V;
	int i;
	for (i = 0; i < N; i++) {
		scanf ("%d%d",&distance,&max_oil);
		V -= distance;
		if (V >= 0) judge++;
		else judge = -100;
		if (V + max_oil > max) V = max;
		else V += max_oil;
	}
	if (judge == N) printf("Yes\n");
	else printf("No\n");
	
	return 0;
}