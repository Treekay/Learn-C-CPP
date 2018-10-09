#include <stdio.h>
#include <math.h>

int main (void) {
	int n;
	double s = 0, x = 0;
	int num[100] = {0};
	scanf ("%d",&n);
	int i;
	for (i = 0; i < n; i++) {
		scanf ("%d",&num[i]);
		x += num[i];
	}
	x = x / n;
	for (i = 0; i < n; i++) {
		s += ((double)num[i] - x)*((double)num[i] - x);
	}
	s /= n;
	s = sqrt(s);
	printf("%.4lf\n",s);
	return 0;
}