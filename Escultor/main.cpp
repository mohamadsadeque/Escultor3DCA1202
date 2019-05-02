#include <iostream>
#include <string.h>
#include <sculptor3d.h>

using namespace std;

int main()
{

    sculptor3d s(200, 200, 200);
    s.setColor(1, 0, 0, 0.7);
    s.putSphere(100, 100, 100, 50);

    /*
    s.putEllipsoid(50,50,50,49,49,49);
    s.cutSphere(25,25,25,24);
    s.cutEllipsoid(40,40,40,39,39,39);
    */

    s.writeOFF("/home/emerson/workspace/arquivo");

    cout << "O arquivo foi gerado" << endl;

}
