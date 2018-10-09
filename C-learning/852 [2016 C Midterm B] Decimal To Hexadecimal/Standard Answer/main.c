#include <stdio.h>

int main() {
  int num = 0;
  char hexi[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  scanf("%d", &num);
  do {
    printf("%c", hexi[num % 16]);
  } while (num /= 16);
  printf("\n");
  return 0;
}
