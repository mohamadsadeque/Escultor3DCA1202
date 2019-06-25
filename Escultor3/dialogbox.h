#ifndef DIALOGBOX_H
#define DIALOGBOX_H

#include <QDialog>

namespace Ui {
class DialogBox;
}

class DialogBox : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBox(QWidget *parent = nullptr);
    ~DialogBox();
    bool getPut();
    int getLargura();
    int getProfundidade();
    int getAltura();

private:
    Ui::DialogBox *ui;
};

#endif // DIALOGBOX_H
