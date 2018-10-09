#include <stdio.h>

int main() {
  int caseNum = 0, input = 0, inputLength = 0, mod = 0, reverse = 0;
  scanf("%d", &caseNum);
  for (int caseIndex = 0; caseIndex != caseNum; ++caseIndex) {
    input = 0, inputLength = 0, mod = 0, reverse = 0;
    for (scanf("%d%d", &input, &mod); input > 0; input /= 10) {
      reverse = reverse * 10 + input % 10;
      ++inputLength;
    }
    printf("%.*d %d\n", inputLength, reverse, reverse % mod);
  }
  return 0;
}
