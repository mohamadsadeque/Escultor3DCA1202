#include <iostream>
#include <string.h>
#include <sculptor3d.h>

using namespace std;
 
int main()
{
    sculptor3d scp(10, 10, 10);

    scp.setColor(1, 0, 0, 1);
    scp.putBox(1, 9, 1, 9, 1, 9);
    scp.writeVECT("/home/emerson/workspace/arquivo");

    cout << "O arquivo foi gerado" << endl;

}
