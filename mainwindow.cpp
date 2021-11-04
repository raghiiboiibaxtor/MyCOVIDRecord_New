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


// Main Window
//*********************************************************


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    // Manual Connection
    connect(ui->pbAddUser, &QPushButton::clicked, this, &MainWindow::mainAddNewUser);
    connect(ui->pbLogout, &QPushButton::clicked, this, &MainWindow::logout);
    connect(ui->pbLoadUsers, &QPushButton::clicked, this, &MainWindow::loadUser);
    connect(ui->pbEditUser, &QPushButton::clicked, this, &MainWindow::editUser);
    connect(ui->pbSaveEdit, &QPushButton::clicked, this, &MainWindow::saveEdit);





   // Mac Create Directory
   QDir pathDir("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files");
       if(!pathDir.exists())
       {
           QDir().mkdir("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files");
       }

}

// Second constructor
MainWindow::MainWindow(classCitizen*& ptrNewCitizen, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptrNewCitizen = &ptrNewCitizen;
}


// Login Functions
//*********************************************************

// Logout Function
void MainWindow::logout()
{
    close();
    //Displays Login window
    login = new Login(this);
    login->show();
}


// Admin Functions
//*********************************************************

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
        userList.push_back(ptrNewCitizen);
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
   //QFile outputFile("Citizens.txt");

    /// Mac File Path
    QFile outputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/Citizens.txt");
    QTextStream out(&outputFile);

    outputFile.open(QIODevice::WriteOnly | QIODevice::Text);

        for (int i = 0; i < userList.size(); i++)
           {
            out << userList.at(i)->getName() << ", ";
            out << userList.at(i)->getContactNumber() << ", ";
            out << userList.at(i)->getEmailAddress() << ", ";
            out << userList.at(i)->getDateOfBirth() << ", ";
            out << userList.at(i)->getNHI() << ", ";
            out << userList.at(i)->getAccessNumber()<< Qt::endl;
           }
        // Flushing file and then closing.
        out.flush();
        outputFile.close();

         ui->addUserName->clear();

  //  }

}

void MainWindow::loadUser()
{
    QFile inputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/Citizens.txt");
    //QFile inputFile("Citizens.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice:: Text);
    QTextStream read(&inputFile);

   for (int i = 0; i< userList.size(); i++)
    {
        delete userList.at(i);
    }
    userList.clear();
    ui->listAllUsersNew->clear();


   while(!read.atEnd()) // Start while loop to read file and push info to vec
   {
       // Reading from file and seperating info at text.split()
        QString text = read.readLine();
        QStringList info = text.split(",");


       // Add read information to ui
       ui->listAllUsersNew->addItem(info.at(0));


       // Adding file information to vector
       classCitizen* temp = new classCitizen(info.at(0), info.at(1),info.at(2),info.at(3),info.at(4),info.at(5));
       userList.push_back(temp);
   } // End while


   // Flushing file and then closing.
   read.flush();
   inputFile.close();
}


void MainWindow::editUser()
{
   int listNum = ui->listAllUsersNew->currentRow();

   if (listNum != -1)
   {
       classCitizen* ptrNewCitizen = userList.at(listNum);

           if (ptrNewCitizen != nullptr)
          {
               //ui->listAllUsersNew->addItem(ptrEditCitizen->getName());

               // Changing page
               ui->stackedWidget->setCurrentIndex(2);
             // ui->listAllUsersNew->clearSelection();

               // Retrieving edited information
               QString editName = ui->addUserName->text();
               QString editPhone = ui->addUserPhone->text();
               QString editEmail = ui->addUserEmail->text();
               QString editDob = ui->addUserDOB->text();
               QString editNhi = ui->addUserNHI->text();
               QString editCvn = ui->addUserCVN->text();

               ptrNewCitizen->setName(editName);
               ptrNewCitizen->setContactNumber(editPhone);
               ptrNewCitizen->setEmailAddress(editEmail);
               ptrNewCitizen->setDateOfBirth(editDob);
               ptrNewCitizen->setNHI(editNhi);
               ptrNewCitizen->setCVN(editCvn);

               //classCitizen *ptrNewCitizen = new classCitizen(editName, editPhone, editEmail, editDob, editNhi, editCvn);
              // userList.append(ptrEditCitizen);
              /* userList.clear();
               ui->listAllUsersNew->clear();*/
              // choice = listAllUsersNew.selectedItems();
             // ui->listAllUsersNew->addItem(ptrEditCitizen->getName());

              // ui->listAllUsersNew->addItem(ptrEditCitizen->getName());

               //ui->listAllUsersNew->setText(ptrEditCitizen->getName());


             /*for (int i = 0; i< userList.size(); i++)
                {
                    delete userList.at(i);
                }
               userList.clear();*/



           }

           else
           {
               QMessageBox messageBox;
               messageBox.setText("ptrEditCitizen is pointing to nullptr");
               messageBox.exec();
           }
   }

   else
   {
       QMessageBox messageBox;
       messageBox.setText("The listNum is != to current row");
       messageBox.exec();
   }

}


void MainWindow :: saveEdit()
{

}


// Stacked Widget Button Slots
//*********************************************************

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

//*********************************************************

MainWindow::~MainWindow()
{
    for (int i=0; i<userList.size(); i++)
    {
        delete userList.at(i);
    }
    userList.clear();

    delete ui;
}




