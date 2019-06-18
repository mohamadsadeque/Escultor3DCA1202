#ifndef DIALOGSPHERE_H
#define DIALOGSPHERE_H

#include <QDialog>

namespace Ui {
class DialogSphere;
}

class DialogSphere : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSphere(QWidget *parent = nullptr);
    ~DialogSphere();
    bool getPut();
    int getRaio();

private:
    Ui::DialogSphere *ui;
};

#endif // DIALOGSPHERE_H
