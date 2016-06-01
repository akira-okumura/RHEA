class Vector3D(object):
    def __init__(self, x = 0., y = 0., z = 0.):
        self.x = x
        self.y = y
        self.z = z

    def __str__(self):
        return "(x, y, z) = (%f, %f, %f)" % (self.x, self.y, self.z)

    def __add__(self, other):
        return Vector3D(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Vector3D(self.x - other.x, self.y - other.y, self.z - other.z)
    
    def __mul__(self, other):
        return self.x*other.x + self.y*other.y + self.z*other.z

class LorentzVector(Vector3D):
    def __init__(self, x = 0., y = 0., z = 0., t = 0.):
        self.Vector3D(x, y, z)
        self.t = t

    def __str__(self):
        return "(x, y, z, t) = (%f, %f, %f, %f)" % (self.x, self.y, self.z,
                                                   self.t)

    def __add__(self, other):
        return LorentzVector(self.x + other.x, self.y + other.y,
                             self.z + other.z, self.t + other.t)

    def __sub__(self, other):
        return LorentzVector(self.x - other.x, self.y - other.y,
                             self.z - other.z, self.t - other.t)
    
    def __mul__(self, other):
        return self.x*other.x + self.y*other.y + self.z*other.z - self.t*other.t

if __name__ == "__main__":
    v0 = Vector3D() # __init__ with default arguments
    v1 = Vector3D(1.5, 2.3, -0.4) # with arguments
    v2 = Vector3D()
    v2 = Vector3D(-3.1, 5.6, 1.9) # operator=
    v3 =  v1 + v2 # operator=, operator+
    v4 =  v1 - v2
    product = v1 * v2
    print(v0)
    print(v1)
    print(v2)
    print(v3)
    print(v4)
    print("v1*v2 = %f" % product)
