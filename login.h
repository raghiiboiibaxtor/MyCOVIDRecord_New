#ifndef LOGIN_H
#define LOGIN_H
//

#include <QVector>
#include <QMainWindow>
#include <QString>
#include "usermain.h"


namespace Ui{
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_pbLogin_clicked();

private:
    //QString userLoginNHI;
     Ui::Login *ui;
    QMainWindow *mainWindow;

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

   // void setUserLogin(QString userLoginNHI);
   // QString getUserLogin();
   // UserMain* ptrUserMain = new UserMain();

    //friend class UserMain;
    //friend void accessUserLogin(QString userLoginNHI);

    void accessLUI();

};

#endif // LOGIN_H
