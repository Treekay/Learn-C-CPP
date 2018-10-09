#include <stdio.h>

int main() {
  for (char c = getchar(); c != '\n' && c != EOF; c = getchar()) {
    if (c == ' ') {
       printf("000");
    } else if ('A' <= c && c <= 'Z') {
       printf("1%.2d", c - 'A' + 1);
    } else if ('a' <= c && c <= 'z') {
      printf("0%.2d", c - 'a' + 1);
    } else {
      printf("[Unexpected char %d]", c);
    }
  }
  putchar('\n');
}
