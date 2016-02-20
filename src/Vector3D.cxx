#include "Vector3D.h"
#include <cstdio>

Vector3D::Vector3D() : fX(0), fY(0), fZ(0) {}

Vector3D::Vector3D(double x, double y, double z)
  : fX(x), fY(y), fZ(z) {}

Vector3D::Vector3D(const Vector3D& other)
  : fX(other.fX), fY(other.fY), fZ(other.fZ) {}

Vector3D::~Vector3D() {}

void Vector3D::Print() const {
  printf("(x, y, z) = (%lf, %lf, %lf)\n", fX, fY, fZ);
}

Vector3D& Vector3D::operator=(const Vector3D& other) {
  if (this != &other) {
    fX = other.fX;
    fY = other.fY;
    fZ = other.fZ;
  }

  return *this;
}

Vector3D Vector3D::operator+(const Vector3D& other) {
  return Vector3D(fX + other.fX, fY + other.fY, fZ + other.fZ);
}

Vector3D Vector3D::operator-(const Vector3D& other) {
  return Vector3D(fX - other.fX, fY - other.fY, fZ - other.fZ);
}

double Vector3D::operator*(const Vector3D& other) {
  return fX*other.fX + fY*other.fY + fZ*other.fZ;
}
