#include <stdio.h>

int main (void) {
	int num;
	long long input, output = 0;
	int i;
	int ten = 0;
	scanf ("%d%lld",&num,&input);
	while (input != 0) {
		output = output * 10 + input % num;
		if (output == 0) ten++;
		input /= num;
	}
	for (i = 0; i < ten; i++) {
		printf("0");
	}
	printf("%lld\n",output);
	return 0;
}