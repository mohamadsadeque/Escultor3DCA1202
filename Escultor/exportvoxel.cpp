#include "exportvoxel.h"
#include "sculptor3d.h"
#include <string.h>
#include <fstream>

exportVoxel::exportVoxel(Voxel ***_v){
    Voxel ***v = _v;
}

void exportVoxel::toOFF(string filename){
    ofstream output (filename);
}

void exportVoxel::toVECT(string filename){
    ofstream output (filename);

}

