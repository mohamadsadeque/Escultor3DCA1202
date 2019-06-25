#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QColor>
#include "sculptor3d.h"

class Plotter : public QWidget
{
    Q_OBJECT
private:
    int linhas,colunas,planos,planoAtual;
    int largura, altura;
    int timerId;
    QColor corAtual;
    QColor lineColor;
    int  r=0;
    int  g=0;
    int b=0;
int a=0;
    int cor;
    bool matriz[100][100][100];
    int referencia;
    int forma;
    //parametros das figuras:
    int raio,raioX,raioY,raioZ;
    sculptor3d *escultor;
    int boxAltura, boxProfundidade, boxLargura;

public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void configurarEscultor(int x, int y, int z);
    void extrairArquivo(QString filename);
    void limparMatriz();

signals:
    void moveX(int);
    void moveY(int);
    void moveZ(int);
    void clickXY(int,int);

public slots:
    void mudaLinhas(int l);
    void mudaColunas(int c);
    void mudaPlanos(int p);
    void olhaPlano(int p);
    void clicou(int x, int y);
    void setRefX();
    void setRefY();
    void setRefZ();
    void mudaForma(int);
    void setRaio(int);
    void setRaioX(int);
    void setRaioY(int);
    void setRaioZ(int);
    void mudaCor(QColor);
    void setBoxLargura(int);
    void setBoxProfundidade(int);
    void setBoxAltura(int);

};

#endif // PLOTTER_H
