#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "ui_adminAddUser.h"
//#include "adminadduser.h"
#include "classcitizen.h"
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    // Manual Connection
    connect(ui->pbAddUser, &QPushButton::clicked, this, &MainWindow::mainAddNewUser);
    connect(ui->pbLogout, &QPushButton::clicked, this, &MainWindow::logout);
    //connect(ui->listAllUsersNew, &QListWidget::itemClicked, this, &MainWindow::mainAddNewUser);


    /*classCitizen* newCitizen = nullptr;
    if (newCitizen != nullptr)
    {
         userList.push_back(newCitizen);
         ui->listAllUsersNew->addItem(newCitizen->getName());
    }*/

   /*QDir pathDir("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord/files");
       if(!pathDir.exists())
       {
           QDir().mkdir("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord/files");
       }*/

}


MainWindow::MainWindow(classCitizen*& ptrNewCitizen, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptrNewCitizen = &ptrNewCitizen;
}


// Login Functions
// ******************************************

// Logout Function
void MainWindow::logout()
{
    close();
    //Displays Login window
    login = new Login(this);
    login->show();
}


// Admin Functions
// ******************************************

// Add New User Function (Admin)
void MainWindow::mainAddNewUser()
{
    classCitizen* newCitizen = nullptr;

    if (newCitizen != nullptr)
    {
         userList.push_back(newCitizen);
         ui->listAllUsersNew->addItem(newCitizen->getName());
    }
}

void MainWindow::on_pbSave_clicked()
{
    QString addName = ui->addUserName->text();
    QString addPhone = ui->addUserPhone->text();
    QString addEmail = ui->addUserEmail->text();
    QString addDob = ui->addUserDOB->text();
    QString addNhi = ui->addUserNHI->text();
    QString addCvn = ui->addUserCVN->text();

    if (addName.trimmed() != "")
    {
        classCitizen *ptrNewCitizen = new classCitizen(addName, addPhone, addEmail, addDob, addNhi, addCvn);
        // *ptrNewCitizen = new classCitizen(addName, addPhone, addEmail, addDob, addNhi, addCvn);

        ui->listAllUsersNew->addItem(ptrNewCitizen->getName()); // Displays added user name to list widget on "all users page"
    }
    else
    {
       QMessageBox messageBox;
       messageBox.setText("Please enter name...");
       messageBox.exec();
    }

    // Writing to file

    /// Windows File Path
    QFile outputFile("Citizens.txt");

    /// Mac File Path
    //QFile outputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord/files/Citizens.txt");
   // if(!mFile.open(QFile::WriteOnly | QFile::Text)){

    outputFile.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!outputFile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox messageBox;
        messageBox.setText("File is not open");
        messageBox.exec();
    }
    else
    {
        QTextStream out(&outputFile);
        for (int i = 0; i < userList.size(); i++)
           {
            out << userList.at(i)->getName() << ", ";
            out << userList.at(i)->getContactNumber() << ", ";
            out << userList.at(i)->getEmailAddress() << ", ";
            out << userList.at(i)->getDateOfBirth() << ", ";
            out << userList.at(i)->getNHI() << ", ";
            out << userList.at(i)->getCVN();
           }
        out.flush();
        outputFile.close();
        // Flushing file and then closing.
    }
}

/// Home Menu Buttons
void MainWindow::on_pbHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


/// Add User Menu Buttons
void MainWindow::on_pbAllUsers_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/// All Users Menu Buttons
void MainWindow::on_pbAddUser_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}


// Destructor : End of Program.
// ******************************************

MainWindow::~MainWindow()
{
    for (int i=0; i<userList.size(); i++)
    {
        delete userList.at(i);
    }
    userList.clear();

    delete ui;
}
