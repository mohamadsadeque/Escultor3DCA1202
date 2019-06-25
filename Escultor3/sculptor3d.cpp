#include "sculptor3d.h"
#include <string.h>
#include <cmath>
#include <fstream>
#include <qdebug.h>

bool vPos(int x, int y,int z, int nx, int ny, int nz);
bool vCol(float r,float g,float b,float a);
string tratarExtensao(string filename, string extensao);

/**
 * @brief sculptor3d Classe responsável pelo armazenamento e manipulação da matriz de Voxels utilizado para representar figuras geométricas
 * @param nx Dimensão X da matriz de Voxels
 * @param ny Dimensão Y da matriz de Voxels
 * @param nz Dimensão Z da matriz de Voxels
 */
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

    setColor(0.5,0.5,0.5,0.5);
}

sculptor3d::~sculptor3d(){
    if(nx == 0 || ny == 0 || nz == 0)
        return;

    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}


void sculptor3d::setColor(float _r, float _g, float _b, float _alpha){
    if(!vCol(_r,_g,_b,_alpha)){
        qDebug("Erro: cor invalida");
        //exit(0);
    }

    this->r = _r;
    this->g = _g;
    this->b = _b;
    this->a = _alpha;
}

void sculptor3d::putVoxel(int x, int y, int z){
    if(!vPos(x,y,z,nx,ny,nz)){
        qDebug("A posicao que deseja acessar nao existe");
        //exit(0);
    }

    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
};

void sculptor3d::cutVoxel(int x, int y, int z){
    if(!vPos(x,y,z,nx,ny,nz)){
        qDebug( "A posicao que deseja acessar nao existe");
        //exit(0);
    }

    v[x][y][z].isOn = false;
};

bool sculptor3d::voxelIsOn(int x, int y,int z,int &r,int &g,int &b,int &a){
    if(v[x][y][z].isOn){
        r = 255*v[x][y][z].r;
        g= 255*v[x][y][z].g;
        b= 255*v[x][y][z].b;
       a = 255*v[x][y][z].a;
       return true;
    }
    else {
        return false;
    }

}

void sculptor3d::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    if(!vPos(x0,y0,z0,nx,ny,nz)){
        qDebug( "Erro: posição invalida");
        //exit(0);
    }
    if(!vPos(x1,y1,z1,nx,ny,nz)){
        qDebug( "Erro: posição invalida");
        //exit(0);
    }
    if(x0>=x1 || z0>=z1 || z0>=z1){
        qDebug( "Erro: posição trocado. Fim menor que o inicio");
        //exit(0);
    }

    for(int i = x0; i < x1; i++)
        for(int j = y0; j < y1; j++)
            for (int k = z0; k < z1; k++){
                v[i][j][k].isOn = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
};

void sculptor3d::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    if(!vPos(x0,y0,z0,nx,ny,nz)){
        qDebug( "Erro: posição invalida");
        //exit(0);
    }

    if(!vPos(x1,y1,z1,nx,ny,nz)){
        qDebug( "Erro: posição invalida");
        //exit(0);
    }

    if(x0>=x1 || z0>=z1 || z0>=z1){
        qDebug( "Erro: Parametros finais menor que os iniciais. Necessario correcao");
        //exit(0);
    }

    for(int i = x0; i < x1 ; i++)
        for(int j = y0; j < y1; j++)
            for (int k = z0; k < z1; k++)
                v[i][j][k].isOn = false;

};

void sculptor3d::putSphere(int xcenter, int ycenter, int zcenter, int radius){
        if(!vPos(xcenter,ycenter,zcenter,nx,ny,nz)){
            qDebug( "Erro: posição invalida");
            //exit(0);
        }

        if(radius == 0){
            qDebug( "Erro: raio invalido");
            //exit(0);
        }

        for(int i=xcenter-radius; i< xcenter+radius; i++){
            if(i == nx) break;
            for(int j=ycenter-radius; j< ycenter+radius; j++){
                if(j == ny) break;
                for(int k=zcenter-radius; k< zcenter+radius; k++)
                {
                    if(k == nz) break;

                    if(i < 0) i = 0;
                    if(j < 0) j = 0;
                    if(k < 0) k = 0;

                    float calc1 = ((float)pow((i-xcenter),2)/(pow(radius,2)));
                    float calc2 = ((float)pow((j-ycenter),2))/(float)(pow(radius,2));
                    float calc3 = (((float)pow((k-zcenter),2))/(float)(pow(radius,2)));

                    if ((calc1 + calc2 + calc3) <= 1.0) {
                        v[i][j][k].isOn = true;
                        v[i][j][k].r = r;
                        v[i][j][k].g = g;
                        v[i][j][k].b = b;
                        v[i][j][k].a = a;
                    }
                }
            }
        }
};

void sculptor3d::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    if(!vPos(xcenter,ycenter,zcenter,nx,ny,nz)){
        qDebug("Erro: posição invalida");
        //exit(0);
    }

    if(radius == 0){
        qDebug( "Erro: raio invalido");
        //exit(0);
    }

    for(int i=xcenter-radius; i< xcenter+radius; i++)
        for(int j=ycenter-radius; j< ycenter+radius; j++)
            for(int k=zcenter-radius; k< zcenter+radius; k++)
            {
                float calc1 = ((float)pow((i-xcenter),2)/(pow(radius,2)));
                float calc2 = ((float)pow((j-ycenter),2))/(float)(pow(radius,2));
                float calc3 = (((float)pow((k-zcenter),2))/(float)(pow(radius,2)));
                if ((calc1 + calc2 + calc3) <= 1.0)
                    v[i][j][k].isOn = false;
            }
};

