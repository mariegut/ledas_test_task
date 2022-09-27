#include "Vector3D.h"

Vector3D::Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) { }

Vector3D Vector3D::operator+(Vector3D v) {
    return {this->X + v.X, this->Y + v.Y, this->Z + v.Z};
}

Vector3D Vector3D::operator-(Vector3D v) {
    return {this->X - v.X, this->Y - v.Y, this->Z - v.Z};
}

Vector3D Vector3D::operator*(double a) {
    return {this->X * a, this->Y * a, this->Z * a};
}

double Vector3D::dot(Vector3D v) {
    return v.X * this->X + v.Y * this->Y + v.Z * this->Z;
}

double Vector3D::norm2() {
    return dot(*this);
}

Vector3D Vector3D::cross(Vector3D v) {
    return {
            this->Y * v.Z - v.Y * this->Z,
            this->Z * v.X - v.Z * this->X,
            this->X * v.Y - v.X * this->Y
    };
}

std::ostream &operator<<(std::ostream &out, const Vector3D &v) {
    out << v.X << " " << v.Y << " " << v.Z;
    return out;
}
