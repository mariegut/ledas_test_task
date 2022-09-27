#include <iostream>
#include "model/Vector3D.h"
#include "model/Segment3D.h"

Vector3D Intersect(Segment3D segment1, Segment3D segment2);

int main() {
    //example
    Segment3D segment1{{3, 0, 6},
                       {1, 2, 5}}, segment2{{2, 1, 7},
                                            {2, 1, 3}};
    Vector3D result_vector = Intersect(segment1, segment2);
    std::cout << result_vector;
    return 0;
}

Vector3D Intersect(Segment3D segment1, Segment3D segment2) {
    Vector3D a = segment1.end - segment1.start;
    Vector3D b = segment2.end - segment2.start;
    Vector3D c = segment2.start - segment1.start;

    if (c.dot(a.cross(b)) != 0.0) {
        std::cout << "Segments don't intersect" << std::endl;
        return {};
    }

    double s = (c.cross(b)).dot(a.cross(b)) / (a.cross(b)).norm2();
    double t = (c.cross(a)).dot(a.cross(b)) / (a.cross(b)).norm2();

    if ((s >= 0.0 && s <= 1.0) && (t >= 0.0 && t <= 1.0)) {
        return segment1.start + a * s;
    }
    std::cout << "Segments don't intersect" << std::endl;
    return {};
}


