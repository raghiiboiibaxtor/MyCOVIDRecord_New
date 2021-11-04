#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "usermainwindow.h"

#include <QListWidgetItem>
#include <QVector>
#include <QFile>
#include <QTextStream>

Login::Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::Login)
{
    ui->setupUi(this);

    // Home page display image
    QPixmap pixmap(":/res/images/dp.png");
    ui->imgHome->setPixmap(pixmap);
    ui->imgHome->setScaledContents(true);
}

Login::~Login()
{
    delete ui;
}


void Login::on_pbLogin_clicked()
{
    QString email = ui->editEmail->text();
    QString NHI = ui->editNHI->text();
    QString accessNumber = ui->editAccessNumber->text();
    //int index;

    //QFile inputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/Citizens.txt");
    QFile inputFile("Citizens.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice:: Text);
    QTextStream read(&inputFile);

    // Check if login input matches, if not, an error message will be displayed
    // If correct, directed to Home Page
    while (!read.atEnd())
    {
        // QString text = read.readLine();
        // userList.push_back(temp);

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
        /*else if (email == userList.at(index)->getEmailAddress()) // User Login Check Loop
        {
            if (NHI == userList.at(index)->getNHI())
            {
                if (accessNumber == "1234")
                {
                    UserMainWindow *userMainWindow;
                    hide();
                    // Displays User Home Page
                    userMainWindow = new UserMainWindow(this);
                    userMainWindow->show();
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
        else
        {
            ui->labelError->setText("Incorrect Name Entered");
        }*/
    }

    // Flushing file and then closing.
    read.flush();
    inputFile.close();
}

