#ifndef CHESS_H
#define CHESS_H

#include <QDialog>

namespace Ui {
class chess;
}

class chess : public QDialog
{
    Q_OBJECT

public:
    explicit chess(QWidget *parent = nullptr);
    ~chess();

private:
    Ui::chess *ui;
};

#endif // CHESS_H
