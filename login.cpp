//

#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "usermain.h"

#include <QListWidgetItem>
#include <QVector>
#include <QFile>
#include <QTextStream>

#define STR_EQUAL 0

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
    //QString fileNumber = ;

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
        QFile inputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/Citizens.txt");
        //QFile inputFile("Citizens.txt");
        inputFile.open(QIODevice::ReadOnly | QIODevice:: Text);
        QTextStream read(&inputFile);

        while (!read.atEnd())
        {
            QString line = read.readLine();
            QStringList info = line.split(", ");

            QString fileEmail = info.at(2);
            QString fileNHI = info.at(4);

            if (email == fileEmail && NHI == fileNHI) // User Login Check Loop
            {
                if (accessNumber == "1234")
                {
                    UserMain *userMain;
                    hide();
                    // Displays User Home Page
                    userMain = new UserMain(this);
                    userMain->show();
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

       /*while (!read.atEnd())
        {
            QString line = read.readLine();
            QStringList info = line.split(", ");

            QString fileEmail = info.at(2);
            QString fileNHI = info.at(4);

            if (email == fileEmail) // User Login Check Loop
            {
                if (NHI == fileNHI)
                {
                    if (accessNumber == "1234")
                    {
                        UserMain *userMain;
                        hide();
                        // Displays User Home Page
                        userMain = new UserMain(this);
                        userMain->show();
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
                  ui->labelError->setText("Incorrect Email Entered");
            }
        }
            //Flushing file and then closing.
            read.flush();
            inputFile.close();
    }
    else
    {
        ui->labelError->setText("Incorrect Email Entered");
    }*/
}


