#include "cutvoxel.h"

CutVoxel::CutVoxel(int _x, int _y, int _z, int _r, int _g, int _b, float _a)
{
    x = _x; y = _y; z = _z; r = _r;
    g = _g; b = _b; a = _a;
}

void CutVoxel::draw(sculptor3d &t){
    t.cutVoxel(x, y, z);
}
