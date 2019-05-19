#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"

using namespace std;

class PutVoxel : public FiguraGeometrica
{
    int x, y, z, r, g, b;
    float a;

public:
    PutVoxel(int _x, int _y, int _z, int _r, int _g, int _b, float _a);
    void draw(sculptor3d &t);
};

#endif // PUTVOXEL_H
