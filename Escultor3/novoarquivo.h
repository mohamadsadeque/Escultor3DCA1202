#ifndef NOVOARQUIVO_H
#define NOVOARQUIVO_H

#include <QDialog>

namespace Ui {
class NovoArquivo;
}

class NovoArquivo : public QDialog
{
    Q_OBJECT

public:
    explicit NovoArquivo(QWidget *parent = nullptr);
    ~NovoArquivo();
    int getX();
    int getY();
    int getZ();


private:
    Ui::NovoArquivo *ui;
};

#endif // NOVOARQUIVO_H
