#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int i, j, k;
	for (i = a; i <= b; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d*%d=%d%s", j, i, j*i, j == i?"\n":"  ");
		}
	}
	return 0;
}
