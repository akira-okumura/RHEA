#include "LorentzVector.h"
#include <cstdio>
#include <cmath>

LorentzVector::LorentzVector() : Vector3D(), fT(0) {}

LorentzVector::LorentzVector(const LorentzVector& other)
    : Vector3D(other), fT(other.fT) {}

LorentzVector::LorentzVector(double x, double y, double z, double t)
    : Vector3D(x, y, z), fT(t) {}

LorentzVector::~LorentzVector() {}

void LorentzVector::Print() const {
  printf("(x, y, z, t) = (%lf, %lf, %lf, %lf)\n", X(), Y(), Z(), fT);
}

LorentzVector& LorentzVector::operator=(const LorentzVector& other) {
  if (this != &other) {
    Vector3D::operator=(other);
    fT = other.fT;
  }

  return *this;
}

LorentzVector LorentzVector::operator+(const LorentzVector& vec) {
  return LorentzVector(X() + vec.X(), Y() + vec.Y(), Z() + vec.Z(),
                       fT + vec.fT);
}

LorentzVector LorentzVector::operator-(const LorentzVector& vec) {
  return LorentzVector(X() - vec.X(), Y() - vec.Y(), Z() - vec.Z(),
                       fT - vec.fT);
}

double LorentzVector::operator*(const LorentzVector& vec) {
  return X() * vec.X() + Y() * vec.Y() + Z() * vec.Z() - fT * vec.fT;
}
