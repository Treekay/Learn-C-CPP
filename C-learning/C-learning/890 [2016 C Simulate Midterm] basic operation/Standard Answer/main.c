#include <stdio.h>
#include <math.h>
int main() {
    int a, b;
    double result;
 
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);
    printf("%d\n", a - b);
    printf("%d\n", a * b);
    if (b != 0)
        printf("%.2lf\n", a * 1.0 / b);
    else
        printf("Error\n");
    printf("%.2lf\n", sqrt(a));
 
    return 0;
}
