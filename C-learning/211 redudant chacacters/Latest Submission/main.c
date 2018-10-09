#include <stdio.h>
#include <string.h>

int main (void) {
	char input[100] = {0};
	char output[100] = {0};
	scanf ("%s",input);
	int i = 0, t = 0, s = 0, m = 0;
	int length = strlen(input);
	for (i = 0; i < length; i++) {
		s = 0;
		for (m = 0; m < t; m++) {
			if (output[m] != input[i]) {
				s++;
			}
		}
		if (s == t) {
			output[t] = input[i];
			t++;
		}
	}
	printf ("%s\n",output);
	return 0;
}