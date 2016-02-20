#include <cstdio>

double min(double v1, double v2);
double max(double v1, double v2);

int main() {
  printf("%f is smaller\n", min(39.2, 48.5));
  printf("%f is larger\n",  max(103.8, -3.2));

  return 0;
}

double min(double v1, double v2) {
  double ret;
  if(v1 < v2){
    ret = v1;
  } else {
    ret = v2;
  }

  return ret;
}

double max(double v1, double v2) {
  return v1 > v2 ? v1 : v2;
}
