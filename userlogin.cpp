//

#include "userlogin.h"
#include "ui_userlogin.h"
#include "mainwindow.h"

#include <QListWidgetItem>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

//UserMain userLoginDetails;

UserLogin::UserLogin(QWidget *parent) : QMainWindow(parent), ui(new Ui::UserLogin)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    ui->labelConfirmation->hide();

    connect(ui->pbLogout, &QPushButton::clicked, this, &UserLogin::logout);
    connect(ui->pbHome, &QPushButton::clicked, this, &UserLogin::pbHome);
    connect(ui->pbMyDetails, &QPushButton::clicked, this, &UserLogin::pbMyDetails);
    connect(ui->pbContactUs, &QPushButton::clicked, this, &UserLogin::pbContactUs);
    connect(ui->pbSendMessage, &QPushButton::clicked, this, &UserLogin::submitReport);

    // Home page display image
    /*QPixmap pixmap("/res/images/admin.png");
    ui->imgHome->setPixmap(pixmap);
    ui->imgHome->setScaledContents(true);*/

}

// Second constructor passing single pointer for classCitizen ptrCurrentCitizen.
UserLogin::UserLogin(classCitizen* ptrCurrentCitizen, QWidget *parent) : QMainWindow(parent), ui(new Ui::UserLogin)
{
    ui->setupUi(this);
    this->ptrCurrentCitizen = ptrCurrentCitizen;
}

UserLogin::UserLogin(citizenReport*& ptrNewReport, QWidget *parent) : QMainWindow(parent), ui(new Ui::UserLogin)
{
    ui->setupUi(this);
    this->ptrNewReport = &ptrNewReport;
}

UserLogin::~UserLogin()
{
    for (int i=0; i<reportList.size(); i++)
    {
        delete reportList.at(i);
    }
    reportList.clear();

    delete ui;
}

// Login Function = if default info entered, will direct to Admin Window, else will change to User Index
void UserLogin::on_pbLogin_clicked()
{
    QString email = ui->editEmail->text();
    QString NHI = ui->editNHI->text();
    QString accessNumber = ui->editAccessNumber->text();

    // Check if login input matches, if not, an error message will be displayed
    // If correct, directed to Home Page
    if (email == "1") // Admin Login Check Loop
    {
        if (NHI == "1")
        {
            if (accessNumber == "1")
            {
                this->hide();
                // Displays Admin Home Page
                mainWindow = new MainWindow(this);
                mainWindow->show();
            }
            else
            {
                ui->labelError->setText("Incorrect Access Number Entered");
            }
        }
        else
        {
            ui->labelError->setText("Incorrect NHI Number Entered");
        }
    }
    else if(email != "1")
    {
        //QFile inputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/Citizens.txt");
        QFile inputFile("Citizens.txt");
        inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream read(&inputFile);

        // Clearing existing data from vector
        for (int i = 0; i< userList.size(); i++)
        {
            delete userList.at(i);
        }
        // Clearing ui
        userList.clear();

        while (!read.atEnd())
        {
            QString line = read.readLine();
            QStringList info = line.split(",");


            QString fileEmail = info.at(2);
            QString fileNHI = info.at(4);


            if (email == fileEmail && NHI == fileNHI) // User Login Check Loop
            {
                if (accessNumber == "1234")
                {
                    // Adding file information to vector
                    classCitizen* temp = new classCitizen(info.at(0), info.at(1), info.at(2), info.at(3), info.at(4), info.at(5), info.at(6), info.at(7), info.at(8), info.at(9), info.at(10),
                                                          info.at(11), info.at(12), info.at(13), info.at(14), info.at(15), info.at(16), info.at(17));
                    userList.push_back(temp);

                    ui->showUserName->setText(temp->getName());
                    ui->showUserNumber->setText(temp->getContactNumber());
                    ui->showUserEmail->setText(temp->getEmailAddress());
                    ui->showUserDOB->setText(temp->getDateOfBirth());
                    ui->showUserNHI->setText(temp->getNHI());
                    ui->showUserCV->setText(temp->getCVN());
                    ui->showUserEmergency->setText(temp->getEmergencyContact());
                    ui->showUserVaccStatus->setText(temp->getVaccineStatus());
                    ui->showDose1Name->setText(temp->getVaccineName1());
                    ui->showDose1Batch->setText(temp->getBatchNumber1());
                    ui->showDose1Date->setText(temp->getDateGiven1());
                    ui->showDose2Name->setText(temp->getVaccineName2());
                    ui->showDose2Batch->setText(temp->getBatchNumber2());
                    ui->showDose2Date->setText(temp->getDateGiven2());
                    QPixmap pixmap(temp->getCertificate());
                    ui->showCertificate->setPixmap(pixmap);
                    ui->showCertificate->setScaledContents(true);
                    QPixmap pixmap1(temp->getQRCode());
                    ui->showQRCode->setPixmap(pixmap1);
                    ui->showQRCode->setScaledContents(true);
                    QPixmap pixmap2(temp->getTestResult());
                    ui->showTestResults->setPixmap(pixmap2);
                    ui->showTestResults->setScaledContents(true);

                    ui->editPreferredName->setText(temp->getName());
                    ui->editPreferredContact->setText(temp->getEmailAddress());

                    ui->stackedWidget->setCurrentIndex(1);
                    ui->labelUserName->setText(info.at(0));
                }
                else
                {
                    ui->labelError->setText("Incorrect Access Number Entered");
                }
            }
            else if (email != fileEmail)
            {
                ui->labelError->setText("Incorrect Email Entered");
            }
            else
            {
                ui->labelError->setText("Incorrect NHI Number Entered");
            }
        }

        //Flushing file and then closing.
        read.flush();
        inputFile.close();
    }
    else
    {
        ui->labelError->setText("Incorrect Email Entered");
    }
}

