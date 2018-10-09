#include <stdio.h>

int main() {
  int num = 0, n = 0;
  scanf("%d%d", &n, &num);

  do {
    printf("%d", num % n);
  } while (num /= n);
  printf("\n");
  return 0;
}
