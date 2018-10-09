#include<stdio.h>
int main() {
    int length = 0;
    int i, j;
    int x;
    int flag = 0;
    int k = 0;
    double threshold = 0;
    scanf("%d%lf", &x, &threshold);
    for (i = 1; i <= x; i++) {
        for (j = 1; j < i; j++) {
            flag = 0;
            for (k = 2; k <= j; k++) {
                if (j != 1) {
                    if ((j % k == 0) && (i % k == 0)) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0 && 1.0 * j / i <= threshold) {
                printf("%d/%d\n", j, i);
            }
        }
    }
    return 0;
}
