#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QVector>
#include "classcitizen.h"
#include "login.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    //Login *login;
    QVector<classCitizen*> userList;
    classCitizen** ptrNewCitizen;
    void mainAddNewUser();
    void logout();
    void loadUser();
    void editUser();
    void saveEdit();
    void selectUserDetails();
    void searchUser();


public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(classCitizen*& ptrNewCitizen, QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pbAllUsers_clicked();
    void on_pbAddUser_clicked();
    void on_pbSave_clicked();
    void on_pbHome_clicked();
};
#endif // MAINWINDOW_H


