#include <cstdio>

int triple(int v) {
  return 3*v;
}

int main() {
  int before = 15;
  int after  = triple(before);

  printf("Before: %d\n", before);
  printf("After : %d\n", after);

  return 0;
}
