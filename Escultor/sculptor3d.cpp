#include "sculptor3d.h"
#include "exportvoxel.h"
#include <string.h>
#include <cmath>

sculptor3d::sculptor3d(int nx, int ny, int nz)
{
    v =  new Voxel **[nx];
    v[0] = new Voxel *[nx*ny];
    v[0][0] = new Voxel[nx*ny*nz];
    for(int i=0; i< nx; i++)
    {
        v[i+1] = v[i]+ny;
        for(int j= 0; j<ny;j++){
            v[i][j+1] = v[i][j]+nz;
        }
    }
    setColor(1,1,1,1);

}

sculptor3d::~sculptor3d(){
    for(int i = 0 ; i < nx; i++){
        for(int j= 0; j<ny; j++){
            delete []v[i][j];
        }
        delete []v[i];
    }
    delete []v;
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
        for(int j = y0; j<y1;j++){
            for (int k = z0; k<z1;k++) {
                v[i][j][k].isOn = true;
            }
        }
    }
};
void sculptor3d::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i<x1; i++){
        for(int j = y0; j<y1;j++){
            for (int k = z0; k<z1;k++) {
                v[i][j][k].isOn = false;
            }
        }
    }
};
void sculptor3d::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int k = 0; k<= zcenter; k++){
            for(int i = 0; i<nx; i++){
                for(int j = 0; j<ny; j++){
                    if( (pow(((i-xcenter)/radius), 2)) +(pow(((j-ycenter)/radius), 2)) + (pow(((k-zcenter)/radius), 2)) <= 1 ){
                        v[i][j][k].isOn = true;
                    }
                    int mk = (nz-1) - k;
                    v[i][j][mk].isOn = v[i][j][k].isOn;
                }
            }
        }
};
void sculptor3d::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int k = 0; k<= zcenter; k++){
            for(int i = 0; i<nx; i++){
                for(int j = 0; j<ny; j++){
                    if( (pow(((i-xcenter)/radius), 2)) +(pow(((j-ycenter)/radius), 2)) + (pow(((k-zcenter)/radius), 2)) <= 1 ){
                        v[i][j][k].isOn = false;
                    }
                    int mk = (nz-1) - k;
                    v[i][j][mk].isOn = v[i][j][k].isOn;
                }
            }
        }
};

void sculptor3d::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int k = 0; k<= zcenter; k++){
            for(int i = 0; i<nx; i++){
                for(int j = 0; j<ny; j++){
                    if( (pow(((i-xcenter)/rx), 2)) +(pow(((j-ycenter)/ry), 2)) + (pow(((k-zcenter)/rz), 2)) <= 1 ){
                        v[i][j][k].isOn = true;
                    }
                    int mk = (nz-1) - k;
                    v[i][j][mk].isOn = v[i][j][k].isOn;
                }
            }
        }
};

void sculptor3d::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int k = 0; k<= zcenter; k++){
            for(int i = 0; i<nx; i++){
                for(int j = 0; j<ny; j++){
                    if( (pow(((i-xcenter)/rx), 2)) +(pow(((j-ycenter)/ry), 2)) + (pow(((k-zcenter)/rz), 2)) <= 1 ){
                        v[i][j][k].isOn = false;
                    }
                    int mk = (nz-1) - k;
                    v[i][j][mk].isOn = v[i][j][k].isOn;
                }
            }
        }
};

void sculptor3d::writeOFF(string filename){
    exportVoxel exporter(this->v);
    exporter.toOFF(filename);
};
void sculptor3d::writeVECT(string filename){
    exportVoxel exporter(this->v);
    exporter.toVECT(filename);
};


