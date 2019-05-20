#include <sculptor3d.h>
#include <cutbox.h>
#include <putbox.h>
#include <cutsphere.h>
#include <putsphere.h>
#include <putellipsoid.h>
#include <cutellipsoid.h>
#include <putvoxel.h>
#include <cutvoxel.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

void eraseSubStr(std::string & mainStr, const std::string & toErase)
{
    // Search for the substring in string
    size_t pos = mainStr.find(toErase);

    if (pos != std::string::npos)
    {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}


int main()
{
    //O sculptor é sempre necessário;
    sculptor3d *s;

    std::ifstream arquivoConfiguracao("/home/emerson/figura.txt");
    if(arquivoConfiguracao.is_open()){
        string linha;
        while (getline(arquivoConfiguracao, linha)) {

            if (linha.find("dim") != std::string::npos) {
                eraseSubStr(linha, "dim");

                std::istringstream linhaEmStream(linha);

                int x, y, z;
                linhaEmStream >> x >> y >> z;
                cout << "O arquivo terá estas dimensões: " << x << " " << y << " " << z << endl;

                s = new sculptor3d(x, y, z);
            }

            if (linha.find("putbox") != std::string::npos) {
                eraseSubStr(linha, "putbox");

                std::istringstream linhaEmStream(linha);

                cout << "Encontrei putbox" << endl;
                int x0, x1, y0, y1, z0, z1, r, g, b;
                float a;

                linhaEmStream >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                PutBox pb(x0,x1,y0,y1,z0,z1, r, g, b, a);
                pb.draw(*s);
            }

            if (linha.find("cutbox") != std::string::npos) {
                eraseSubStr(linha, "cutbox");

                std::istringstream linhaEmStream(linha);

                cout << "Encontrei um cutbox" << endl;
                int x0, x1, y0, y1, z0, z1;

                linhaEmStream >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                CutBox cb(x0,x1,y0,y1,z0,z1);
                cb.draw(*s);
            }

            if (linha.find("putvoxel") != std::string::npos) {
                eraseSubStr(linha, "putvoxel");

                std::istringstream linhaEmStream(linha);

                cout << "Encontrei putvoxel" << endl;
                int x0, y0, z0, r, g, b;
                float a;

                linhaEmStream >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                PutVoxel pv(x0,y0,z0, r, g, b, a);
                pv.draw(*s);
            }

            if (linha.find("cutvoxel") != std::string::npos) {
                eraseSubStr(linha, "cutvoxel");

                std::istringstream linhaEmStream(linha);

                cout << "Encontrei cutvoxel" << endl;
                int x0, y0, z0, r, g, b;
                float a;

                linhaEmStream >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                CutVoxel cv(x0,y0,z0, r, g, b, a);
                cv.draw(*s);
            }

            if (linha.find("cutsphere") != std::string::npos) {
                eraseSubStr(linha, "cutsphere");

                std::istringstream linhaEmStream(linha);

                cout << "Encontrei cutsphere" << endl;
                int x0, y0, z0, raio;


                linhaEmStream >> x0 >> y0 >> z0 >> raio;
                CutSphere cs(x0, y0, z0, raio);
                cs.draw(*s);
            }

            if (linha.find("putsphere") != std::string::npos) {
                eraseSubStr(linha, "putsphere");

                std::istringstream linhaEmStream(linha);

                cout << "Encontrei putsphere" << endl;
                int x0, y0, z0, raio, r, g, b;
                float a;

                linhaEmStream >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;
                PutSphere ps(x0, y0, z0, raio, r, g, b, a);
                ps.draw(*s);
            }

            if (linha.find("cutellipsoid") != std::string::npos) {
                eraseSubStr(linha, "cutellipsoid");

                std::istringstream linhaEmStream(linha);

                cout << "Encontrei cutellipsoid" << endl;
                int x0, y0, z0, rx, ry, rz;

                linhaEmStream >> x0 >> y0 >> z0 >> rx >> ry >> rz;
                CutEllipsoid ce(x0, y0, z0, rx, ry, rz);
                ce.draw(*s);
            }

            if (linha.find("putellipsoid") != std::string::npos) {
                eraseSubStr(linha, "putellipsoid");

                std::istringstream linhaEmStream(linha);

                cout << "Encontrei putellipsoid" << endl;
                int x0, y0, z0, rx, ry, rz, r, g, b;
                float a;

                linhaEmStream >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
                PutEllipsoid pe(x0, y0, z0, rx, ry, rz, r, g, b, a);
                pe.draw(*s);
            }

        }
        arquivoConfiguracao.close();
    }

    s->writeOFF("/home/emerson/box");
    cout << "O arquivo foi gerado" << endl;

}
