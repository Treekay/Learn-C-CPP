#include <stdio.h>
#include <string.h>

int main (void) {
	char num[1000];
	scanf ("%s",num);
	int i, sum = 0;
	printf("%d ",strlen(num));
	for (i = 0; i < strlen(num); i++) {
		sum += num[i] - '0';
	}
	printf("%d\n",sum);
	return 0;
}