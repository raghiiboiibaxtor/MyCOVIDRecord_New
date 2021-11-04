#ifndef LOGIN_H
#define LOGIN_H
//
//#include <QDialog>
#include <QMainWindow>
#include "mainwindow.h"
//#include "usermainwindow.h"

namespace Ui{
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pbLogin_clicked();

private:
    Ui::Login *ui;
    QMainWindow *mainWindow;
    QVector<classCitizen*> userList;
};

#endif // LOGIN_H
