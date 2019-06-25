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
#include <qdebug.h>
#include <sculptor3d.h>

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    linhas = 100;
    colunas = 100;
    planos = 100;
    planoAtual = 0;
    referencia = 0;
    raio = 20;
    escultor = new sculptor3d(linhas,colunas,planos);

    setMouseTracking(true);
    corAtual = QColor(150,200,255);
}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush,brush2,brushSeta;
    QPen pen,penOff;


    //for(int i =0; i<planos;i++) matriz[i][i][i] = true;

    switch (referencia) {
    case 0:
        largura = width()/(colunas);
        altura = height()/(linhas);
        qDebug()<< largura << altura;
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

    brush.setColor(corAtual);
    brush.setStyle(Qt::SolidPattern);
    brush2.setColor(QColor(255,255,255));
    brush2.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(1);
    penOff.setColor(QColor(100,100,100));
    penOff.setStyle(Qt::DashLine);
    painter.setBrush(brush);
    painter.setPen(pen);
    pen.setColor(QColor(0,0,0));
    painter.setBrush(brushSeta);

    for(int i = 0; i<colunas;i++){
        for(int j = 0; j<linhas; j++){
            if(escultor->voxelIsOn(i,j,planoAtual,r,g,b,a)){
                corAtual = QColor(r,g,b,a);
                 painter.setPen(pen);
                brush.setColor(corAtual);
                painter.setBrush(brush);
            }else{
                painter.setPen(penOff);
                painter.setBrush(brush2);
            }
            painter.drawRect(largura*i,altura*j,largura,altura);
        }
    }

}

void Plotter::setBoxLargura(int x){
    boxLargura = x;
}

void Plotter::setBoxProfundidade(int x){
    boxProfundidade = x;
}

void Plotter::setBoxAltura(int x){
    boxAltura = x;
}

void Plotter::configurarEscultor(int x, int y, int z){
    escultor = new sculptor3d(x, y, z);
}

void Plotter::extrairArquivo(QString filename)
{
    escultor->writeOFF(filename.toUtf8().constData());
}

void Plotter::limparMatriz()
{
    for(int k =0;k<100;k++)
        for(int i =0; i<100; i++)
            for(int j=0;j<100;j++)
                matriz[i][j][k] = false;
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
    int xPos,yPos,zPos;

    switch (referencia) {
    case 0:
        xPos = x/largura;
        yPos = y/altura;
        zPos = planoAtual;
        break;
    case 1:
        xPos = x/largura;
        yPos = planoAtual;
        zPos = y/altura;
        break;
    case 2:
        xPos = planoAtual;
        yPos = x/largura;
        zPos = y/altura;
        break;
    }

        matriz[xPos][yPos][zPos] = !matriz[xPos][yPos][zPos];

        switch (forma) {
            case 0:
                escultor->putSphere(xPos, yPos, zPos, raio);

                qDebug("linhas: %d, colunas: %d, planos: %d", linhas, colunas, planos);
                qDebug("Inseri Esfera x: %d, y: %d, z: %d", xPos, yPos, zPos);
                break;
            case 1:
                escultor->cutSphere(xPos, yPos, zPos, raio);

                qDebug("Removi Esfera x: %d, y: %d, z: %d", xPos, yPos, zPos);
                break;
            case 2:
                escultor->putEllipsoid(xPos, yPos, zPos, raioX, raioY, raioZ);

                qDebug("Inseri Elipsóide x: %d, y: %d, z: %d", xPos, yPos, zPos);
                break;
            case 3:
                escultor->cutEllipsoid(xPos, yPos, zPos, raioX, raioY, raioZ);

                qDebug("Removi Elipsóide x: %d, y: %d, z: %d", xPos, yPos, zPos);
                break;
            case 4:
                escultor->putVoxel(xPos, yPos, zPos);
                qDebug("Inseri Voxel x: %d, y: %d, z: %d", xPos, yPos, zPos);
                break;
            case 5:
                escultor->cutVoxel(xPos, yPos, zPos);
                qDebug("Removi Voxel x: %d, y: %d, z: %d", xPos, yPos, zPos);
                break;
            case 6:
                qDebug() << "============================" <<
                         "xPos :" << xPos <<
                         "yPos :" << yPos <<
                         "zPos :" << zPos<<
                         "============================" <<
                         "xPos+Largura" << xPos+boxLargura <<
                         "yPos+Altura" << yPos+boxAltura <<
                         "yPos+Profundidade" << zPos+boxProfundidade
                ;

                escultor->putBox(xPos, xPos+boxLargura, yPos, yPos+boxAltura, zPos, zPos+boxProfundidade);
                qDebug("Inseri Caixa x: %d, y: %d, z: %d", xPos, yPos, zPos);
                break;
            case 7:
                escultor->cutBox(xPos, xPos+boxLargura, yPos, yPos+boxAltura, zPos, zPos+boxProfundidade);
                qDebug("Removi Caixa x: %d, y: %d, z: %d", xPos, yPos, zPos);
                break;
        }
    repaint();
}

void Plotter::setRefZ()
{
    referencia = 0;
    repaint();
}

void Plotter::mudaForma(int a)
{
    forma = a;
}

void Plotter::setRaio(int r)
{
    raio = r;
}

void Plotter::setRaioX(int r)
{
    raioX = r;
}

void Plotter::setRaioY(int r)
{
    raioY = r;
}

void Plotter::setRaioZ(int r)
{
    raioZ = r;
}

void Plotter::mudaCor(QColor cor)
{
    corAtual = cor;

    escultor->setColor(corAtual.redF(),
                       corAtual.greenF(),
                       corAtual.blueF(),
                       corAtual.alphaF());

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




