#include <stdio.h>

int main (void) {
	int test_time, money, time, left, cost, num;
	scanf("%d",&test_time);
	int i, t;
	for (i = 0; i < test_time; i++) {
		scanf ("%d %d",&money,&time);
		left = money;
		for (t = 0; t < time; t++) {
			scanf ("%d %d",&cost,&num);
			left -= (cost*num);
		}
		if (left >= 0) printf("%d\n",left);
		else printf("Not enough\n");
	}
	return 0;
}