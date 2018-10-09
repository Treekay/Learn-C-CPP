#include <stdio.h>
#include <ctype.h>
int main() {
 char ch;
 while((ch = getchar()) != '\n') {
  if (ch != ' ' && ch != '\t') {
   if (islower(ch)) putchar(ch);
   else  putchar(ch + 32);
   }
  }
 return 0;
}