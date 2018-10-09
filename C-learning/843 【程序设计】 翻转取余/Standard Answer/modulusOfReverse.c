#include <stdio.h>

int main() {
  int caseNum = 0, tmpDigit = 0;
  int result = 0, divisor = 0, tensMod = 0;
  char c = 0;
  scanf("%d", &caseNum);
  for (int caseIndex = 0; caseIndex != caseNum; ++caseIndex) {
    tensMod = 1;
    scanf("%d%1d", &divisor, &result);
    result = result % divisor;
    for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) {
      tmpDigit = c - '0';
      tensMod = (10 * tensMod) % divisor;
      result = (result + tmpDigit * tensMod) % divisor;
    }
    printf("%d\n", result);
  }
  return 0;
}
