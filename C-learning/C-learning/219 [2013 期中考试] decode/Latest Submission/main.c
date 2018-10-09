#include <stdio.h>
#include <string.h>

int main (void) {
	char string[81] = {0};
	int i;
	scanf("%s",string);
	for (i = 0; i < strlen(string); i++) {
		if (string[i] > 64 && string[i] < 91){
			printf("%c",155-string[i]);
		}
		else if (string[i] > 96 && string[i] < 123) {
			printf("%c",219-string[i]);
		}
	}
	printf("\n");
	return 0;
}