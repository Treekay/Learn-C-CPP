#include<stdio.h>
int main() {
    char ch;
 
    while ((ch = getchar()) != '\n') {
        if (ch == ' ' || ch == '\t')
            continue;
 
        if (ch >= 65 && ch <= 90)
            ch += 32;
 
        printf("%c", ch);
    }
    return 0;
}
