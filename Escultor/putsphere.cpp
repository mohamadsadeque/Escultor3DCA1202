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

    for(int i=xcenter-radius; i< xcenter+radius; i++)
        for(int j=ycenter-radius; j< ycenter+radius; j++)
            for(int k=zcenter-radius; k< zcenter+radius; k++)
            {
                float calc1 = ((float)pow((i-xcenter),2)/(pow(radius,2)));
                float calc2 = ((float)pow((j-ycenter),2))/(float)(pow(radius,2));
                float calc3 = (((float)pow((k-zcenter),2))/(float)(pow(radius,2)));
                if ((calc1 + calc2 + calc3) <= 1.0) {
                    t.putVoxel(i, j, k);
                }
            }
}

PutSphere::~PutSphere(){}
