#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

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
    QString username = ui->editEmail->text();
    QString password = ui->editNHI->text();
    QString accessNumber = ui->editAccessNumber->text();

    // Check if login input matches, if not, an error message will be displayed
    // If correct, directed to Home Page
    if (username == "1") // Admin Login Check Loop
    {
        if (password == "1")
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
    else
    {
        ui->labelError->setText("Incorrect Name Entered");
    }
}

