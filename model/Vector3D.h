#ifndef LEDAS_TEST_TASK_VECTOR3D_H
#define LEDAS_TEST_TASK_VECTOR3D_H


#include <iostream>

class Vector3D {
    double X;
    double Y;
    double Z;
public:

    Vector3D() = default;
    Vector3D(double x, double y, double z);

    Vector3D operator+(Vector3D v);
    Vector3D operator-(Vector3D v);
    Vector3D operator*(double a);

    double dot(Vector3D v);
    double norm2();
    Vector3D cross(Vector3D v);

    friend std::ostream& operator<<(std::ostream &out, const  Vector3D& v);

};


#endif //LEDAS_TEST_TASK_VECTOR3D_H
