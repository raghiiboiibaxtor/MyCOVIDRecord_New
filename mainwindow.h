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

    QString certificateImage;
    QString qrCodeImage;
    QString testResultImage;
    QString userProfilePicture;

    void pbHome();

    void addNewUser();
    void addCertificateImage();
    void addQRCodeImage();
    void addTestResultImage();
    void addUserPicture();
    void saveUser();

    void pbAllUsers();
    void selectUserDetails();
    void searchUser();

    void editUser();
    void editCertificateImage();
    void editQRCodeImage();
    void editTestResultImage();
    void editUserPicture();
    void saveEdit();

    void pbReports();
    void selectReportDetails();
    void searchCategory();

    void logout();  

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(classCitizen*& ptrNewCitizen, QWidget *parent = nullptr);
    explicit MainWindow(classCitizen* ptrCurrentCitizen, QWidget *parent = nullptr);
    explicit MainWindow(citizenReport* ptrCurrentReport, QWidget *parent = nullptr);
    //explicit MainWindow(classCitizen* ptrReportDetails, QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H


