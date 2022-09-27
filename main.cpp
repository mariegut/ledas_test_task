#include <iostream>

class Vector3D
{
    double X{};
    double Y{};
    double Z{};
public:
    Vector3D() = default;
    Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

    Vector3D operator+(Vector3D v){
        return {this->X + v.X, this->Y + v.Y, this->Z + v.Z};
    }
    Vector3D operator-(Vector3D v){
        return {this->X - v.X, this->Y - v.Y, this->Z - v.Z};
    }
    Vector3D operator*(double a){
        return {this->X*a, this->Y*a, this->Z*a};
    }

    double dot(Vector3D v){
        return v.X* this->X + v.Y* this->Y + v.Z* this->Z;
    }
    double norm2(){
        return dot(*this);
    }
    Vector3D cross(Vector3D v){
        return {this->Y * v.Z - v.Y * this->Z, this->Z * v.X - v.Z * this->X, this->X *  v.Y - v.X * this->Y};
    }
    void print(){
        std::cout << this->X << " " << this->Y<< " "<< this->Z << std::endl;
    }

};


class Segment3D
{
public:
    Segment3D() = default;
    Segment3D(const Vector3D &start, const Vector3D &anEnd) : start(start), end(anEnd) {}

    Vector3D end{};
    Vector3D start{};
};

Vector3D Intersect(Segment3D segment1, Segment3D segment2)
{
    Vector3D a = segment1.end - segment1.start;
    Vector3D b = segment2.end - segment2.start;
    Vector3D c = segment2.start - segment1.start;

    if(c.dot(a.cross(b)) != 0.0) {
        std::cout << "Segments don't intersect" << std::endl;
        return {};
    }

    double s = (c.cross(b)).dot(a.cross(b))/(a.cross(b)).norm2();
    double t = (c.cross(a)).dot(a.cross(b))/(a.cross(b)).norm2();

    if ((s >= 0.0 && s <= 1.0) && (t >= 0.0 && t <= 1.0)){
        return segment1.start + a*s;
    }
    std::cout << "Segments don't intersect" << std::endl;
    return {};
}

int main() {
    Segment3D segment1{{3,0,6},{1,2,5}}, segment2{{2,1,7},{2,1,2}};
    Vector3D result_vector = Intersect(segment1, segment2);
    result_vector.print();
    return 0;
}


