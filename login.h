#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <homepage.h>
#include<registration.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Login *ui;
    HomePage *homepage;
    registration *REGISTRATION;


};
#endif // LOGIN_H
