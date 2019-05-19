#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"

using namespace std;

class CutVoxel : public FiguraGeometrica
{
    int x, y, z, r, g, b;
    float a;

public:
    CutVoxel(int _x, int _y, int _z, int _r, int _g, int _b, float _a);
    void draw(sculptor3d &t);
};

#endif // CUTVOXEL_H
