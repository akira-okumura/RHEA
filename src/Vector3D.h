#ifndef VECTOR_3D
#define VECTOR_3D

class Vector3D {
private:
  double fX;
  double fY;
  double fZ;

public:
  Vector3D();
  Vector3D(double x, double y, double z);
  Vector3D(const Vector3D& other);
  virtual ~Vector3D();

  virtual double X() const { return fX; }
  virtual double Y() const { return fY; }
  inline virtual double Z() const;
  virtual void Print() const;

  Vector3D& operator=(const Vector3D& other);
  Vector3D operator+(const Vector3D& other);
  Vector3D operator-(const Vector3D& other);
  double operator*(const Vector3D& other);
};

double Vector3D::Z() const { return fZ; }

#endif // VECTOR_3D
