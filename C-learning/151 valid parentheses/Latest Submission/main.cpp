#include <stdio.h>
#include <string.h>

int main (){
	char poi[1000] = {0};
	int num[1000] = {0}; 
	int i, t, len;
	scanf ("%s",poi);
	len = strlen(poi);
	if (len % 2 != 0) {
		printf("False\n");
		return 0;
	}
	for (i = 0; i < len; i++) {
		for (t = i + 1; t < len; t += 2) {
			if (poi[t] == poi[i] + 1||poi[t] == poi[i] + 2) {
				num[i] = 1;
				num[t] = 1;
			}
		}
	}
	for (i = 0; i < len; i++) {
		if (num[i] == 0) {
			printf("False\n");
			return 0;
		}
	}
	if (num[i - 1] == 1) printf("True\n");
	return 0;
} 