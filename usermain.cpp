#include "usermain.h"
#include "ui_usermain.h"
#include "userlogin.h"
#include "classcitizen.h"

#include <QFile>
#include <QTextStream>
#include <QDir>


// Main Window
//*********************************************************

UserMain::UserMain(QWidget *parent) : QMainWindow(parent), ui(new Ui::UserMainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    ui->labelConfirmation->hide();

    // Manual Connection
    connect(ui->pbLogout, &QPushButton::clicked, this, &UserMain::logout);
    connect(ui->pbSendMessage, &QPushButton::clicked, this, &UserMain::submitReport);

    //Mac Create Directory
    QDir pathDir("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files");
        if(!pathDir.exists())
        {
            QDir().mkdir("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files");
        }
}

/*UserMain::UserMain(QString*ptrTestLogin, QWidget *parent) : QMainWindow(parent), ui(new Ui::UserMainWindow)
{
    ui->setupUi(this);
    this->ptrTestLogin = ptrTestLogin;
}*/




// Login Functions
//*********************************************************

// Logout Function
void UserMain::logout()
{
    UserLogin *login;
    close();
    //Displays Login window
    login = new UserLogin(this);
    login->show();
}

// Report Function
//*********************************************************
void UserMain::submitReport()
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


/*QString UserMain::accessUserLogin(QString *ptrTestLogin)
{
    *ptrTestLogin = "TestText";
    ui->labelUserName->setText(*ptrTestLogin);
    return *ptrTestLogin;

}*/






























// Stacked Widget Button Slots
//*********************************************************

/// Home Menu Button
void UserMain::on_pbHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


/// User Profile Menu Button
void UserMain::on_pbMyDetails_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);  
}


/// Contact Menu Button
void UserMain::on_pbContactUs_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


// Destructor : End of Program.

//*********************************************************
UserMain::~UserMain()
{
    delete ui;
}
