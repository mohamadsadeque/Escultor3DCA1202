#include "sculptor3d.h"
#include "exportvoxel.h"
#include <string.h>
#include <cmath>

bool vPos(int x, int y,int z, int nx, int ny, int nz);
bool vCol(float r,float g,float b);

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
    if(!vCol(r,g,b)){
    //mata o programa
    }
     this->r = _r;
     this->g = _g;
     this->b = _b;
     this->a = _alpha;

}

void sculptor3d::putVoxel(int x, int y, int z){
    if(!vPos(x,y,z,nx,ny,nz)){
        // mata o programa
    }
    v[x][y][z].isOn = true;
    v[x][y][z].r = this->r;
    v[x][y][z].g = this->g;
    v[x][y][z].b = this->b;
    v[x][y][z].a = this->a;
};

void sculptor3d::cutVoxel(int x, int y, int z){
    if(!vPos(x,y,z,nx,ny,nz)){
        // mata o programa~~ posição que não existe
    }
    v[x][y][z].isOn = false;
    v[x][y][z].r = this->r;
    v[x][y][z].g = this->g;
    v[x][y][z].b = this->b;
    v[x][y][z].a = this->a;
};

void sculptor3d::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    if(!vPos(x0,y0,z0,nx,ny,nz)){
        // mata o programa~~ posição que não existe
    }
    if(!vPos(x1,y1,z1,nx,ny,nz)){
        // mata o programa~~ posição que não existe
    }
    if(x0>=x1 || z0>=z1 || z0>=z1){
        // mata o programa ~~ limites da figura errados
    }
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
    if(!vPos(x0,y0,z0,nx,ny,nz)){
        // mata o programa~~ posição que não existe
    }
    if(!vPos(x1,y1,z1,nx,ny,nz)){
        // mata o programa ~~ posição que não existe
    }
    if(x0>=x1 || z0>=z1 || z0>=z1){
        // mata o programa ~~ limites da figura errados
    }
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
    if(!vPos(xcenter,ycenter,zcenter,nx,ny,nz)){
        // mata o programa~~ posição que não existe
    }
    if(radius == 0){
        // mata o programa ~~ o raio não pode ser zero
    }

    for(int k = 0; k< nz; k++){
            for(int i = 0; i<nx; i++){
                for(int j = 0; j<ny; j++){
                    if( (pow(((i-xcenter)/radius), 2)) +(pow(((j-ycenter)/radius), 2)) + (pow(((k-zcenter)/radius), 2)) <= 1 ){
                        v[i][j][k].isOn = true;
                        v[i][j][k].r = this->r;
                        v[i][j][k].g = this->g;
                        v[i][j][k].b = this->b;
                        v[i][j][k].a = this->a;
                    }

                }
            }
        }
};
void sculptor3d::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    if(!vPos(xcenter,ycenter,zcenter,nx,ny,nz)){
        // mata o programa~~ posição que não existe
    }
    if(radius == 0){
        // mata o programa ~~ o raio não pode ser zero
    }
    for(int k = 0; k< nz; k++){
            for(int i = 0; i<nx; i++){
                for(int j = 0; j<ny; j++){
                    if( (pow(((i-xcenter)/radius), 2)) +(pow(((j-ycenter)/radius), 2)) + (pow(((k-zcenter)/radius), 2)) <= 1 ){
                        v[i][j][k].isOn = false;
                        v[i][j][k].r = this->r;
                        v[i][j][k].g = this->g;
                        v[i][j][k].b = this->b;
                        v[i][j][k].a = this->a;
                    }

                }
            }
        }
};

void sculptor3d::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    if(!vPos(xcenter,ycenter,zcenter,nx,ny,nz)){
        // mata o programa~~ posição que não existe
    }
    if(rx == 0||ry == 0 || rz == 0){
        // mata o programa ~~ o raio não pode ser zero
    }
    for(int k = 0;k< nz; k++){
            for(int i = 0; i<nx; i++){
                for(int j = 0; j<ny; j++){
                    if( (pow(((i-xcenter)/rx), 2)) +(pow(((j-ycenter)/ry), 2)) + (pow(((k-zcenter)/rz), 2)) <= 1 ){
                        v[i][j][k].isOn = true;
                        v[i][j][k].r = this->r;
                        v[i][j][k].g = this->g;
                        v[i][j][k].b = this->b;
                        v[i][j][k].a = this->a;

                    }

                }
            }
        }
};

void sculptor3d::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    if(!vPos(xcenter,ycenter,zcenter,nx,ny,nz)){
        // mata o programa~~ posição que não existe
    }
    if(rx == 0||ry == 0 || rz == 0){
        // mata o programa ~~ o raio não pode ser zero
    }
    for(int k = 0; k< nz; k++){
            for(int i = 0; i<nx; i++){
                for(int j = 0; j<ny; j++){
                    if( (pow(((i-xcenter)/rx), 2)) +(pow(((j-ycenter)/ry), 2)) + (pow(((k-zcenter)/rz), 2)) <= 1 ){
                        v[i][j][k].isOn = false;
                        v[i][j][k].r = this->r;
                        v[i][j][k].g = this->g;
                        v[i][j][k].b = this->b;
                        v[i][j][k].a = this->a;
                    }
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


bool vPos(int x, int y,int z, int nx, int ny, int nz){
    if(x<0 || x>=nx) return false;
    if(y<0 || y>=ny) return false;
    if(z<0 || z>=nz) return false;
    return true;

}

bool vCol(float r,float g,float b){
    if(r<0 || r>1) return false;
    if(g<0 || g>1) return false;
    if(b<0 || b>1) return false;
    return true;

}

