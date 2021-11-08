#ifndef USERLOGIN_H
#define USERLOGIN_H
//

#include <QVector>
#include <QMainWindow>
#include <QString>
#include "mainwindow.h"


namespace Ui{
class UserLogin;
}

class UserLogin : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_pbLogin_clicked();

private:
    Ui::UserLogin *ui;
    QMainWindow *mainWindow;
    QVector<classCitizen*> userList;
    classCitizen *ptrCurrentCitizen;

    void pbHome();
    void pbMyDetails();
    void pbContactUs();
    void submitReport();
    void logout();

public:
    explicit UserLogin(QWidget *parent = nullptr);
    explicit UserLogin(classCitizen* ptrCurrentCitizen, QWidget *parent = nullptr);
    ~UserLogin();


    void accessLUI();

};

#endif // USERLOGIN_H
