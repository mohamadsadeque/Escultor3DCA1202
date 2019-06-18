#include "plotter.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <cmath>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QColorDialog>
#include <QMessageBox>
#include <QString>
#include <QColor>
Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
linhas = 1;
colunas = 1;
planos = 1;
planoAtual = 0;
referencia = 0;
for(int k =0;k<100;k++){
    for(int i =0; i<100; i++){
        for(int j=0;j<100;j++){

            matriz[i][j][k] = false;
        }
    }

}
setMouseTracking(true);

}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush,brush2,brushSeta;
    QPen pen,penSeta;


  //for(int i =0; i<planos;i++) matriz[i][i][i] = true;

    switch (referencia) {
    case 0:
        largura = width()/colunas;
        altura = height()/linhas;
    break;

    case 1:
        largura = width()/colunas;
        altura = height()/planos;
    break;
    case 2:
        largura = width()/linhas;
        altura = height()/planos;
    break;

}


    brush.setColor(QColor(150,200,255));
    brush.setStyle(Qt::SolidPattern);
    brush2.setColor(QColor(0,150,100));
    brush2.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(255,0,0));
    pen.setWidth(1);

    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0,0,width(),height());
    pen.setColor(QColor(255,0,0));
    painter.setBrush(brushSeta);

    painter.setPen(penSeta);
    painter.drawLine(0,0,width(),0);

    painter.setBrush(brush);
    painter.setPen(pen);

    switch (referencia) {
        case 0:
        for(int i = 0; i<linhas;i++){
            for(int j = 0; j<colunas; j++){
                if(matriz[i][j][planoAtual]){
                     painter.setBrush(brush);
                }
                else{
                    painter.setBrush(brush2);
                }
                 painter.drawRect(largura*i+1,altura*j+1,largura+1,altura+1);
            }
        }
        break;
    case 1:
        for(int i = 0; i<linhas;i++){
            for(int j = 0; j<planos; j++){
                if(matriz[i][planoAtual][j]){
                     painter.setBrush(brush);
                }
                else{
                    painter.setBrush(brush2);
                }
                 painter.drawRect(largura*i+1,altura*j+1,largura+1,altura+1);
            }
        }

        break;
    case 2:
        for(int i = 0; i<colunas;i++){
            for(int j = 0; j<planos; j++){
                if(matriz[planoAtual][i][j]){
                     painter.setBrush(brush);
                }
                else{
                    painter.setBrush(brush2);
                }
                 painter.drawRect(largura*i+1,altura*j+1,largura+1,altura+1);
            }
        }
        break;


    }

}

void Plotter::mudaLinhas(int l)
{
    linhas = l;
    repaint();
}

void Plotter::mudaColunas(int c)
{
    colunas = c;
    repaint();
}

void Plotter::mudaPlanos(int p)
{

    planos = p;
    repaint();
}

void Plotter::olhaPlano(int p)
{

    planoAtual = p;
    switch (referencia) {
    case 0:
        if(planoAtual >= planos) planoAtual = planos-1;
    break;
    case 1:
        if(planoAtual >= colunas) planoAtual = colunas-1;

    break;
    case 2:
        if(planoAtual >= linhas) planoAtual = linhas-1;

    break;

    }
    repaint();

}

void Plotter::clicou(int x, int y)
{
    int xPos = x/largura;
    int yPos = y/altura;
    switch (referencia) {
    case 0:
        matriz[xPos][yPos][planoAtual] = !matriz[xPos][yPos][planoAtual];
    break;
    case 1:
        matriz[xPos][planoAtual][yPos] = !matriz[xPos][planoAtual][yPos];
    break;
    case 2:
        matriz[planoAtual][xPos][yPos] = !matriz[planoAtual][xPos][yPos];
    break;

    }
   repaint();

}

void Plotter::setRefZ()
{
    referencia = 0;
    repaint();
}
void Plotter::setRefX()
{
    referencia = 2;
    repaint();
}
void Plotter::setRefY()
{
    referencia = 1;
    repaint();
}





void Plotter::mouseMoveEvent(QMouseEvent *event){

    switch (referencia) {
    case 0:
        emit moveX(event->x()/largura);
        emit moveY(event->y()/altura);
        emit moveZ(planoAtual);
    break;

    case 1:
        emit moveX(event->x()/largura);
        emit moveY(planoAtual);
        emit moveZ(event->y()/altura);
    break;
    case 2:
        emit moveX(planoAtual);
        emit moveY(event->x()/largura);
        emit moveZ(event->y()/altura);
    break;

}
}

void Plotter::mousePressEvent(QMouseEvent *event){
  if(event->button() == Qt::LeftButton ){
    emit clickXY(event->x(),event->y());

  }
}




