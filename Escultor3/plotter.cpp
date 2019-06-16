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
for(int k =0;k<100;k++){
    for(int i =0; i<100; i++){
        for(int j=0;j<100;j++){

            matriz[i][j][k] = false;
        }
    }

}
}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush,brush2;
    QPen pen;


  //for(int i =0; i<planos;i++) matriz[i][i][i] = true;



     largura = width()/colunas;
     altura = height()/linhas;

    brush.setColor(QColor(255,255,100));
    brush.setStyle(Qt::SolidPattern);
    brush2.setColor(QColor(0,255,100));
    brush2.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(255,0,0));
    pen.setWidth(2);

    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0,0,width(),height());
    pen.setColor(QColor(255,0,0));

    // Desenha linhas baseado na entrada da caixa de dialogo NovoArquivo
    /*
    for(int i =0; i<linhas;i++){
    painter.drawLine(0,(height()/linhas)*i,width(),(height()/linhas)*i);
    }

    for(int i =0; i<colunas;i++){
    painter.drawLine((width()/colunas)*i,0,(width()/colunas)*i,height());
    }*/

    // Tentando desenhar os retangulos
    brush.setColor(QColor(100,100,150));
    for(int i = 0; i<linhas;i++){
        for(int j = 0; j<colunas; j++){
            if(matriz[i][j][planoAtual]){
                 painter.setBrush(brush);
            }
            else{
                painter.setBrush(brush2);
            }
             painter.drawRect(largura*i,altura*j,largura,altura);
        }
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

}

void Plotter::olhaPlano(int p)
{

    planoAtual = p;
    if(planoAtual > planos) planoAtual = planos-1;
    repaint();

}

void Plotter::clicou(int x, int y)
{
    int xPos = x/largura;
    int yPos = y/altura;
   matriz[xPos][yPos][planoAtual] = !matriz[xPos][yPos][planoAtual];
   repaint();

}



void Plotter::mouseMoveEvent(QMouseEvent *event){
  emit moveX(event->x());
  emit moveY(event->y());
  // qDebug() << event->x() << "x" << event->y();
}

void Plotter::mousePressEvent(QMouseEvent *event){
  if(event->button() == Qt::LeftButton ){
    emit clickXY(event->x(),event->y());

  }
}


void Plotter::mudaCor(){
  int r, g, b;
  QColor cor;
  QMessageBox box;
  QString msg;
  QColorDialog d;
  d.exec();
  cor = d.selectedColor();
  lineColor = cor;
  r = cor.red();
  g = cor.green();
  b = cor.blue();
  msg = "r = <b>"+QString::number(r)+"</b> <br>"+
      "g = <b>"+QString::number(g)+"</b> <br>"+
      "b = <b>"+QString::number(b)+"</b>";
  box.setText(msg);
  box.exec();
  repaint();
}

