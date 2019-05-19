#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

using namespace std;

class PutEllipsoid : public FiguraGeometrica
{
    int xcenter,ycenter,zcenter,rx, ry, rz, r,g,b;
    float a;
public:
    PutEllipsoid(int xc, int yc, int zc, int radx, int rady, int radz, int rb,int gb,int bb,int ab);
    void draw(sculptor3d &t);
};

#endif // PUTELLIPSOID_H
