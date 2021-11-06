#ifndef USERMAIN_H
#define USERMAIN_H

#include <QMainWindow>

namespace Ui{
class UserMainWindow;
}

class UserMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMain(QWidget *parent = nullptr);
    ~UserMain();

    void logout();

private slots:
    void on_pbHome_clicked();

    void on_pbMyDetails_clicked();

    void on_pbContactUs_clicked();

private:
    Ui::UserMainWindow *ui;
    UserMain *userMain;
};

#endif // USERMAINWINDOW_H
