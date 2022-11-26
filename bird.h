#ifndef BIRD_H
#define BIRD_H

#include <QDialog>

namespace Ui {
class bird;
}

class bird : public QDialog
{
    Q_OBJECT

public:
    explicit bird(QWidget *parent = nullptr);
    ~bird();

private:
    Ui::bird *ui;
};

#endif // BIRD_H
