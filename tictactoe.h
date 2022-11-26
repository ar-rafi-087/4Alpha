#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QDialog>

namespace Ui {
class tictactoe;
}

class tictactoe : public QDialog
{
    Q_OBJECT

public:
    explicit tictactoe(QWidget *parent = nullptr);
    ~tictactoe();



private:
    Ui::tictactoe *ui;
};

#endif // TICTACTOE_H
