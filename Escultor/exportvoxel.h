#ifndef EXPORTVOXEL_H
#define EXPORTVOXEL_H

#include "sculptor3d.h"
#include <string.h>

using namespace std;

class exportVoxel
{
    protected:
        Voxel ***v;

    public:
        exportVoxel(Voxel ***v);
        void toOFF(string filename);
        void toVECT(string filename);

    private:
        string tratarExtensao(string filename, string extensao);
};

#endif // EXPORTVOXEL_H
