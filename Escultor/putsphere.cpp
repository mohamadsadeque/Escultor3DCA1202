#include "putsphere.h"

PutSphere::PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, int _r, int _g, int _b, float _a)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
    r = _r; b = _b;
    g = _g; a = _a;
}

void PutSphere::draw(sculptor3d &t){
    t.setColor(r, g, b, a);
    t.putSphere(xcenter, ycenter, zcenter, radius);
}
