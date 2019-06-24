#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void abreNovoArquivo();
    void fecha();
    void selecionaCor();
    void configuraEsfera();
    void configuraElipsoide();
    void configuraVoxel();
    void configuraBox();
    void abrirArquivo();
    void salvarArquivo();


private slots:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
