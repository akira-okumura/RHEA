#include <cstdio>
#include "Vector3D.h"

int main()
{
  Vector3D v0; // default constructor
  Vector3D v1(1.5, 2.3, -0.4); // constructor with arguments
  Vector3D v2 = Vector3D(-3.1, 5.6, 1.9); // operator=, constructor
  Vector3D v3 = v1 + v2; // operator=, operator+
  Vector3D v4(v1 - v2); // copy constructor, operator-
  double product = v1*v2; // operator*

  v0.Print();
  v1.Print();
  v2.Print();
  v3.Print();
  v4.Print();
  printf("v1*v2 = %f\n", product);
  
  return 0;
}
