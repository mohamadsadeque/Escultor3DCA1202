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
        ******************************************************************
        ***** Nesse exemplo é possível ver o Cut/Put Box, além do    *****
        ***** setColor para, nesse caso com azul = 1  e alpha = 0.3  *****
        ***** Nesse exemplo também é utilizado os métodos cutVoxel e *****
        ***** putVoxel                                              *****
        ******************************************************************

        s.setColor(0, 0, 1, 0.3);
        s.putBox(40,95,40,95,40,95);
        s.cutBox(80,95,80,95,80,95);
    */

    /*
        ***************************************************************
        ***** Nesse exemplo é possível ver o Cut/Put Box,         *****
        ***** além do setColor para, nesse caso com azul = 1      *****
        ***** e alpha = 0.7 .Nesse exemplo também é utilizado os  *****
        ***** métodos cutVoxel e putVoxel                         *****
        ***************************************************************
        s.putEllipsoid(50,50,50,49,49,49);
        s.cutEllipsoid(40,40,40,39,39,39);


    */

    s.writeOFF("/home/emerson/workspace/arquivo");

    cout << "O arquivo foi gerado" << endl;

}
