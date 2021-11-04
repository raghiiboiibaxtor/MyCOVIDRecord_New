#ifndef USERMAINWINDOW_H
#define USERMAINWINDOW_H

#include <QMainWindow>

namespace Ui{
class UserMainWindow;
}

class UserMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMainWindow(QWidget *parent = nullptr);
    ~UserMainWindow();

private:
    Ui::UserMainWindow *ui;
    UserMainWindow *userMainWindow;
};

#endif // USERMAINWINDOW_H
