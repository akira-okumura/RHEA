#include <cstdio>

int triple(int v);
double triple(double v);

int main() {
  int before_i = 15;
  int after_i  = triple(before_i);

  printf("Before: %d\n", before_i);
  printf("After : %d\n", after_i);

  double before_d = 16.9;
  double after_d  = triple(before_d);

  printf("Before: %f\n", before_d);
  printf("After : %f\n", after_d);

  return 0;
}

int triple(int v) {
  return 3*v;
}

double triple(double v) {
  return 3*v;
}
