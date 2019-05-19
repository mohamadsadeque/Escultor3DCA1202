#include "putbox.h"

PutBox::PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, int _r, int _g, int _b, float _a)
{
    x0 = _x0; x1 = _x1;
    y0 = _y0; y1 = _y1;
    z0 = _z0; z1 = _z1;
    r = _r; b = _b;
    g = _g; a = _a;
}

void PutBox::draw(sculptor3d &t){
    t.setColor(r, g, b, a);

    for(int i = x0; i < x1; i++)
        for(int j = y0; j < y1; j++)
            for (int k = z0; k < z1; k++)
                t.putVoxel(i, j, k);
}
