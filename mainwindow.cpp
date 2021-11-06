#include "mainwindow.h"
#include "ui_mainwindow.h"
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


// { Overloading constructors begins :

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    ui->lblSavedMessage->hide(); // "Saved" pop up message on Add User Page hidden on launch

    // Manual Connection
    connect(ui->pbAddUser, &QPushButton::clicked, this, &MainWindow::addNewUser);
    connect(ui->pbSave, &QPushButton::clicked, this, &MainWindow::saveUser);
    connect(ui->pbLogout, &QPushButton::clicked, this, &MainWindow::logout);
    connect(ui->pbLoadUsers, &QPushButton::clicked, this, &MainWindow::loadUser);
    connect(ui->pbEditUser, &QPushButton::clicked, this, &MainWindow::editUser);
    connect(ui->pbSaveEdit, &QPushButton::clicked, this, &MainWindow::saveEdit);
    connect(ui->listAllUsersNew, &QListWidget::itemClicked, this, &MainWindow::selectUserDetails);
    connect(ui->pbSearch, &QPushButton::clicked, this, &MainWindow::searchUser);


   //Mac Create Directory
   QDir pathDir("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files");
       if(!pathDir.exists())
       {
           QDir().mkdir("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files");
       }

}

// Second constructor passing double pointer for classCitizen ptrNewCitizen.
MainWindow::MainWindow(classCitizen*& ptrNewCitizen, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptrNewCitizen = &ptrNewCitizen;
}

// Second constructor passing single pointer for classCitizen ptrCurrentCitizen.
MainWindow::MainWindow(classCitizen* ptrCurrentCitizen, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptrCurrentCitizen = ptrCurrentCitizen;
}

// } Overloading constructors ends.



// { Class MainWindow methods begin:

// Login Functions
//*********************************************************

// Logout Function
void MainWindow::logout()
{
    Login *login;
    close();
    //Displays Login window
    login = new Login(this);
    login->show();
}


// Admin Functions
//*********************************************************

// Pushing new users information to a vector of pointers
void MainWindow::addNewUser()
{
    classCitizen* newCitizen = nullptr;

    if (newCitizen != nullptr)
    {
         userList.push_back(newCitizen);
         ui->listAllUsersNew->addItem(newCitizen->getName());
    }
}

// Saving new user information to file
void MainWindow::saveUser()
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
        ui->listAllUsersNew->addItem(ptrNewCitizen->getNHI()); // Displays added user name to list widget on "all users page"
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
            out << userList.at(i)->getName() << ",";
            out << userList.at(i)->getContactNumber() << ",";
            out << userList.at(i)->getEmailAddress() << ",";
            out << userList.at(i)->getDateOfBirth() << ",";
            out << userList.at(i)->getNHI() << ",";
            out << userList.at(i)->getCVN()<< Qt::endl;
           }
        // Flushing file and then closing.
        out.flush();
        outputFile.close();

        // Clear input from labels
        ui->addUserName->clear();
        ui->addUserPhone->clear();
        ui->addUserEmail->clear();
        ui->addUserDOB->clear();
        ui->addUserNHI->clear();
        ui->addUserCVN->clear();

        // Displaying saved message for admin user
        ui->lblSavedMessage->show();

} // End of saveUser()



// Loading Users from Text File on All Users Pages
void MainWindow::loadUser()
{
    // Open file for reading
    QFile inputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/Citizens.txt");
    //QFile inputFile("Citizens.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice:: Text);
    QTextStream read(&inputFile);

    // Clearing existing data from vector
   for (int i = 0; i< userList.size(); i++)
    {
        delete userList.at(i);
    }
   // Clearing ui
    userList.clear();
    ui->listAllUsersNew->clear();


   while(!read.atEnd()) // Start while loop to read file and push info to vec
   {
       // Reading from file and seperating info at text.split()
        QString text = read.readLine();
        QStringList info = text.split(",");


       // Add read information to ui
       ui->listAllUsersNew->addItem(info.at(4));

       // Adding file information to vector
       classCitizen* temp = new classCitizen(info.at(0), info.at(1),info.at(2),info.at(3),info.at(4),info.at(5));
       userList.push_back(temp);
   } // End while


   // Flushing file and then closing.
   read.flush();
   inputFile.close();


} // End of loadUser()


