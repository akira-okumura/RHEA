#include <cstdio>

double pi(int n);

int main() {
  for(int i = 1; i <= 100; i++){
    printf("n = %d: pi = %f\n", i, pi(i));
  } // i

  return 0;
}

double pi(int n) {
  int total = 0; // number of points inside a unit circle
  double d = 1./n; // grid length of points

  for(int j = -n; j < n; j++){
    double y = d*(j + 0.5);
    for(int i = -n; i < n; i++){
      double x = d*(i + 0.5);
      if(x*x + y*y < 1.){ // check if (x, y) exists inside a unit circle
        total += 1;
      } // if
    } // i
  } // j

  return total/double(n*n);
}
