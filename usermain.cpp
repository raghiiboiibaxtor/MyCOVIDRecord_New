#include "usermain.h"
#include "ui_usermain.h"

UserMain::UserMain(QWidget *parent) : QMainWindow(parent), ui(new Ui::UserMainWindow)
{
    ui->setupUi(this);
}

UserMain::~UserMain()
{
    delete ui;
}

