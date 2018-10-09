#include <stdio.h>

int main (void) {
	int n, i;
	float profit = 0, bonus = 0;
	scanf ("%d",&n);
	for (i = 0; i < n; i++) {
		scanf ("%f",&profit);
		if (profit <= 100000) bonus = profit * 0.1;
		else if (profit > 100000&&profit <= 200000) bonus = 10000 + (profit - 100000) * 0.075;
		else if (profit > 200000&&profit <= 400000) bonus = 10000 + 7500 + (profit - 200000) * 0.05;
		else if (profit > 400000&&profit <= 600000) bonus = 10000 + 7500 + 10000 + (profit - 400000) * 0.03;
		else if (profit > 600000&&profit <= 1000000) bonus = 10000 + 7500 + 10000 + 6000 + (profit - 600000) * 0.015;
		else if (profit > 1000000) bonus = 10000 + 7500 + 10000 + 6000 + 6000 + (profit - 1000000) * 0.01;
		printf("%.0f\n",bonus);
	}
	return 0;
}