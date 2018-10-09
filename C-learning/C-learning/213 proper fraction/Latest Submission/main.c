#include <stdio.h>

int main (void) {
	int N;
	float M;
	scanf ("%d %f",&N,&M);
	int i, j, t;
	for (j = 1; j <= N; j++) {
		for (i = 1; i < N; i++) {
			for (t = j; t > 0; t--) {
				if (j % t == 0&& i % t == 0) break;
			}
			if (t != 1) continue;
			if (i*1.0/j < M) printf("%d/%d\n",i,j);
		}
	}
	return 0;
}