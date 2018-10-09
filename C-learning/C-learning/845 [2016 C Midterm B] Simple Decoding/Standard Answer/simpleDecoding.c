#include <stdio.h>

int main() {
  int charIndex = 0;
  while (scanf("%3d", &charIndex) == 1) {
    if (charIndex == 0) {
      putchar(' ');
    } else if (1 <= charIndex && charIndex <= 26) {
      putchar(charIndex + 'a' - 1);
    } else if (101 <= charIndex && charIndex <= 126) {
      putchar(charIndex + 'A' - 101);
    }
  }
  putchar('\n');
}
