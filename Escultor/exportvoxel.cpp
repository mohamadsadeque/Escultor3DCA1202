#include "exportvoxel.h"
#include "sculptor3d.h"
#include <string.h>
#include <fstream>

exportVoxel::exportVoxel(Voxel ***_v){
    Voxel ***v = _v;
}

/**
 * @brief exportVoxel::toOFF Exporta o Voxel fornecido para o formato de arquivos OFF. A função aceita arquivos com ou sem extensão fornecida pelo usuário
 * @param filename
 */
void exportVoxel::toOFF(string filename){
    filename = tratarExtensao(filename, ".off");
    ofstream output (filename);

}

/**
 * @brief exportVoxel::toVECT Exporta o Voxel fornecido para o formato de arquivos VECT. A função aceita arquivos com ou sem extensão fornecida pelo usuário
 * @param filename
 */
void exportVoxel::toVECT(string filename){
    filename = tratarExtensao(filename, ".vect");

    ofstream output (filename);

}

//Tratamento para filename com ou sem referência, ambos são aceitos
string exportVoxel::tratarExtensao(string filename, string extensao ){
    if (filename.find(extensao) == std::string::npos) {
        filename = filename + extensao;
    }

    return filename;
}
