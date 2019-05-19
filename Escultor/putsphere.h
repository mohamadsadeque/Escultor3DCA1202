#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

using namespace std;

class PutSphere : public FiguraGeometrica
{
 int xcenter, ycenter, zcenter, radius, r, g, b;
 float a;
public:
    PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, int _r, int _g, int _b, float _a);
    void draw(sculptor3d &t);
    ~PutSphere();
};

#endif // PUTSPHERE_H
