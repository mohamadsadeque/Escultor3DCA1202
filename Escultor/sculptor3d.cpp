#include "sculptor3d.h"
#include <string.h>

sculptor3d::sculptor3d(int nx, int ny, int nz)
{
    v =  (Voxel***)malloc(nx*sizeof(Voxel**));
    v[0] = (Voxel**)malloc(nx*ny*sizeof(Voxel*));
    v[0][0] = (Voxel*)malloc(nx*ny*nz*sizeof(Voxel));
    for(int i=0; i< nx; i++)
    {
        v[i+1] = v[i]+ny;
        for(int j= 0; j<ny;j++){
            v[i][j+1] = v[i][j]+nz;
        }
    }
    setColor(1,1,1,1);
}

sculptor3d::~sculptor3d()
{
    free(v[0][0]);
    free(v[0]);
    free(v);
}

void sculptor3d::setColor(float r, float g, float b, float alpha){
    for(int i = 0; i<nx; i++){
        for(int j = 0; i<ny;j++){
            for (int k = 0; k<nz;k++) {
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = alpha;
            }
        }
    }
}

void sculptor3d::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
};

void sculptor3d::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
};

void sculptor3d::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i<x1; i++){
        for(int j = y0; i<y1;j++){
            for (int k = z0; k<z1;k++) {
                v[i][j][k].isOn = true;
            }
        }
    }
};

void sculptor3d::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i<x1; i++){
        for(int j = y0; i<y1;j++){
            for (int k = z0; k<z1;k++) {
                v[i][j][k].isOn = false;
            }
        }
    }
};

void sculptor3d::putSphere(int xcenter, int ycenter, int zcenter, int radius){

};
void sculptor3d::cutSphere(int xcenter, int ycenter, int zcenter, int radius){};
void sculptor3d::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){};
void sculptor3d::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){};
void sculptor3d::writeOFF(string filename){};
void sculptor3d::writeVECT(string filename){};
