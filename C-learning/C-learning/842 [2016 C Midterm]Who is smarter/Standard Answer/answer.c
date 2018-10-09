#include <stdio.h>
int main() {
  int n, m, x, y, i;
  scanf("%d%d", &n, &m);
  x = n * 365 % 400009;
  y = 1;
  for (i = 0; i < m * 365; i++)
  y = y * 2 % 400009;
  printf("%d\n", (y + 400009 - x) % 400009);
  return 0;
}