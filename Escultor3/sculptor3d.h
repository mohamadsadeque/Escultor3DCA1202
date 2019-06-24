#ifndef SCULPTOR3D_H
#define SCULPTOR3D_H

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
/**
 * @brief O struct Voxel reuni as caracteristicas que definem a menor unidade que compõe o desenho 3D,sendo representado por um cubo de lado 1, possuindo os atributos de cor,
 * sendo armazenado no padrão RGB, representados pelas variáveis 'r','g','b', com cada intensidade definida no intervalo aberto de 0 à 1,
 * tendo também o atributo 'a' que define o nivel de transparência do voxel, se ele vai ser translúcido ou opaco, por fim o último atributo é o 'isOn'
 * que define se o voxel vai aparecer no desenho ou não.
 *
 *
 */

struct Voxel {
    /**
   * @brief  Variável para armazenar o valor da cor vermelha no intervalo [0,1].
   */

  float r;
  /**
   * @brief  Variável para armazenar o valor da cor verde no intervalo [0,1].
   */
  float g;
  /**
   * @brief  Variável para armazenar o valor da cor azul no intervalo [0,1].
   */
  float b;
  /**
   * @brief  Variável para armazenar o valor da transparência no intervalo [0,1], sendo 0 transparente e  1 opaco.
   */
  float a;
// Transparency
  /**
   * @brief  Variável para armazenar estado do voxel, se ele está ativo ou não.
   */
  bool isOn; // Included or not
};

/**
 * @brief A  classe sculptor3d foi feita para modelar desenhos 3D em arquivos que fossem capazes de serem interpretados
 * por algum software, os formatos escolhidos foramo *.vect e o *.off. Para desenhar as figuras é utilizado uma unidade
 * chamada de Voxels (volume elements), que carrega alguns atributos que definem sua cor,transparência e seu estado. Para produzir as figuras
 * é necessário construir um objeto dessa classe e determinar as dimensões máximas, após isso os métodos de construção e edição estão habilitados
 *  para serem utilizados.
 */

