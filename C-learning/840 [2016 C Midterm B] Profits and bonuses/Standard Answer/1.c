#include <stdio.h>

int main() {
	int n;
	double profit, bonus = 0, tmp = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &profit);

		tmp = profit;
		bonus = 0;

		if (profit > 0) {
			tmp = profit < 100000 ? profit : 100000;
			bonus += tmp * 0.1;
		}
		if (profit > 100000) {
			tmp = profit < 200000 ? profit - 100000 : 100000;
			bonus += tmp * 0.075;
		}
		if (profit > 200000) {
			tmp = profit < 400000 ? profit - 200000 : 200000;
			bonus += tmp * 0.05;
		}
		if (profit > 400000) {
			tmp = profit < 600000 ? profit - 400000 : 200000;
			bonus += tmp * 0.03;
		}
		if (profit > 600000) {
			tmp = profit < 1000000 ? profit - 600000 : 400000;
			bonus += tmp * 0.015;
		}
		if (profit > 1000000) {
			tmp = profit - 1000000;
			bonus += tmp * 0.01;
		}

		printf("%.0lf\n", bonus);
	}
	return 0;
}

