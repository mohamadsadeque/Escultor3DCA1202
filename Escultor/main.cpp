#include <iostream>
#include <string.h>
#include <sculptor3d.h>

using namespace std;

int main()
{

    //O sculptor é sempre necessário;
    sculptor3d s(100, 100, 100);

    /*
        ***************************************************************
        ***** Nesse exemplo é possível ver o Cut/Put Sphere,      *****
        ***** além do setColor para, nesse caso com vermelho = 1  *****
        ***** e alpha = 0.7 .Nesse exemplo também é utilizado os  *****
        ***** métodos cutVoxel e putVoxel                         *****
        **************************************************************

        s.setColor(1,0, 0, 0.7);
        s.putSphere(10,10,10,9);
        s.cutSphere(25,25,25,24);
    */


    /*
        ***************************************************************
        ***** Nesse exemplo é possível ver o Cut/Put Box,         *****
        ***** além do setColor para, nesse caso com vermelho = 1  *****
        ***** e alpha = 0.7 .Nesse exemplo também é utilizado os  *****
        ***** métodos cutVoxel e putVoxel                         *****
        **************************************************************
    */

    /*
    s.putBox(50,95,50,95,50,95);
    s.cutBox(90,95,90,95,90,95);
    s.setColor(1, 0, 0, 0.5);
    s.putSphere(10,10,10,9);
    s.putEllipsoid(50,50,50,49,49,49);
    s.cutSphere(25,25,25,24);
    s.cutEllipsoid(40,40,40,39,39,39);
    */

    s.writeVECT("/home/emerson/workspace/arquivo");

    cout << "O arquivo foi gerado" << endl;

}