// Showing User's Data when selected from list widget
void MainWindow::selectUserDetails()
{
    int index = ui->listAllUsersNew->currentRow();

    if (index >= 0)
    {
        classCitizen *selectedUser = userList.at(index);
        ui->showUserName->setText(selectedUser->getName());
        ui->showUserPhone->setText(selectedUser->getContactNumber());
        ui->showUserEmail->setText(selectedUser->getEmailAddress());
        ui->showUserDOB->setText(selectedUser->getDateOfBirth());
        ui->showUserNHI->setText(selectedUser->getNHI());
        ui->showUserCVN->setText(selectedUser->getCVN());
        //ui->showUserGuardian->setText(selectedUser->getGuardian)
        /// Still need to add guardian, notes, files in image paths
    }
}

// Search for user in AllUsersList
void MainWindow::searchUser()
{
    QString search = ui->labelSearchUser->text();

    if(search !="")
    {
        // Loop to remove highlight on orginal search before highlighting next search
        for (int i=0; i < ui->listAllUsersNew->count(); i++)
        {
            QListWidgetItem* user = ui->listAllUsersNew->item(i);
            user->setBackground(Qt::transparent);
        }

        QList<QListWidgetItem*> list = ui->listAllUsersNew->findItems(search, Qt::MatchContains);

        // Loop to highlight matching users
        for (int i = 0; i <list.count(); i++)
        {
            QListWidgetItem* item = list.at(i);
            item->setBackground(Qt::cyan);
        }
    }
    else
    {
        // Loop to remove highlight
        for (int i = 0; i < ui->listAllUsersNew->count(); i++)
        {
            QListWidgetItem* item = ui->listAllUsersNew->item(i);
            item->setBackground(Qt::transparent);
        }
    }
}



// ****************************************************************************************************************  NEW EDIT USER
// NEW EDIT USER FUNCTIONS

// Editing existing users information
void MainWindow:: editUser()
{

    int listNum = ui->listAllUsersNew->currentRow();

    if (listNum != -1)
    {
        ptrCurrentCitizen = userList.at(listNum);

            if (ptrCurrentCitizen != nullptr)
           {
                // Changing UI page
                ui->stackedWidget->setCurrentIndex(3);

                ui->NHIDisplayLabel->setText(ptrCurrentCitizen->getNHI());
                ui->CVNDisplayLabel->setText(ptrCurrentCitizen->getCVN());

                // Clearing ui
             // ui->listAllUsersNew->clear();
              //ui->listAllUsersNew->addItem(ptrCurrentCitizen->getNHI());

            }
            else
            {
                QMessageBox messageBox;
                messageBox.setText("ptrCurrentCitizen = nullptr");
                messageBox.exec();

            }

    }
    else
    {
        QMessageBox messageBox;
        messageBox.setText("listNum = -1");
        messageBox.exec();
    }

}


// Saving edited information and re-writing file
void MainWindow::saveEdit()
{

    // Retrieving edited information from ui
    QString editName = ui->editUserName->text();
    QString editPhone = ui->editUserPhone->text();
    QString editEmail = ui->editUserEmail->text();
    QString editDob = ui->editUserDOB->text();

    if(editName.trimmed() != "")
    {
         // Changing the information of the current citizen
        ptrCurrentCitizen->setName(editName);
        ptrCurrentCitizen->setContactNumber(editPhone);
        ptrCurrentCitizen->setEmailAddress(editEmail);
        ptrCurrentCitizen->setDateOfBirth(editDob);

        // Writing edit to file
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
                out << userList.at(i)->getCVN()<< Qt::endl;
               }
            // Flushing file and then closing.
            out.flush();
            outputFile.close();

            /// Arranging ui to meet ux standards
            // Clear input from edit labels
            ui->editUserName->clear();
            ui->editUserPhone->clear();
            ui->editUserEmail->clear();
            ui->editUserDOB->clear();
            ui->NHIDisplayLabel->clear();
            ui->CVNDisplayLabel->clear();

            // Changing input from view user labels
            ui->showUserName->setText(ptrCurrentCitizen->getName());
            ui->showUserPhone->setText(ptrCurrentCitizen->getContactNumber());
            ui->showUserEmail->setText(ptrCurrentCitizen->getEmailAddress());
            ui->showUserDOB->setText(ptrCurrentCitizen->getDateOfBirth());
            ui->showUserNHI->setText(ptrCurrentCitizen->getNHI());
            ui->showUserCVN->setText(ptrCurrentCitizen->getCVN());

            //Changing page back to All Users
            ui->stackedWidget->setCurrentIndex(1);

    }
    else
    {
        QMessageBox messageBox;
        messageBox.setText("Please enter all user information.");
        messageBox.exec();
    }


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
















