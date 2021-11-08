#ifndef USERLOGIN_H
#define USERLOGIN_H
//

#include <QVector>
#include <QMainWindow>
#include <QString>
#include "userlogin.h"


namespace Ui{
class UserLogin;
}

class UserLogin : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_pbLogin_clicked();

private:
    //QString userLoginNHI;
    Ui::UserLogin *ui;
    QMainWindow *mainWindow;

    void pbHome();
    void pbMyDetails();
    void pbContactUs();
    void submitReport();
    void logout();

public:
    explicit UserLogin(QWidget *parent = nullptr);
    ~UserLogin();


    void accessLUI();

};

#endif // USERLOGIN_H
