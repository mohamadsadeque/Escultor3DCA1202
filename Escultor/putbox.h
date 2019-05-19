#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"

using namespace std;

class PutBox : public FiguraGeometrica
{
int x0, x1, y0, y1, z0, z1, r, g, b;
float a;

public:
   PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1,  int _r, int _g, int _b, float _a);
   void draw(sculptor3d &t);
   ~PutBox();
};

#endif // PUTBOX_H
