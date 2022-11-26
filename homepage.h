#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QDialog>
#include <tictactoe.h>
#include <chess.h>
#include <bird.h>
#include <mainwindow.h>
#include <Puzzle15.h>


namespace Ui {
class HomePage;
}

class HomePage : public QDialog
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::HomePage *ui;
    tictactoe *Tictactoe;
    chess *Chess;
    bird *Bird;
    MainWindow *MAINWINDOW;
    Puzzle15 *PUZZLE15;
};

#endif // HOMEPAGE_H
