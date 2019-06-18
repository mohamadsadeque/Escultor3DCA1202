#ifndef DIALOGELLIPSOID_H
#define DIALOGELLIPSOID_H

#include <QDialog>

namespace Ui {
class DialogEllipsoid;
}

class DialogEllipsoid : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEllipsoid(QWidget *parent = nullptr);
    ~DialogEllipsoid();
    bool getPut();
    int getRaioX();
    int getRaioY();
    int getRaioZ();


private:
    Ui::DialogEllipsoid *ui;
};

#endif // DIALOGELLIPSOID_H