// BROKEN CODE

//*********************************************************************************************************************************




// Function to edit existing user's data
/* void MainWindow::editUser()
{
    /// ******************* RAGHII'S ATTEMPT *********************

   int listNum = ui->listAllUsersNew->currentRow();

   if (listNum != -1)
   {

       ptrCurrentCitizen = userList.at(listNum);
     //  userList.clear(listNum);

           if (ptrCurrentCitizen != nullptr)
          {
               //ui->listAllUsersNew->addItem(ptrEditCitizen->getName());

               // Changing UI page
               ui->stackedWidget->setCurrentIndex(3);

               // Retrieving edited information
               QString editName = ui->addUserName->text();
               QString editPhone = ui->addUserPhone->text();
               QString editEmail = ui->addUserEmail->text();
               QString editDob = ui->addUserDOB->text();

               int index = ui->listAllUsersNew->currentRow();

               if (index >= 0)
               {
                   classCitizen *selectedUser = userList.at(index);

                     ui->NHIDisplayLabel->setText(selectedUser->getNHI());
                     ui->CVNDisplayLabel->setText(selectedUser->getCVN());
               }
               else
               {
                   QMessageBox messageBox;
                   messageBox.setText("User not found");
                   messageBox.exec();
               }


             //  userList.push_back(ptrCurrentCitizen);
           //    ptrCurrentCitizen->setNHI(editNhi);
             //  ptrCurrentCitizen->setCVN(editCvn);

               ui->listAllUsersNew->clear();
               ui->listAllUsersNew->addItem(ptrCurrentCitizen->getNHI());
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


    /// ******************* TESS' ATTEMPT *********************

    // Selected Item
   int listNumber = ui->listAllUsersNew->currentRow();

   if (listNumber >= 0)
   {
       classCitizen* ptrCurrentCitizen = userList.at(listNumber);

       if (ptrCurrentCitizen != nullptr)
       {
           //ui->listAllUsersNew->addItem(ptrEditCitizen->getName());

           // Changing UI page
           ui->stackedWidget->setCurrentIndex(3);

           // Populating Labels with existing info
           ui->editUserName->setText(ptrCurrentCitizen->getName());
           ui->editUserPhone->setText(ptrCurrentCitizen->getContactNumber());
           ui->editUserEmail->setText(ptrCurrentCitizen->getEmailAddress());
           ui->editUserDOB->setText(ptrCurrentCitizen->getDateOfBirth());

           // Non-Editable Populations
           ui->NHIDisplayLabel->setText(ptrCurrentCitizen->getNHI());
           ui->CVNDisplayLabel->setText(ptrCurrentCitizen->getCVN());
           // ** NEED TO ADD IN GUARDIAN, VACC STATUS, RECORDS, & NOTES **
       }
       else
       {
           // Error Message
           QMessageBox messageBox;
           messageBox.setText("User not found");
           messageBox.exec();
       }

       ui->listAllUsersNew->clear();
       ui->listAllUsersNew->addItem(ptrCurrentCitizen->getNHI());
   }
} */

/* void MainWindow::saveEdit()
{

    ui->stackedWidget->setCurrentIndex(1);

    /// ******************* RAGHII'S ATTEMPT *********************

    QFile outputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/Citizens.txt");
    //QFile outputFile("Citizens.txt");
    QTextStream out(&outputFile);
    outputFile.open(QIODevice::WriteOnly | QIODevice:: Append | QIODevice::Text);

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

        // Clear input from labels
        ui->addUserName->clear();
        ui->addUserPhone->clear();
        ui->addUserEmail->clear();
        ui->addUserDOB->clear();
        ui->addUserNHI->clear();
        ui->addUserCVN->clear();


    /// ******************* TESS' ATTEMPT *********************

    QString editName = ui->addUserName->text();
    QString editPhone = ui->addUserPhone->text();
    QString editEmail = ui->addUserEmail->text();
    QString editDob = ui->addUserDOB->text();

    if(editName.trimmed() != "")
    {
        ptrCurrentCitizen->setName(editName);
        ptrCurrentCitizen->setContactNumber(editPhone);
        ptrCurrentCitizen->setEmailAddress(editEmail);
        ptrCurrentCitizen->setDateOfBirth(editDob);
    }

    QFile outputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/Citizens.txt");
    //QFile outputFile("Citizens.txt");
    QTextStream out(&outputFile);
    outputFile.open(QIODevice:: Append | QIODevice::Text);

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
}*/


