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

private:
    Ui::UserMainWindow *ui;
    UserMain *userMain;
};

#endif // USERMAINWINDOW_H
