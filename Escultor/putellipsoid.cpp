#include "putellipsoid.h"
#include "math.h"

PutEllipsoid::PutEllipsoid(int _xcenter, int _ycenter, int _zcenter,
                           int _rx, int _ry, int _rz,
                           int _r,int _g,int _b, int _a)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx = _rx;
    ry = _ry;
    rz = _rz;
    r = _r; g = _g; b = _b; a = _a;
}

void PutEllipsoid::draw(sculptor3d &t){
    t.setColor(r, g, b, a);

    for(int i=xcenter-rx; i< xcenter+rx; i++)
        for(int j=ycenter-ry; j< ycenter+ry; j++)
            for(int k=zcenter - rz; k< zcenter + rz; k++){
                float calc1 = ((float)pow((i-xcenter),2)/(pow(rx,2)));
                float calc2 = ((float)pow((j-ycenter),2)/(pow(ry,2)));
                float calc3 = ((float)pow((k-zcenter),2)/(pow(rz,2)));
                if ((calc1 + calc2 + calc3) <=1.0) {
                   t.putVoxel(i, j, k);
                }
            }
}
