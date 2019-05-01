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
    if(nx == 0 || ny == 0 || nz == 0)
           return;

    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

void sculptor3d::setColor(float _r, float _g, float _b, float _alpha){
     this->r = _r;
     this->g = _g;
     this->b = _b;
     this->a = _alpha;
}

void sculptor3d::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = this->r;
    v[x][y][z].g = this->g;
    v[x][y][z].b = this->b;
    v[x][y][z].a = this->a;
};

void sculptor3d::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
    v[x][y][z].r = this->r;
    v[x][y][z].g = this->g;
    v[x][y][z].b = this->b;
    v[x][y][z].a = this->a;
};

void sculptor3d::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i<x1; i++){
        for(int j = y0; j<y1;j++){
            for (int k = z0; k<z1;k++) {
                v[i][j][k].isOn = true;
                v[i][j][k].r = this->r;
                v[i][j][k].g = this->g;
                v[i][j][k].b = this->b;
                v[i][j][k].a = this->a;
            }
        }
    }
};
void sculptor3d::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i<x1; i++){
        for(int j = y0; j<y1;j++){
            for (int k = z0; k<z1;k++) {
                v[i][j][k].isOn = false;
                v[i][j][k].r = this->r;
                v[i][j][k].g = this->g;
                v[i][j][k].b = this->b;
                v[i][j][k].a = this->a;
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
                        v[i][j][k].r = this->r;
                        v[i][j][k].g = this->g;
                        v[i][j][k].b = this->b;
                        v[i][j][k].a = this->a;
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
                        v[i][j][k].r = this->r;
                        v[i][j][k].g = this->g;
                        v[i][j][k].b = this->b;
                        v[i][j][k].a = this->a;
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
                        v[i][j][k].r = this->r;
                        v[i][j][k].g = this->g;
                        v[i][j][k].b = this->b;
                        v[i][j][k].a = this->a;

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
                    v[i][j][mk].r = this->r;
                    v[i][j][mk].g = this->g;
                    v[i][j][mk].b = this->b;
                    v[i][j][mk].a = this->a;
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


