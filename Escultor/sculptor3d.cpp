#include "sculptor3d.h"
#include <string.h>
#include <cmath>
#include <fstream>

bool vPos(int x, int y,int z, int nx, int ny, int nz);
bool vCol(float r,float g,float b);
string tratarExtensao(string filename, string extensao);

sculptor3d::sculptor3d(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

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
        exit(0);
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
        cout << "Erro: posição invalida" << endl;
        exit(0);
    }

    if(!vPos(x1,y1,z1,nx,ny,nz)){
        cout << "Erro: posição invalida" << endl;
        exit(0);
    }

    if(x0>=x1 || z0>=z1 || z0>=z1){
        cout << "Erro: posição trocada" << endl;
        exit(0);
    }

    for(int i = x0; i<x1+1; i++){
        for(int j = y0; j<y1+1;j++){
            for (int k = z0; k<z1+1;k++) {
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
        exit(0);
    }

    if(!vPos(x1,y1,z1,nx,ny,nz)){
        exit(0);
    }

    if(x0>=x1 || z0>=z1 || z0>=z1){
        exit(0);
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
        cout << "Erro: posição invalida" << endl;
        exit(0);


    }

    if(radius == 0){
        cout << "Erro: raio invalido" << endl;
        exit(0);

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
        exit(0);
    }

    if(radius == 0){
        // mata o programa ~~ o raio não pode ser zero
        exit(0);
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
        exit(0);
    }

    if(rx == 0||ry == 0 || rz == 0){
        // mata o programa ~~ o raio não pode ser zero
        exit(0);
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
    filename = tratarExtensao(filename, ".off");
    int numeroVoxels = countVoxels();
    int count = 0;
    ofstream output (filename);
    output << "OFF" << endl;
    output << numeroVoxels*8 << " " << numeroVoxels*6 << " 0"<< endl;
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(v[i][j][k].isOn){
                    output << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    output << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    output << i+0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    output << i+0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    output << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                    output << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    output << i+0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    output << i+0.5 << " " << j+0.5 << " " << k+0.5 << endl;

                }
            }

        }
    }

    for(int i = 0; i < nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(v[i][j][k].isOn){
                output << "4 " << count << " " << count+3 << " " << count+2<< " "<< count+1 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a <<endl;
                output << "4 " << count+4 << " " << count+5 << " " << count+6<< " "<< count+7 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a <<endl;
                output << "4 " << count << " " << count+1 << " " << count+5<< " "<< count+4 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a <<endl;
                output << "4 " << count << " " << count+4 << " " << count+7<< " "<< count+3 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a <<endl;
                output << "4 " << count+3 << " " << count+7 << " " << count+6<< " "<< count+2 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a <<endl;
                output << "4 " << count+1 << " " << count+2 << " " << count+6<< " "<< count+5 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a <<endl;
               count++;
                }
            }
        }
    }

    output.close();
};

void sculptor3d::writeVECT(string filename){
    filename = tratarExtensao(filename, ".vect");

    unsigned long int numeroVoxels = countVoxels();

    ofstream arquivo (filename);
    arquivo << "VECT" << endl;
    arquivo << numeroVoxels << " " << numeroVoxels << " " << numeroVoxels << endl;

    for(int i = 0; i <= 1; i++){
        for (int j =0; j < numeroVoxels; j++) {
            arquivo << "1" << " ";
        }
        arquivo << endl;
    }

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn){
                    arquivo << i <<" "<< j <<" "<< k << endl;
                }
            }
        }
    }

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn){
                    arquivo << v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                }
            }
        }
    }


    arquivo.close();
};


//Tratamento para filename com ou sem referência, ambos são aceitos
string tratarExtensao(string filename, string extensao ){
    if (filename.find(extensao) == std::string::npos) {
        filename = filename + extensao;
    }

    return filename;
}

bool vPos(int x, int y,int z, int nx, int ny, int nz){
    if(x<0 || x>=nx)
        return false;

    if(y<0 || y>=ny)
        return false;

    if(z<0 || z>=nz)
        return false;

    return true;
}

bool vCol(float r,float g,float b){
    if(r<0 || r>1) return false;
    if(g<0 || g>1) return false;
    if(b<0 || b>1) return false;
    return true;

}

int sculptor3d::getNx(){
    return nx;
}

int sculptor3d::getNy(){
    return ny;
}

int sculptor3d::getNz(){
    return nz;
}


unsigned long int sculptor3d::countVoxels(){
    unsigned long int numeroDeVoxels = 0;

    for(int i = 0; i < nx; i++)
        for(int j = 0; j < ny; j++)
            for(int k = 0; k < nz; k++)
                if (v[i][j][k].isOn == true)
                    numeroDeVoxels++;

    return numeroDeVoxels;
}
