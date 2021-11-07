#ifndef USERMAIN_H
#define USERMAIN_H

#include <QMainWindow>
#include <QString>
#include "login.h"
#include <QString>


namespace Ui{
class UserMainWindow;
}

class UserMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMain(QWidget *parent = nullptr);
    //explicit UserMain(QString *ptrTestLogin, QWidget *parent = nullptr);
    ~UserMain();

    void submitReport();
    void logout();
   // QString accessUserLogin(QString *ptrTestLogin);

private slots:
    void on_pbHome_clicked();
    void on_pbMyDetails_clicked();
    void on_pbContactUs_clicked();

private:
    Ui::UserMainWindow *ui;
    UserMain *userMain;
   // QString *ptrTestLogin;
};

#endif // USERMAINWINDOW_H
