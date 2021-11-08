//

#include "userlogin.h"
#include "ui_userlogin.h"
#include "mainwindow.h"

#include <QListWidgetItem>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QString>

//UserMain userLoginDetails;

UserLogin::UserLogin(QWidget *parent) : QMainWindow(parent), ui(new Ui::UserLogin)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->pbLogout, &QPushButton::clicked, this, &UserLogin::logout);
    connect(ui->pbHome, &QPushButton::clicked, this, &UserLogin::pbHome);
    connect(ui->pbMyDetails, &QPushButton::clicked, this, &UserLogin::pbMyDetails);
    connect(ui->pbContactUs, &QPushButton::clicked, this, &UserLogin::pbContactUs);
    connect(ui->pbSendMessage, &QPushButton::clicked, this, &UserLogin::submitReport);

    // Home page display image
    QPixmap pixmap(":/res/images/dp.png");
    ui->imgHome->setPixmap(pixmap);
    ui->imgHome->setScaledContents(true);
}

UserLogin::~UserLogin()
{
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
        inputFile.open(QIODevice::ReadOnly | QIODevice:: Text);
        QTextStream read(&inputFile);

        while (!read.atEnd())
        {
            QString line = read.readLine();
            QStringList info = line.split(", ");

            QString fileName = info.at(0);
            QString fileNumber = info.at(1);
            QString fileEmail = info.at(2);
            QString fileDOB = info.at(3);
            QString fileNHI = info.at(4);
            QString fileGuardian = info.at(5);
            //QString fileNotes = info.at(6);
            QString fileVacc = info.at(7);
            QString fileCV = info.at(8);


            if (email == fileEmail && NHI == fileNHI) // User Login Check Loop
            {
                if (accessNumber == "1234")
                {
                    ui->stackedWidget->setCurrentIndex(1);
                    ui->labelUserName->setText(fileName);
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

            ui->showUserName->setText(fileName);
            ui->showUserNumber->setText(fileNumber);
            ui->showUserEmail->setText(fileEmail);
            ui->showUserDOB->setText(fileDOB);
            ui->showUserNHI->setText(fileNHI);
            ui->showUserCV->setText(fileCV);
            ui->showUserGuardian->setText(fileGuardian);
            ui->showUserVaccStatus->setText(fileVacc);
            // ui->showUserNotes->setText(fileNotes);

            ui->editPreferredName->setText(fileName);
            ui->editPreferredContact->setText(fileEmail);
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
    // Writing to file
    /// Windows File Path
    QFile outputFile("UserReports.txt");
    /// Mac File Path
    //QFile outputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/UserReports.txt");

    QTextStream out(&outputFile);
    outputFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);

    out << ui->editReportSubject->text() << ", ";
    out << ui->cbReportCategory->currentText() << ", ";
    out << ui->editPreferredName->text() << ", ";
    out << ui->editPreferredContact->text() << ", ";
    out << ui->editReportDetails->toPlainText() << endl;


    // Flushing file and then closing.
    out.flush();
    outputFile.close();

    // Clear input from labels
    ui->editReportSubject->clear();
    ui->editPreferredName->clear();
    ui->editPreferredContact->clear();
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
}