// Report Function
//*********************************************************
void UserLogin::submitReport()
{
    QString addName = ui->editPreferredName->text();
    QString addContact = ui->editPreferredContact->text();
    QString addCategory = ui->cbReportCategory->currentText();
    QString addSubject = ui->editReportSubject->text();
    QString addDetails = ui->editReportDetails->toPlainText();

    if (addDetails.trimmed() != "")
    {
        citizenReport *ptrNewReport = new citizenReport(addName, addContact, addCategory, addSubject, addDetails);
        reportList.push_back(ptrNewReport);
    }
    else
    {
       QMessageBox messageBox;
       messageBox.setText("Please enter details...");
       messageBox.exec();
    }

    // Writing to file
    /// Windows File Path
    QFile outputFile("UserReports.txt");
    /// Mac File Path
    //QFile outputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/UserReports.txt");

    QTextStream out(&outputFile);
    outputFile.open(QIODevice::WriteOnly | QIODevice::Text);

    for (int i = 0; i < reportList.size(); i++)
       {
        out << reportList.at(i)->getName() << ",";
        out << reportList.at(i)->getContact() << ",";
        out << reportList.at(i)->getCategory() << ",";
        out << reportList.at(i)->getSubject() << ",";
        out << reportList.at(i)->getDetails()<< Qt::endl;
       }


    // Flushing file and then closing.
    out.flush();
    outputFile.close();

    // Clear input from labels
    ui->editReportSubject->clear();
    ui->editReportDetails->clear();

    // Displaying saved message for admin user
    ui->labelConfirmation->show();
}


// Logout Function
void UserLogin::logout()
{
    UserLogin *login;
    close();
    //Displays Login window
    login = new UserLogin(this);
    login->show();
}

/// Home Menu Button
void UserLogin::pbHome()
{
    ui->stackedWidget2->setCurrentIndex(0);
}
/// User Profile Menu Button
void UserLogin::pbMyDetails()
{
    ui->stackedWidget2->setCurrentIndex(1);
}
/// Contact Menu Button
void UserLogin::pbContactUs()
{
    ui->stackedWidget2->setCurrentIndex(2);

    citizenReport* ptrNewReport = nullptr;

    if (ptrNewReport != nullptr)
    {
        reportList.push_back(ptrNewReport);
    }
}
