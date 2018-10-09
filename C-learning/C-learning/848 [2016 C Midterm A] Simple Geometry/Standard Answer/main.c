#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main() {
  double area = 0.0;
  scanf("%lf", &area);
  printf("%.3f %.3f %.3f\n", sqrt(area), sqrt(area / PI), 0.5 * area * PI);
}