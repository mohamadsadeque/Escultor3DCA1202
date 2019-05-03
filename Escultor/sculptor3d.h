#ifndef SCULPTOR3D_H
#define SCULPTOR3D_H

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
/**
 * @brief The Voxel struct
 * POW
 * PEI
 */

struct Voxel {
  float r,g,b; // Colors
  float a;
// Transparency
  bool isOn; // Included or not
};

/**
 * @brief sculptor3d Classe responsável pelo armazenamento e manipulação da matriz de Voxels utilizado para representar figuras geométricas
 */
class sculptor3d {
protected:
  Voxel ***v;
  // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  /**
   * @brief sculptor3d Classe responsável pelo armazenamento e manipulação da matriz de Voxels utilizado para representar figuras geométricas
   * @param nx Dimensão X da matriz de Voxels
   * @param ny Dimensão Y da matriz de Voxels
   * @param nz Dimensão Z da matriz de Voxels
   */
  sculptor3d(int nx, int ny, int nz);/** Construtor da classe, para inicializar a criação das figuras é feito um dimensionamento
da sua área de trabalho, assim, os parametros passados são as dimensões máximas do eixo x,y e z respectivamente. */
  ~sculptor3d(); /** Destrutor. */
  void setColor(float r, float g, float b, float alpha); /** Método que altera a cor e transparência dos próximos voxels
 que serão inseridos ou removidos pelos métodos da classe.Seus parâmetros são a intesidade das cores vermelha(r), verde(g)
 e azul(b) em um intervalo de [0,1],também podendo alterar sua transparência nesse mesmo intervalo,sendo feito no parâmetro final.*/
  void putVoxel(int x, int y, int z);/** Método que insere um voxel no desenho, onde a passagem de paramêtros é feita com sua posição dentro da matriz principal.*/
  void cutVoxel(int x, int y, int z);/** Esse método remove um voxel no desenho, onde a passagem de paramêtros é feita com sua posição dentro da matriz principal.*/
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);/** Método insere voxels de um paralelepípedo é construído dando as coordenadas iniciais
  e finais de cada eixo, assim, tendo controle sobre sua posição e dimensão.*/
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);/** Método remove voxels de um paralelepípedo que é construído dando as coordenadas iniciais
  e finais de cada eixo, assim, tendo controle sobre sua posição e dimensão. */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);/** Método insere uma esfera de voxels na matriz principal, passando como parâmetro as coordenas do centro e o seu raio. */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);/** Método remove uma esfera de voxels na matriz principal, passando como parâmetro as coordenas do centro e o seu raio. */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);/** Método insere um elipsóide formada por voxels passando como parâmpetro as coornadas do
seu centro e os raios em cada eixo. */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);/** Método remove um elipsóide formada por voxels passando como parâmpetro as coornadas do
seu centro e os raios em cada eixo. */
  void writeOFF(string filename);/** Método exporta a figura criada para um arquivo em extensão *.off,que pode ser visualizado pelo software Meshlab ou Geomview.
A passagem de parâmetro é feita com uma String dando o endereço do diretório e o nome do arquivo que você deseja salvar.*/
  void writeVECT(string filename);/** Método exporta a figura criada para um arquivo em extensão *.vect,que pode ser visualizado pelo software Geomview.
A passagem de parâmetro é feita com uma String dando o endereço do diretório e o nome do arquivo que você deseja salvar. */
  unsigned long int countVoxels();/** Função auxiliar para fazer a contagem de voxels ativos no desenho. */
  int getNx();/** Método para retornar o valor da dimesão do eixo x. */
  int getNy();/** Método para retornar o valor da dimesão do eixo y. */
  int getNz();/** Método para retornar o valor da dimesão do eixo z. */

};

#endif // SCULPTOR3D_H
