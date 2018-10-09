#include <stdbool.h>
#include <stdio.h>

bool isAlp(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
bool isNum(char ch) { return (ch >= '0' && ch <= '9'); }

bool isUnderline(char ch) { return (ch == '_'); }

int main() {
  int n;
  scanf("%d", &n);
  char ch;
  getchar();
  while (n--) {
    bool flag = true;
    int count = 0;
    while (1) {
      ch = getchar();
      ++count;
      if (ch == '\n') {
        break;
      }
      if (count == 1) {
        if (!(isUnderline(ch) || isAlp(ch))) {
          flag = false;
        }
      } else {
        if (!(isUnderline(ch) || isAlp(ch) || isNum(ch))) {
          flag = false;
        }
      }
    }
    if (flag) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
