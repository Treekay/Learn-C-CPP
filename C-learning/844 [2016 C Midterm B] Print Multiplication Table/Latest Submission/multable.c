#include <stdio.h>

int main (void) {
	int a, b;
	scanf ("%d%d",&a,&b);
	int i, t;
	for (i = a; i <= b; i++) {
		for (t = 1;t <= i;t++) {
			printf("%d*%d=%d",t,i,t*i);
			if (t + 1 <= i) printf("  ");
			else printf("\n");
		}
	}
	return 0;
}