#include <cstdio>
#include "LorentzVector.h"

int main() {
  LorentzVector v0;                      // default constructor
  LorentzVector v1(1.5, 2.3, -0.4, 4.2); // constructor with arguments
  LorentzVector v2 =
      LorentzVector(-3.1, 5.6, 1.9, -3.8); // operator=, constructor
  LorentzVector v3 = v1 + v2;              // operator=, operator+
  LorentzVector v4(v1 - v2);               // copy constructor, operator-
  double product = v1 * v2;                // operator*

  v0.Print();
  v1.Print();
  v2.Print();
  v3.Print();
  v4.Print();
  printf("v1*v2 = %f\n", product);

  return 0;
}
