#ifndef DIALOGVOXEL_H
#define DIALOGVOXEL_H

#include <QDialog>

namespace Ui {
class DialogVoxel;
}

class DialogVoxel : public QDialog
{
    Q_OBJECT

public:
    explicit DialogVoxel(QWidget *parent = nullptr);
    ~DialogVoxel();

private:
    Ui::DialogVoxel *ui;
};

#endif // DIALOGVOXEL_H
