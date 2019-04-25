#ifndef EXPORTVOXEL_H
#define EXPORTVOXEL_H

#include "sculptor3d.h"
#include <string.h>
using namespace std;

class exportVoxel
{
    public:
        exportVoxel(Voxel ***v);
        void toOFF(string filename);
        void toVECT(string filename);

};

#endif // EXPORTVOXEL_H
