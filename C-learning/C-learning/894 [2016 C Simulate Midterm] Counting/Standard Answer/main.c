#include <stdio.h>

int main() {
  int x;
  int digits = 0;
  int d_sum = 0;
  while(scanf("%1d", &x) != EOF) {
    digits++;
    d_sum += x;
  }
  printf("%d %d\n", digits, d_sum);
  return 0;
}
