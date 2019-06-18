#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>


class Plotter : public QWidget
{
    Q_OBJECT
private:
    int linhas,colunas,planos,planoAtual;
    int largura, altura;
    int timerId;
    QColor lineColor;
    int cor;
    bool matriz[100][100][100];
    int referencia;


public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

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

};

#endif // PLOTTER_H
