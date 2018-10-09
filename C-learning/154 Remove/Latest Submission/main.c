#include <stdio.h>

int main (void) {
	int n, i;
	scanf ("%d",&n);
	int array[n+1];
	int length = n;
	for (i = 0; i < n + 1; i++) {
		scanf ("%d",&array[i]);
	}
	for (i = 0; i < n; i++) {
		if (array[i] == array [n]) {
			length--;
		}
	}
	printf("%d\n",length);
	return 0;
}