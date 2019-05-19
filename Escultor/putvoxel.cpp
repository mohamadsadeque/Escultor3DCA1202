#include "putvoxel.h"

PutVoxel::PutVoxel(int _x, int _y, int _z, int _r, int _g, int _b, float _a)
{
    x = _x; y = _y; z = _z; r = _r;
    g = _g; b = _b; a = _a;
}

void PutVoxel::draw(sculptor3d &t){
    t.setColor(r, g, b, a);
    t.putVoxel(x, y, z);
}
