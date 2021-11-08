#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//
#include <QMainWindow>
#include <QListWidgetItem>
#include <QVector>
#include "classcitizen.h"
#include "citizenreport.h"
#include "userlogin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QVector<classCitizen*> userList;
    classCitizen** ptrNewCitizen;
    classCitizen *ptrCurrentCitizen;

    QVector<citizenReport*> reportList;
    citizenReport *ptrCurrentReport;


    void addNewUser();
    void saveUser();
    void logout();
    void loadUser();
    void editUser();
    void saveEdit();
    void selectUserDetails();
    void searchUser();
    void loadReports();
    void selectReportDetails();
    void searchCategory();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(classCitizen*& ptrNewCitizen, QWidget *parent = nullptr);
    explicit MainWindow(classCitizen* ptrCurrentCitizen, QWidget *parent = nullptr);
    explicit MainWindow(citizenReport* ptrCurrentReport, QWidget *parent = nullptr);
    //explicit MainWindow(classCitizen* ptrReportDetails, QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pbAllUsers_clicked();
    void on_pbAddUser_clicked();
    void on_pbHome_clicked();
    void on_pbReports_clicked();
    void on_pbEditUser_clicked();
};
#endif // MAINWINDOW_H


