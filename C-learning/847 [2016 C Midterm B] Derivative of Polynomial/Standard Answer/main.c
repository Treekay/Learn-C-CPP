#include <math.h>
#include <stdio.h>

int main() {
  int size = 0, x = 0;
  long degree = 0, coefficient = 0, derivative = 0;
  scanf("%d%d", &size, &x);

  for (int i = 0; i < size; i++) {
    scanf("%ld%ld", &coefficient, &degree);
    if (degree) derivative += coefficient * degree * (int)(pow(x, degree - 1));
  }
  printf("%ld\n", derivative);
}