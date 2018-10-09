#include <stdio.h>

int main (void) {
	int n;
	scanf ("%d",&n);
	int a, b, i , t =0;
	int poi = 0;
	for (i = 0; i < n; i++) {
		poi = 0;
		scanf ("%d%d",&a,&b);
		while (a != 0) {
			poi = a % 10 + poi *10;
			if (poi == 0) t++;
			a /= 10;
		}
		while (t != 0) {
			printf("0");
			t--;
		}
		printf ("%d %d\n",poi,poi%b);
	}
	return 0;
}