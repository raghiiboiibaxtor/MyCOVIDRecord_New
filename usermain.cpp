#include "usermain.h"
#include "ui_usermain.h"
#include "login.h"
#include "classcitizen.h"


// Main Window
//*********************************************************

UserMain::UserMain(QWidget *parent) : QMainWindow(parent), ui(new Ui::UserMainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    // Manual Connection
    connect(ui->pbLogout, &QPushButton::clicked, this, &UserMain::logout);
}

// Login Functions
//*********************************************************

// Logout Function
void UserMain::logout()
{
    Login *login;
    close();
    //Displays Login window
    login = new Login(this);
    login->show();
}

// Stacked Widget Button Slots
//*********************************************************

/// Home Menu Button
void UserMain::on_pbHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


/// User Profile Menu Button
void UserMain::on_pbAllUsers_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


/// Contact Menu Button
void UserMain::on_pbAddUser_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


// Destructor : End of Program.

//*********************************************************
UserMain::~UserMain()
{
    delete ui;
}
