#include "cutellipsoid.h"
#include "math.h"

CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter,
                           int _rx, int _ry, int _rz)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx = _rx;
    ry = _ry;
    rz = _rz;
}

void CutEllipsoid::draw(sculptor3d &t){
    for(int i=xcenter-rx; i< xcenter+rx; i++)
        for(int j=ycenter-ry; j< ycenter+ry; j++)
            for(int k=zcenter - rz; k< zcenter + rz; k++){
                float calc1 = ((float)pow((i-xcenter),2)/(pow(rx,2)));
                float calc2 = ((float)pow((j-ycenter),2)/(pow(ry,2)));
                float calc3 = ((float)pow((k-zcenter),2)/(pow(rz,2)));
                if ((calc1 + calc2 + calc3) <=1.0) {
                   t.cutVoxel(i, j, k);
                }
            }
}
