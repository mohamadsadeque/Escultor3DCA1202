#include "exportvoxel.h"
#include "sculptor3d.h"
#include <string.h>
#include <fstream>

exportVoxel::exportVoxel(Voxel ***_v){
    Voxel ***v = _v;
}

void exportVoxel::toOFF(string filename){
    if (filename.find(".off") == std::string::npos) {
        filename = filename + ".off";
    }

    ofstream output (filename);



}

void exportVoxel::toVECT(string filename){
    if (filename.find(".vect") == std::string::npos) {
        filename = filename + ".vect";
    }

    ofstream output (filename);

}

