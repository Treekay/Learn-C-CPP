#include <stdio.h>

int main (void) {
	long long num,change = 0;
	char output[1000] = {0};
	int i = 0, t;
	scanf("%lld",&num);
	if (num == 0) {
		printf("0\n");
		return 0;
	}
	while (num != 0) {
		change =  num % 16;
		if (change > 9) output[i] = 55 + change;
		else output[i] = change + 48; 
		num /= 16;
		i++;
	}
	for (t = 0; t < i; t++) {
		printf("%c",output[t]);
	}
	printf("\n");
	return 0;
}