void sculptor3d::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=xcenter-rx; i< xcenter+rx; i++)
        for(int j=ycenter-ry; j< ycenter+ry; j++)
            for(int k=zcenter - rz; k< zcenter + rz; k++){
                float calc1 = ((float)pow((i-xcenter),2)/(pow(rx,2)));
                float calc2 = ((float)pow((j-ycenter),2)/(pow(ry,2)));
                float calc3 = ((float)pow((k-zcenter),2)/(pow(rz,2)));
                if ((calc1 + calc2 + calc3) <=1.0) {
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
}

void sculptor3d::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=xcenter-rx; i< xcenter+rx; i++)
        for(int j=ycenter-ry; j< ycenter+ry; j++)
            for(int k=zcenter - rz; k< zcenter + rz; k++){
                float calc1 = ((float)pow((i-xcenter),2)/(pow(rx,2)));
                float calc2 = ((float)pow((j-ycenter),2)/(pow(ry,2)));
                float calc3 = ((float)pow((k-zcenter),2)/(pow(rz,2)));
                if ((calc1 + calc2 + calc3) <=1.0)
                    v[i][j][k].isOn = false;

            }
}

void sculptor3d::writeOFF(string filename){
    filename = tratarExtensao(filename, ".off");

    //Essa construção não funciona no compilador VSMS do Windows. Necessário utilizar GCC!!!!
    char pontosAoRedor[nx][ny][nz];

    for(int i = 0; i < nx; i++)
        for(int j = 0; j < ny; j++)
            for(int k = 0; k < nz; k++)
                pontosAoRedor[i][j][k] = 0;

    bool emVoltaX, emVoltaY, emVoltaZ;

    for(int i = 1; i < nx-1; i++)
        for(int j = 1; j < ny-1; j++)
            for(int k = 1; k < nz-1; k++){
                emVoltaX = false; emVoltaY = false; emVoltaZ=false;

                if(v[i][j][k-1].isOn && v[i][j][k+1].isOn)
                    emVoltaZ = true;

                if(v[i][j-1][k].isOn && v[i][j+1][k].isOn)
                    emVoltaY = true;

                if(v[i-1][j][k].isOn && v[i+1][j][k].isOn)
                    emVoltaX = true;

                if(emVoltaX && emVoltaY && emVoltaZ)
                    pontosAoRedor[i][j][k] = 1;
            }

    //Número de voxel com pontos On e ao redor vazio. Arquivo .vect dando problema aqui
    int numeroDeVoxels = 0;

    for(int i = 0; i < nx; i++)
        for(int j = 0; j < ny; j++)
            for(int k = 0; k < nz; k++)
                if (v[i][j][k].isOn && pontosAoRedor[i][j][k] == 0)
                    numeroDeVoxels++;

    ofstream arquivo (filename);
    arquivo << "OFF" << endl;
    arquivo << numeroDeVoxels*8 << " " << numeroDeVoxels*6 << " " << 0 << endl;

    for(int k = 0; k < nz; k++)
        for(int j = 0; j < ny; j++)
            for(int i = 0; i < nx; i++){
                if(v[i][j][k].isOn && pontosAoRedor[i][j][k] == 0){
                    arquivo << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    arquivo << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    arquivo << 0.5+i << " " << j-0.5 << " " << k-0.5 << endl;
                    arquivo << 0.5+i << " " << j+0.5 << " " << k-0.5 << endl;
                    arquivo << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                    arquivo << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    arquivo << 0.5+i << " " << j-0.5 << " " << k+0.5 << endl;
                    arquivo << 0.5+i << " " << 0.5+j << " " << k+0.5 << endl;
                }
            }

    int count = 0;

    for(int k = 0; k < nz; k++)
        for(int j = 0; j<ny; j++)
            for(int i = 0; i < nx; i++){
                if(v[i][j][k].isOn && pontosAoRedor[i][j][k] == 0){
                    //Ver exemplo de agostinho para um cubo unitário e replicar a numeração aqui para os incrementos
                    arquivo << "4 " << 0+count*8 << " " << 8*count+3 << " " << 8*count+2<< " "<< 8*count+1 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a << endl;
                    arquivo << "4 " << 8*count+4 << " " << 8*count+5 << " " << 8*count+6<< " "<< 8*count+7 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a << endl;
                    arquivo << "4 " << 8*count+0 << " " << 8*count+1 << " " << 8*count+5<< " "<< 8*count+4 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a << endl;
                    arquivo << "4 " << 8*count+0 << " " << 8*count+4 << " " << 8*count+7<< " "<< 8*count+3 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a << endl;
                    arquivo << "4 " << 8*count+3 << " " << 8*count+7 << " " << 8*count+6<< " "<< 8*count+2 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a << endl;
                    arquivo << "4 " << 8*count+1 << " " << 8*count+2 << " " << 8*count+6<< " "<< 8*count+5 <<" " <<v[i][j][k].r << " " <<v[i][j][k].g << " " <<v[i][j][k].b << " "<<v[i][j][k].a << endl;
                    count++;
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

bool vCol(float r,float g,float b,float a){
    if(r<0.0 || r>1.0) return false;
    if(g<0.0 || g>1.0) return false;
    if(b<0.0 || b>1.0) return false;
    if(a<0.0 || a>1.0) return false;
    return true;
}
