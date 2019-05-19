#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor3d.h"

using namespace std;

class FiguraGeometrica
{
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica() = 0;
    virtual void draw(sculptor3d &t) = 0;
};

#endif // FIGURAGEOMETRICA_H
