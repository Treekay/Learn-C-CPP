#include <stdio.h> 
#include <string.h>

int main () {
	char num[1000] = {0};
	int i, t;
	int sum = 0;
	scanf("%s",num);
	for (i = 0; i < strlen(num); i+=3) {
		for (t = 0; t < 3; t++) {
			sum = sum*10 + num[i+t] - '0';
		}
		if (sum == 0) printf(" ");
		else if (sum > 0 && sum < 27) printf("%c",sum+96);
		else if (sum > 100 && sum < 127) printf("%c",sum-36);
		sum = 0;
	} 
	printf("\n");
	return 0;
}