#ifndef LORENTZ_VECTOR
#define LORENTZ_VECTOR

#include "Vector3D.h"

class LorentzVector : public Vector3D {
 private:
  double fT;

 public:
  LorentzVector();
  LorentzVector(double x, double y, double z, double t);
  LorentzVector(const LorentzVector& other);
  virtual ~LorentzVector();

  virtual double T() const {return fT;}
  virtual void   Print() const;

  LorentzVector& operator=(const LorentzVector& other);
  LorentzVector  operator+(const LorentzVector& other);
  LorentzVector  operator-(const LorentzVector& other);
  double         operator*(const LorentzVector& other);
};

#endif  // LORENTZ_VECTOR
