//
#include "mainwindow.h"
#include "userlogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.hide();

    UserLogin login;
    login.show();

    return a.exec();
}
