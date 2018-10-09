#include <stdio.h>
#include <math.h>

int main (void) {
	int n, x, C = 0, D = 0;
	scanf ("%d%d",&n,&x);
	int i, output = 0;
	for (i = 0; i < n; i++) {
		scanf ("%d%d",&C,&D);
		output += C*D*pow(x,D-1);
	}
	printf ("%d\n",output);
	return 0;
}