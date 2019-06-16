#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>


class Plotter : public QWidget
{
    Q_OBJECT
private:
    int linhas,colunas,planos,planoAtual;
    int timerId;
    QColor lineColor;
    int cor;
    QAction *actionMudaCor;


public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void moveX(int);
    void moveY(int);
    void clickX(int);
    void clickY(int);

public slots:
    void mudaLinhas(int l);
    void mudaColunas(int c);
    void mudaPlanos(int p);
    void olhaPlano(int p);

};

#endif // PLOTTER_H
