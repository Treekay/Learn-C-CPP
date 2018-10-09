#include <stdio.h>
#include <string.h>

int main (void) {
	int n = 0, i = 0, t = 0, s = 0;
	int num = 0;
	int len = 0;
	long long reminder = 0, add = 0;
	char divisior, ch;
	scanf ("%d",&n);
	for (i = 0; i < n; i++) {
		reminder = 0;
		s = 0;
		scanf ("%d",&num);
		getchar();
		while ((ch = getchar()) != '\n') {
			if (ch == ' ') continue;
			divisior = ch;
			add = divisior - '0';
			for (t = 0; t < s;t++) {
				add *= 10;
				add %= num;
			}
			reminder += add;
			reminder %= num;
			s++;
		}
		printf("%d\n",reminder%num);
	}
	return 0;
}