#include <iostream>
#include <string.h>
#include <sculptor3d.h>

using namespace std;
 
int main()
{

    sculptor3d s(10,10,10);
    s.setColor(1,0,0,1);
    s.putBox(5, 9, 5, 9, 5, 9);
    s.setColor(0,1,0,1);
    s.putBox(0,4,0,4,0,4);

    //s.cutBox(2,3,2,3,2,3);

    /*
    s.cutBox(90,95,90,95,90,95);
    s.setColor(1, 0, 0, 0.5);
    s.putSphere(10,10,10,9);
    s.putEllipsoid(50,50,50,49,49,49);
    s.cutSphere(25,25,25,24);
    s.cutEllipsoid(40,40,40,39,39,39);
    */

    s.writeOFF("/home/emerson/workspace/arquivo");

    cout << "O arquivo foi gerado" << endl;

}
