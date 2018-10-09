#include<stdio.h>
int main() {
    int n, a[105], i, t, min, pi = 0, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n-1; i++) {          
        min = i;
        for (j = i + 1; j < n; j++)
        if (a[min] > a[j])
        min = j;
        if (min != i) {
            t = a[min];
            a[min] = a[i];
            a[i] = t;
        }
    }
    if (n % 3 == 0) {            
        for (i = 0; i < n; i += 3) {
            pi += a[i];
        }
    }
    else if (n % 3 == 1) {
        for (i = 1; i < n; i += 3) {
            pi += a[i];
        }
    }
    else if (n % 3 == 2) {
        for (i = 2; i < n; i += 3) {
            pi += a[i];
        }
    }
    printf("%d\n", pi);
    return 0;
}