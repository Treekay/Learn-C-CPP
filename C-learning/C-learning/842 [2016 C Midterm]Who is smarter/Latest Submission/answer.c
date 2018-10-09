#include <stdio.h>

int main() {
	int n, m;
 	long long int x = 0, y = 1;
	int i;
	int sum;
	scanf ("%d%d",&n,&m);
	x = n*365;
	for (i = 0; i < m*365; i++) {
		y *= 2;
		if (y % 400009 > x ||y*2 < 0) y %= 400009;
	}
	if (m == 0) y = 400010;
	x %= 400009;
	sum = (y-x)%400009;
	printf("%d\n",sum);
	return 0;
}