class sculptor3d {
protected:
  Voxel ***v;
  // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  /**
   * @brief Construtor da classe.
   * @param nx Dimensão X da matriz de Voxels
   * @param ny Dimensão Y da matriz de Voxels
   * @param nz Dimensão Z da matriz de Voxels
   */
  sculptor3d(int nx, int ny, int nz);
  /**
   * @brief Destrutor da classe.
  */
  ~sculptor3d();
  /**
   * @brief setColor Método que altera a cor e transparência dos próximos voxels
   * que serão inseridos ou removidos pelos métodos da classe.Seus parâmetros são a intesidade das cores vermelha(r), verde(g) e azul(b) em um intervalo de [0,1],também podendo alterar sua transparência nesse mesmo intervalo,sendo feito no parâmetro final.
   * @param r Valor da cor vermelha.
   * @param g Valor da cor verde.
   * @param b Valor da cor azul.
   * @param alpha Valor da transparência.
   */
  void setColor(float r, float g, float b, float alpha);
  /**
   * @brief putVoxel Método que insere um voxel no desenho, onde a passagem de paramêtros é feita com sua posição dentro da matriz principal.
   * @param x Posição do voxel no eixo x.
   * @param y Posição do voxel no eixo y.
   * @param z Posição do voxel no eixo z.
   */
  void putVoxel(int x, int y, int z);
  /**
   * @brief cutVoxel Esse método remove um voxel no desenho, onde a passagem de paramêtros é feita com sua posição dentro da matriz principal.
   * @param x Posição do voxel no eixo x.
   * @param y Posição do voxel no eixo y.
   * @param z Posição do voxel no eixo z.
   */
  void cutVoxel(int x, int y, int z);
  /**
   * @brief putBox Método insere voxels de um paralelepípedo é construído dando as coordenadas iniciais
   * e finais de cada eixo, assim, tendo controle sobre sua posição e dimensão.
   * @param x0 Ponto inicial do eixo x.
   * @param x1 Ponto final do eixo x.
   * @param y0 Ponto inicial do eixo y.
   * @param y1 Ponto final do eixo y.
   * @param z0 Ponto inicial do eixo z.
   * @param z1 Ponto final do eixo z.
   */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief cutBox Método remove voxels de um paralelepípedo que é construído dando as coordenadas iniciais
  e finais de cada eixo, assim, tendo controle sobre sua posição e dimensão.
   * @param x0 Ponto inicial do eixo x.
   * @param x1 Ponto final do eixo x.
   * @param y0 Ponto inicial do eixo y.
   * @param y1 Ponto final do eixo y.
   * @param z0 Ponto inicial do eixo z.
   * @param z1 Ponto final do eixo z.
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief putSphere Método insere uma esfera de voxels na matriz principal, passando como parâmetro as coordenas do centro e o seu raio.
   * @param xcenter Posição do centro da esfera no eixo x.
   * @param ycenter Posição do centro da esfera no eixo x.
   * @param zcenter Posição do centro da esfera no eixo x.
   * @param radius Dimensão do raio da esfera.
   */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);/** */
  /**
   * @brief cutSphere Método remove uma esfera de voxels na matriz principal, passando como parâmetro as coordenas do centro e o seu raio.
   * @param xcenter Posição do centro da esfera no eixo x.
   * @param ycenter Posição do centro da esfera no eixo y.
   * @param zcenter Posição do centro da esfera no eixo z.
   * @param radius  Dimensão do raio da esfera.
   */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);/** */
  /**
   * @brief putEllipsoid  Método insere um elipsóide formada por voxels passando como parâmpetro as coornadas do
   * seu centro e os raios em cada eixo.
   * @param xcenter Posição do centro do elipsóide no eixo x.
   * @param ycenter Posição do centro do elipsóide no eixo y.
   * @param zcenter Posição do centro do elipsóide no eixo z.
   * @param rx Dimensão do raio no eixo x.
   * @param ry Dimensão do raio no eixo y.
   * @param rz Dimensão do raio no eixo z.
   */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief cutEllipsoid Método remove um elipsóide formada por voxels passando como parâmpetro as coornadas do
   * seu centro e os raios em cada eixo.
   * @param xcenter Posição do centro do elipsóide no eixo x.
   * @param ycenter Posição do centro do elipsóide no eixo y.
   * @param zcenter Posição do centro do elipsóide no eixo z.
   * @param rx Dimensão do raio no eixo x.
   * @param ry Dimensão do raio no eixo y.
   * @param rz Dimensão do raio no eixo z.
   */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief writeOFF Método exporta a figura criada para um arquivo em extensão *.off,que pode ser visualizado pelo software Meshlab ou Geomview.
   * A passagem de parâmetro é feita com uma String dando o endereço do diretório e o nome do arquivo que você deseja salvar.
   * @param filename Passagem de endereço com o nome do arquivo no final. Exemplo: "/home/user/workspace/nomedoarquivo".
   */
  void writeOFF(string filename);
  /**
   * @brief writeVECT Método exporta a figura criada para um arquivo em extensão *.vect,que pode ser visualizado pelo software Geomview.
   * A passagem de parâmetro é feita com uma String dando o endereço do diretório e o nome do arquivo que você deseja salvar.
   * @param filename Passagem de endereço com o nome do arquivo no final. Exemplo: "/home/user/workspace/nomedoarquivo".
   */
  void writeVECT(string filename);
  /**
   * @brief countVoxels Função auxiliar para fazer a contagem de voxels ativos no desenho.
   * @return
   */
  unsigned long int countVoxels();
  /**
   * @brief getNx Método para retornar o valor da dimesão do eixo x.
   * @return nx
   */
  int getNx();
  /**
   * @brief getNy  Método para retornar o valor da dimensão do eixo y.
   * @return ny
   */
  int getNy();
  /**
   * @brief getNz Método para retornar o valor da dimensão do eixo z.
   * @return nz
   */
  int getNz();
};

#endif // SCULPTOR3D_H
