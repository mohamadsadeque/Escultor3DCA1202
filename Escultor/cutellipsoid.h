#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

using namespace std;

class CutEllipsoid : public FiguraGeometrica
{
     int xcenter,ycenter,zcenter,rx, ry, rz;
public:
    CutEllipsoid(int _xcenter, int _ycenter, int _zcenter,
                                int _rx, int _ry, int _rz);
    void draw(sculptor3d &t);
    ~CutEllipsoid();

};

#endif // CUTELLIPSOID_H
