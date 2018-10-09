#include <stdio.h>
#include <string.h>

int main (void) {
	char ch;
	while (scanf("%c",&ch) != EOF) {
		if (ch == ' ') printf("000");
		else if (ch > 96 && ch < 123) printf("%03d",ch-96);
		else if (ch > 64 && ch < 91) printf("%03d",ch+36);
	}
 	printf("\n");
	return 0;
}