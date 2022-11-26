#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QList"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionnew_game, SIGNAL(triggered()), this, SLOT(actionnew_game()));
    connect(ui->actionexit, SIGNAL(triggered()), this, SLOT(action_exit()));

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(btn_clicked()));

    connect(this, SIGNAL(game_over()), this, SLOT(game_over_msg()));

    ui->statusBar->showMessage("Current: Player1 | Next: Player2 | --> Game Design & Develop By Team 4Alpha --> BUBT");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actionnew_game()
{
    nextPlayer = 1;
    clickcount = 0;
    ui->statusBar->showMessage("Current: Player1 | Next: Player2 | --> Game Design & Develop By Team 4Alpha --> BUBT");
    ui->pushButton->setText("");
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");
}

void MainWindow::action_exit()
{
    this->close();
}

void MainWindow::btn_clicked()
{
    auto button = (QPushButton*)sender();
    if (nextPlayer == 1 && button->text() == "")
    {
        ui->statusBar->showMessage("Current: Player2 | Next: Player1 | --> Game Design & Develop By Team 4Alpha --> BUBT");
        nextPlayer = 0;
        button->setText("X");
    }
    else
    {
        if (nextPlayer == 0 && button->text() == "")
        {
            ui->statusBar->showMessage("Current: Player1 | Next: Player2 | --> Game Design & Develop By Team 4Alpha --> BUBT");
            nextPlayer = 1;
            button->setText("O");
        }
    }

    ++clickcount;
    checkWinner();
    if (clickcount == 9)
    {
        emit game_over();
    }
}

void MainWindow::displayWinner(QPushButton* btn)
{
    if (btn->text() == 'X')
        ui->statusBar->showMessage("Player1 win. | --> Game Design & Develop By Team 4Alpha --> BUBT");
    else
        ui->statusBar->showMessage("Player2 win. | --> Game Design & Develop By Team 4Alpha --> BUBT");
}

bool MainWindow::checkLines(QPushButton* btn1, QPushButton* btn2, QPushButton* btn3)
{
    return (btn1->text() == btn2->text() && btn2->text() == btn3->text() && btn1->text() != "") ? true : false;
}

void MainWindow::checkWinner()
{
    if (checkLines(ui->pushButton, ui->pushButton_2, ui->pushButton_3))
    {
        displayWinner(ui->pushButton);
        return;
    }
    if (checkLines(ui->pushButton, ui->pushButton_4, ui->pushButton_7))
    {
        displayWinner(ui->pushButton);
        return;
    }
    if (checkLines(ui->pushButton, ui->pushButton_5, ui->pushButton_9))
    {
        displayWinner(ui->pushButton);
        return;
    }
    if (checkLines(ui->pushButton_9, ui->pushButton_6, ui->pushButton_3))
    {
        displayWinner(ui->pushButton_9);
        return;
    }
    if (checkLines(ui->pushButton_9, ui->pushButton_8, ui->pushButton_7))
    {
        displayWinner(ui->pushButton_9);
        return;
    }
    if (checkLines(ui->pushButton_4, ui->pushButton_5, ui->pushButton_6))
    {
        displayWinner(ui->pushButton_5);
        return;
    }
    if (checkLines(ui->pushButton_2, ui->pushButton_5, ui->pushButton_8))
    {
        displayWinner(ui->pushButton_5);
        return;
    }
    if (checkLines(ui->pushButton_3, ui->pushButton_5, ui->pushButton_7))
    {
        displayWinner(ui->pushButton_5);
        return;
    }

}

void MainWindow::game_over_msg()
{
    ui->statusBar->showMessage("Game Over! | Press 'Reset Game' To Play Again");
}



