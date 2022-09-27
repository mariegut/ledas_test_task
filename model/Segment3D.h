#ifndef LEDAS_TEST_TASK_SEGMENT3D_H
#define LEDAS_TEST_TASK_SEGMENT3D_H


#include "Vector3D.h"

class Segment3D {
public:

    Segment3D() = default;
    Segment3D(const Vector3D &start, const Vector3D &anEnd);

    Vector3D end;
    Vector3D start;

};


#endif //LEDAS_TEST_TASK_SEGMENT3D_H
