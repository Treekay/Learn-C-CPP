#include <stdio.h>
 
int main(void) {
    int n, year;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &year);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
