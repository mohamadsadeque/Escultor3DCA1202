#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

using namespace std;

class CutSphere : public FiguraGeometrica
{
int xcenter,ycenter,zcenter,radius;

public:
    CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);
    ~CutSphere();
    void draw(sculptor3d &t);
};

#endif // CUTSPHERE_H
