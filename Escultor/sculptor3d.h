#ifndef SCULPTOR3D_H
#define SCULPTOR3D_H

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

struct Voxel {
  float r,g,b; // Colors
  float a;
// Transparency
  bool isOn; // Included or not
};


class sculptor3d {
protected:
  Voxel ***v;
  // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  sculptor3d(int nx, int ny, int nz);
  ~sculptor3d();
  void setColor(float r, float g, float b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(string filename);
  void writeVECT(string filename);
};

#endif // SCULPTOR3D_H
