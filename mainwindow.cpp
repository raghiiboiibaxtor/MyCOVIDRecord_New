//
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
#include <QFileDialog>
#include <QDir>


// Admin Main Window
//*********************************************************

// { Overloading constructors begins :

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    // Hidden UI Elements
    ui->lblSavedMessage->hide();

    // Manual Connections
    connect(ui->pbHome, &QPushButton::clicked, this, &MainWindow::pbHome);

    connect(ui->pbAddUser, &QPushButton::clicked, this, &MainWindow::addNewUser);
    connect(ui->pbAddCertificate, &QPushButton::clicked, this, &MainWindow::addCertificateImage);
    connect(ui->pbAddQRCode, &QPushButton::clicked, this, &MainWindow::addQRCodeImage);
    connect(ui->pbAddTestResults, &QPushButton::clicked, this, &MainWindow::addTestResultImage);
    connect(ui->pbAddUserPicture, &QPushButton::clicked, this, &MainWindow::addUserPicture);
    connect(ui->pbSave, &QPushButton::clicked, this, &MainWindow::saveUser);

    connect(ui->pbAllUsers, &QPushButton::clicked, this, &MainWindow::pbAllUsers);
    //connect(ui->pbLoadUsers, &QPushButton::clicked, this, &MainWindow::loadUser);
    connect(ui->listAllUsersNew, &QListWidget::itemClicked, this, &MainWindow::selectUserDetails);
    connect(ui->pbSearch, &QPushButton::clicked, this, &MainWindow::searchUser);

    connect(ui->pbEditUser, &QPushButton::clicked, this, &MainWindow::editUser);
    connect(ui->pbEditCertificate, &QPushButton::clicked, this, &MainWindow::editCertificateImage);
    connect(ui->pbEditQRCode, &QPushButton::clicked, this, &MainWindow::editQRCodeImage);
    connect(ui->pbEditTestResults, &QPushButton::clicked, this, &MainWindow::editTestResultImage);
    connect(ui->pbEditUserPicture, &QPushButton::clicked, this, &MainWindow::editUserPicture);
    connect(ui->pbSaveEdit, &QPushButton::clicked, this, &MainWindow::saveEdit);

    connect(ui->pbReports, &QPushButton::clicked, this, &MainWindow::pbReports);
    //connect(ui->pbLoadReports, &QPushButton::clicked, this, &MainWindow::loadReports);
    connect(ui->listAllReports, &QListWidget::itemClicked, this, &MainWindow::selectReportDetails);
    connect(ui->pbSearchCategory, &QPushButton::clicked, this, &MainWindow::searchCategory);

    connect(ui->pbLogout, &QPushButton::clicked, this, &MainWindow::logout);

   //Mac Create Directory
   /*QDir pathDir("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files");
       if(!pathDir.exists())
       {
           QDir().mkdir("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files");
       }*/
}

// Second constructor passing double pointer for classCitizen ptrNewCitizen.
MainWindow::MainWindow(classCitizen*& ptrNewCitizen, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptrNewCitizen = &ptrNewCitizen;

    // File path for Vaccine Certificates
    QDir pathDir("./VaccineCertificates");
    if(!pathDir.exists())
    {
        //create it!
        QDir().mkdir("./VaccineCertificates");
    }

    // File path for QRCodes
    QDir pathDir1("./QRCodes");
    if(!pathDir1.exists())
    {
        //create it!
        QDir().mkdir("./QRCodes");
    }

    // File path for Test Results
    QDir pathDir2("./TestResults");
    if(!pathDir2.exists())
    {
        //create it!
        QDir().mkdir("./TestResults");
    }

    // File path for User Profile Pictures
    QDir pathDir3("./UserProfilePictures");
    if(!pathDir3.exists())
    {
        //create it!
        QDir().mkdir("./UserProfilePictures");
    }
}

// Third constructor passing single pointer for classCitizen ptrCurrentCitizen.
MainWindow::MainWindow(classCitizen* ptrCurrentCitizen, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptrCurrentCitizen = ptrCurrentCitizen;
}

// Fourth constructor passing single pointer for citizenReport ptrCurrentReport.
MainWindow::MainWindow(citizenReport* ptrCurrentReport, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptrCurrentReport = ptrCurrentReport;
}
// Overloading constructors ends }


// PROGRAM FUNCTIONS
//*********************************************************


// Function to display Home Page
void MainWindow::pbHome()
{
    ui->stackedWidget->setCurrentIndex(0);
} // End of pbHome()


/// Add New User Functions
///*********************************************************

// Function to display Add User Page & Push new user's information to a vector of pointers
void MainWindow::addNewUser()
{
    ui->stackedWidget->setCurrentIndex(2);

    classCitizen* newCitizen = nullptr;

    if (newCitizen != nullptr)
    {
         userList.push_back(newCitizen);
         ui->listAllUsersNew->addItem(newCitizen->getName());
    }
} /// End of addNewUser()

// Function to add Vaccine Certificate Image
void MainWindow::addCertificateImage()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Image", "./", "Image File(*.png *.jpg .*jpeg)");

    if(fileName != "")
    {
        int lastSlash = fileName.lastIndexOf("/");

        QString shortName = fileName.right(fileName.size() - lastSlash - 1);

        QFile::copy(fileName, "./vaccineCertificates/"+shortName);

        QPixmap pixmap("./vaccineCertificates/"+shortName);

        ui->showCertificate->setPixmap(pixmap);
        ui->showCertificate->setScaledContents(true);

        certificateImage = "./vaccineCertificates/" + shortName;
    }
} /// End of addCertificateImage()

// Function to add QR Code Image
void MainWindow::addQRCodeImage()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Image", "./", "Image File(*.png *.jpg .*jpeg)");

    if(fileName != "")
    {
        int lastSlash = fileName.lastIndexOf("/");

        QString shortName = fileName.right(fileName.size() - lastSlash - 1);

        QFile::copy(fileName, "./qrCodes/"+shortName);

        QPixmap pixmap1("./qrCodes/"+shortName);

        ui->showQRCode->setPixmap(pixmap1);
        ui->showQRCode->setScaledContents(true);

        qrCodeImage = "./qrCodes/" + shortName;
    }
} /// End of addQRCodeImage()

// Function to add QR Code
void MainWindow::addTestResultImage()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Image", "./", "Image File(*.png *.jpg .*jpeg)");

    if(fileName != "")
    {
        int lastSlash = fileName.lastIndexOf("/");

        QString shortName = fileName.right(fileName.size() - lastSlash - 1);

        QFile::copy(fileName, "./testResults/"+shortName);

        QPixmap pixmap2("./testResults/"+shortName);

        ui->showTestResults->setPixmap(pixmap2);
        ui->showTestResults->setScaledContents(true);

        testResultImage = "./testResults/" + shortName;
    }
} /// End of addTestResultImage()

// Function to add QR Code
void MainWindow::addUserPicture()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Image", "./", "Image File(*.png *.jpg .*jpeg)");

    if(fileName != "")
    {
        int lastSlash = fileName.lastIndexOf("/");

        QString shortName = fileName.right(fileName.size() - lastSlash - 1);

        QFile::copy(fileName, "./userProfilePictures/"+shortName);

        QPixmap pixmap3("./userProfilePictures/"+shortName);

        ui->showUserPicture->setPixmap(pixmap3);
        ui->showUserPicture->setScaledContents(true);

        userProfilePicture = "./userProfilePictures/" + shortName;
    }
} /// End of addTestResultImage()

// Saving new user information to file
void MainWindow::saveUser()
{
    QString addName = ui->addUserName->text();
    QString addPhone = ui->addUserPhone->text();
    QString addEmail = ui->addUserEmail->text();
    QString addDob = ui->addUserDOB->text();
    QString addNhi = ui->addUserNHI->text();
    QString addEmergencyContact = ui->addUserEmergency->text();
    QString addNotes = ui->addNotes->text();
    QString addVaccStatus = ui->addVaccStatus->currentText();
    QString addCvn = ui->addUserCVN->text();
    QString add1VaccName = ui->add1stDoseName->text();
    QString add1BatchNum = ui->add1stDoseBatch->text();
    QString add1Date = ui->add1stDoseDate->text();
    QString add2VaccName = ui->add2ndDoseName->text();
    QString add2BatchNum = ui->add2ndDoseBatch->text();
    QString add2Date = ui->add2ndDoseDate->text();

    if (addName.trimmed() != "" && addNhi.trimmed() != "" && addEmail.trimmed() != "")
    {
        classCitizen *ptrNewCitizen = new classCitizen(addName, addPhone, addEmail, addDob, addNhi, addEmergencyContact, addNotes, addVaccStatus, addCvn,
                                                       add1VaccName, add1BatchNum, add1Date, add2VaccName, add2BatchNum, add2Date, certificateImage, qrCodeImage, testResultImage, userProfilePicture);
        userList.push_back(ptrNewCitizen);
        ui->listAllUsersNew->addItem(ptrNewCitizen->getNHI()); // Displays added user name to list widget on "all users page"

        // Writing to file
        /// Windows File Path
        QFile outputFile("Citizens.txt");
        /// Mac File Path
        //QFile outputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/Citizens.txt");

        QTextStream out(&outputFile);
        outputFile.open(QIODevice::WriteOnly | QIODevice::Text);

            for (int i = 0; i < userList.size(); i++)
               {
                out << userList.at(i)->getName() << ",";
                out << userList.at(i)->getContactNumber() << ",";
                out << userList.at(i)->getEmailAddress() << ",";
                out << userList.at(i)->getDateOfBirth() << ",";
                out << userList.at(i)->getNHI() << ",";
                out << userList.at(i)->getEmergencyContact() << ",";
                out << userList.at(i)->getAdditionalNotes() << ",";
                out << userList.at(i)->getVaccineStatus() << ",";
                out << userList.at(i)->getCVN()<< ",";
                out << userList.at(i)->getVaccineName1() << ",";
                out << userList.at(i)->getBatchNumber1() << ",";
                out << userList.at(i)->getDateGiven1() << ",";
                out << userList.at(i)->getVaccineName2() << ",";
                out << userList.at(i)->getBatchNumber2() << ",";
                out << userList.at(i)->getDateGiven2() << ",";
                out << userList.at(i)->getCertificate() << ",";
                out << userList.at(i)->getQRCode() << ",";
                out << userList.at(i)->getTestResult() << ",";
                out << userList.at(i)->getCitizenImage() << Qt::endl;
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
            ui->addUserEmergency->clear();
            ui->addNotes->clear();
            ui->addUserCVN->clear();
            ui->add1stDoseName->clear();
            ui->add1stDoseBatch->clear();
            ui->add1stDoseDate->clear();
            ui->add2ndDoseName->clear();
            ui->add2ndDoseBatch->clear();
            ui->add2ndDoseDate->clear();
            ui->showCertificate->clear();
            ui->showQRCode->clear();
            ui->showTestResults->clear();
            ui->showUserPicture->clear();

            // Displaying saved message for admin user
            ui->lblSavedMessage->show();
    }
    else
    {
       QMessageBox::information(this, "More Details Required",
                                      "Please ensure the Name, Email, and National Health Index has been entered...");
    }

} /// End of saveUser()


/// Display List of All Users & Info Functions
///*********************************************************

// Function to display All Users Page
void MainWindow::pbAllUsers()
{
    ui->stackedWidget->setCurrentIndex(1);

    // Open file for reading
    //QFile inputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/Citizens.txt");
    QFile inputFile("Citizens.txt");
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
       classCitizen* temp = new classCitizen(info.at(0), info.at(1), info.at(2), info.at(3), info.at(4), info.at(5), info.at(6), info.at(7), info.at(8), info.at(9),
                                             info.at(10), info.at(11), info.at(12), info.at(13), info.at(14), info.at(15), info.at(16), info.at(17), info.at(18));
       userList.push_back(temp);
   } // End while


   // Flushing file and then closing.
   read.flush();
   inputFile.close();
} // End of pbAllUsers()

// Function to show user's information when selected from list widget
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
        ui->showUserEmergency->setText(selectedUser->getEmergencyContact());
        ui->showUserNotes->setText(selectedUser->getAdditionalNotes());
        ui->showUserVaccStatus->setText(selectedUser->getVaccineStatus());
        ui->showUserCVN->setText(selectedUser->getCVN());
        QPixmap pixmap3(selectedUser->getCitizenImage());
        ui->showUserPicture2->setPixmap(pixmap3);
        ui->showUserPicture2->setScaledContents(true);
    }    
} /// End of selectUserDetails()

// Function to search for user in list widget
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
    else if (search == "")
    {
        QMessageBox::information(this, "Invalid Search",
                                       "Please type the National Health Index in the search bar...");
        // Loop to remove highlight
        for (int i = 0; i < ui->listAllUsersNew->count(); i++)
        {
            QListWidgetItem* item = ui->listAllUsersNew->item(i);
            item->setBackground(Qt::transparent);
        }
    }
} /// End of searchUser()


/// Edit User Functions
///*********************************************************

// Function to edit existing user's information
void MainWindow:: editUser()
{  
    int listNum = ui->listAllUsersNew->currentRow();
    ui->stackedWidget->setCurrentIndex(3);

    if (listNum != -1)
    {
        ptrCurrentCitizen = userList.at(listNum);

            if (ptrCurrentCitizen != nullptr)
           {
                // Changing UI page
                ui->stackedWidget->setCurrentIndex(3);

                // Populating labels with existing info
                ui->editUserName->setText(ptrCurrentCitizen->getName());
                ui->editUserPhone->setText(ptrCurrentCitizen->getContactNumber());
                ui->editUserEmail->setText(ptrCurrentCitizen->getEmailAddress());
                ui->editUserDOB->setText(ptrCurrentCitizen->getDateOfBirth());
                ui->NHIDisplayLabel->setText(ptrCurrentCitizen->getNHI()); // Non-editable
                ui->editUserEmergency->setText(ptrCurrentCitizen->getEmergencyContact());
                ui->editUserNotes->setText(ptrCurrentCitizen->getAdditionalNotes());
                ui->editUserVaccineSB->setCurrentText(ptrCurrentCitizen->getVaccineStatus());
                ui->CVNDisplayLabel->setText(ptrCurrentCitizen->getCVN()); // Non-editable
                ui->edit1stDoseName->setText(ptrCurrentCitizen->getVaccineName1());
                ui->edit1stDoseBatch->setText(ptrCurrentCitizen->getBatchNumber1());
                ui->edit1stDoseDate->setText(ptrCurrentCitizen->getDateGiven1());
                ui->edit2ndDoseName->setText(ptrCurrentCitizen->getVaccineName2());
                ui->edit2ndDoseBatch->setText(ptrCurrentCitizen->getBatchNumber2());
                ui->edit2ndDoseDate->setText(ptrCurrentCitizen->getDateGiven2());
                QPixmap pixmap(ptrCurrentCitizen->getCertificate());
                ui->displayCertificate->setPixmap(pixmap);
                ui->displayCertificate->setScaledContents(true);
                QPixmap pixmap1(ptrCurrentCitizen->getQRCode());
                ui->displayQRCode->setPixmap(pixmap1);
                ui->displayQRCode->setScaledContents(true);
                QPixmap pixmap2(ptrCurrentCitizen->getTestResult());
                ui->displayTestResults->setPixmap(pixmap2);
                ui->displayTestResults->setScaledContents(true);
                QPixmap pixmap3(ptrCurrentCitizen->getCitizenImage());
                ui->displayUserPicture->setPixmap(pixmap3);
                ui->displayUserPicture->setScaledContents(true);
            }
    }
    else
    {
        QMessageBox::information(this, "No User Selected",
                                       "Please select a user to edit...");
    }
} /// End of editUser()

// Function to add Vaccine Certificate Image
void MainWindow::editCertificateImage()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Image", "./", "Image File(*.png *.jpg .*jpeg)");

    if(fileName != "")
    {
        int lastSlash = fileName.lastIndexOf("/");

        QString shortName = fileName.right(fileName.size() - lastSlash - 1);

        QFile::copy(fileName, "./vaccineCertificates/"+shortName);

        QPixmap pixmap("./vaccineCertificates/"+shortName);

        ui->displayCertificate->setPixmap(pixmap);
        ui->displayCertificate->setScaledContents(true);

        certificateImage = "./vaccineCertificates/" + shortName;
    }
} /// End of addQRCodeImage()

// Function to add QR Code Image
void MainWindow::editQRCodeImage()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Image", "./", "Image File(*.png *.jpg .*jpeg)");

    if(fileName != "")
    {
        int lastSlash = fileName.lastIndexOf("/");

        QString shortName = fileName.right(fileName.size() - lastSlash - 1);

        QFile::copy(fileName, "./qrCodes/"+shortName);

        QPixmap pixmap1("./qrCodes/"+shortName);

        ui->displayQRCode->setPixmap(pixmap1);
        ui->displayQRCode->setScaledContents(true);

        qrCodeImage = "./qrCodes/" + shortName;
    }
} /// End of addQRCodeImage()

// Function to add QR Code
void MainWindow::editTestResultImage()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Image", "./", "Image File(*.png *.jpg .*jpeg)");

    if(fileName != "")
    {
        int lastSlash = fileName.lastIndexOf("/");

        QString shortName = fileName.right(fileName.size() - lastSlash - 1);

        QFile::copy(fileName, "./testResults/"+shortName);

        QPixmap pixmap2("./testResults/"+shortName);

        ui->displayTestResults->setPixmap(pixmap2);
        ui->displayTestResults->setScaledContents(true);

        testResultImage = "./testResults/" + shortName;
    }
} /// End of addTestResultImage()

// Function to add QR Code
void MainWindow::editUserPicture()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Image", "./", "Image File(*.png *.jpg .*jpeg)");

    if(fileName != "")
    {
        int lastSlash = fileName.lastIndexOf("/");

        QString shortName = fileName.right(fileName.size() - lastSlash - 1);

        QFile::copy(fileName, "./userProfilePictures/"+shortName);

        QPixmap pixmap2("./userProfilePictures/"+shortName);

        ui->displayUserPicture->setPixmap(pixmap2);
        ui->displayUserPicture->setScaledContents(true);

        userProfilePicture = "./userProfilePictures/" + shortName;
    }
} /// End of addTestResultImage()

// Function to save edited information and re-writing file
void MainWindow::saveEdit()
{
    // Retrieving edited information from ui
    QString editName = ui->editUserName->text();
    QString editPhone = ui->editUserPhone->text();
    QString editEmail = ui->editUserEmail->text();
    QString editDob = ui->editUserDOB->text();
    QString editEmergencyContact = ui->editUserEmergency->text();
    QString editNotes = ui->editUserNotes->text();
    QString editVaccStatus = ui->editUserVaccineSB->currentText();
    QString edit1VaccName = ui->edit1stDoseName->text();
    QString edit1BatchNum = ui->edit1stDoseBatch->text();
    QString edit1Date = ui->edit1stDoseDate->text();
    QString edit2VaccName = ui->edit2ndDoseName->text();
    QString edit2BatchNum = ui->edit2ndDoseBatch->text();
    QString edit2Date = ui->edit2ndDoseDate->text();

    QPixmap pixmap(ptrCurrentCitizen->getCertificate());
    ui->displayCertificate->setPixmap(pixmap);
    QPixmap pixmap1(ptrCurrentCitizen->getQRCode());
    ui->displayQRCode->setPixmap(pixmap1);
    QPixmap pixmap2(ptrCurrentCitizen->getTestResult());
    ui->displayTestResults->setPixmap(pixmap2);
    QPixmap pixmap3(ptrCurrentCitizen->getCitizenImage());
    ui->displayUserPicture->setPixmap(pixmap2);


    if(editName.trimmed() != "" && editEmail.trimmed() != "")
    {
        // Changing the information of the current citizen
        ptrCurrentCitizen->setName(editName);
        ptrCurrentCitizen->setContactNumber(editPhone);
        ptrCurrentCitizen->setEmailAddress(editEmail);
        ptrCurrentCitizen->setDateOfBirth(editDob);
        ptrCurrentCitizen->setEmergencyContact(editEmergencyContact);
        ptrCurrentCitizen->setAdditionalNotes(editNotes);
        ptrCurrentCitizen->setVaccineStatus(editVaccStatus);
        ptrCurrentCitizen->setVaccineName1(edit1VaccName);
        ptrCurrentCitizen->setBatchNumber1(edit1BatchNum);
        ptrCurrentCitizen->setDateGiven1(edit1Date);
        ptrCurrentCitizen->setVaccineName2(edit2VaccName);
        ptrCurrentCitizen->setBatchNumber2(edit2BatchNum);
        ptrCurrentCitizen->setDateGiven2(edit2Date);
        ptrCurrentCitizen->setCertificate(certificateImage);
        ptrCurrentCitizen->setQRCode(qrCodeImage);
        ptrCurrentCitizen->setTestResult(testResultImage);
        ptrCurrentCitizen->setCitizenImage(userProfilePicture);

        // Writing edit to file
        /// Windows File Path
        QFile outputFile("Citizens.txt");
        /// Mac File Path
        //QFile outputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/Citizens.txt");

        QTextStream out(&outputFile);
        outputFile.open(QIODevice::WriteOnly | QIODevice::Text);

            for (int i = 0; i < userList.size(); i++)
               {
                out << userList.at(i)->getName() << ",";
                out << userList.at(i)->getContactNumber() << ",";
                out << userList.at(i)->getEmailAddress() << ",";
                out << userList.at(i)->getDateOfBirth() << ",";
                out << userList.at(i)->getNHI() << ",";
                out << userList.at(i)->getEmergencyContact() << ",";
                out << userList.at(i)->getAdditionalNotes() << ",";
                out << userList.at(i)->getVaccineStatus() << ",";
                out << userList.at(i)->getCVN()<< ",";
                out << userList.at(i)->getVaccineName1() << ",";
                out << userList.at(i)->getBatchNumber1() << ",";
                out << userList.at(i)->getDateGiven1() << ",";
                out << userList.at(i)->getVaccineName2() << ",";
                out << userList.at(i)->getBatchNumber2() << ",";
                out << userList.at(i)->getDateGiven2() << ",";
                out << userList.at(i)->getCertificate() << ",";
                out << userList.at(i)->getQRCode() << ",";
                out << userList.at(i)->getTestResult() << ",";
                out << userList.at(i)->getCitizenImage() << Qt::endl;
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
            ui->editUserEmergency->clear();
            ui->editUserNotes->clear();
            ui->editUserVaccineSB->clear();
            ui->CVNDisplayLabel->clear();
            ui->add1stDoseName->clear();
            ui->add1stDoseBatch->clear();
            ui->add1stDoseDate->clear();
            ui->add2ndDoseName->clear();
            ui->add2ndDoseBatch->clear();
            ui->add2ndDoseDate->clear();
            ui->showCertificate->clear();
            ui->showQRCode->clear();
            ui->showTestResults->clear();
            ui->showUserPicture->clear();

            // Changing input from view user labels
            ui->showUserName->setText(ptrCurrentCitizen->getName());
            ui->showUserPhone->setText(ptrCurrentCitizen->getContactNumber());
            ui->showUserEmail->setText(ptrCurrentCitizen->getEmailAddress());
            ui->showUserDOB->setText(ptrCurrentCitizen->getDateOfBirth());
            ui->showUserNHI->setText(ptrCurrentCitizen->getNHI());
            ui->showUserEmergency->setText(ptrCurrentCitizen->getEmergencyContact());
            ui->showUserNotes->setText(ptrCurrentCitizen->getAdditionalNotes());
            ui->showUserVaccStatus->setText(ptrCurrentCitizen->getVaccineStatus());
            ui->showUserCVN->setText(ptrCurrentCitizen->getCVN());
            QPixmap pixmap3(ptrCurrentCitizen->getCitizenImage());
            ui->displayUserPicture->setPixmap(pixmap3);
            ui->displayUserPicture->setScaledContents(true);

            //Changing page back to All Users
            ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::information(this, "More Details Required",
                                       "Please ensure the Name and Email fields have been entered...");
    }
} /// End of saveEdit()


/// Citizen Report Functions
///*********************************************************

// Display Reports Page
void MainWindow::pbReports()
{
    ui->stackedWidget->setCurrentIndex(4);

    // Open file for reading
    //QFile inputFile("/Users/raghiiboiibaxtor/Documents/MyCOVIDRecord_New/files/UserReports.txt");
    QFile inputFile("UserReports.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice:: Text);
    QTextStream read(&inputFile);

    // Clearing existing data from vector
   for (int i = 0; i< reportList.size(); i++)
    {
        delete reportList.at(i);
    }
    // Clearing UI
    reportList.clear();
    ui->listAllReports->clear();

    while(!read.atEnd())
    {
        // Reading from file and seperating info at text.split()
        QString text = read.readLine();
        QStringList info = text.split(",");

        // Add read information to ui list widget
        ui->listAllReports->addItem(info.at(3)); // Display subject in list widget

        // Adding file information to vector
        citizenReport* temp = new citizenReport(info.at(0), info.at(1), info.at(2), info.at(3), info.at(4));
        reportList.push_back(temp);
    } // End while

    // Flushing file and then closing.
    read.flush();
    inputFile.close();

} /// End of pbReports()

// Function to show report details when selected
void MainWindow::selectReportDetails()
{
    int index = ui->listAllReports->currentRow();

        if (index >= 0)
        {
            citizenReport *selectedReport = reportList.at(index);
            ui->showReportSubject->setText(selectedReport->getSubject());
            ui->showReportCategory->setText(selectedReport->getCategory());
            ui->showReportDetails->setText(selectedReport->getDetails());
            ui->showPreferredName->setText(selectedReport->getName());
            ui->showContactDetails->setText(selectedReport->getContact());
        }
} /// End of selectedReportDetails()

// Function to search report category in list widget
void MainWindow::searchCategory()
{
    QString search = ui->cbReportCategory->currentText();

    if(search !="")
    {
        // Loop to remove highlight on orginal search before highlighting next search
        for (int i=0; i < ui->listAllReports->count(); i++)
        {
            QListWidgetItem* user = ui->listAllReports->item(i);
            user->setBackground(Qt::transparent);
        }

        QList<QListWidgetItem*> list = ui->listAllReports->findItems(search, Qt::MatchContains);

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
        for (int i = 0; i < ui->listAllReports->count(); i++)
        {
            QListWidgetItem* item = ui->listAllReports->item(i);
            item->setBackground(Qt::transparent);
        }
    }
} /// End of searchCategory()

// Function to logout
void MainWindow::logout()
{
    UserLogin *login;
    close();
    //Displays Login window
    login = new UserLogin(this);
    login->show();
} // End of logout()


/// Destructor : End of Program.
///*********************************************************
MainWindow::~MainWindow()
{
    for (int i=0; i<userList.size(); i++)
    {
        delete userList.at(i);
    }
    userList.clear();

    delete ui;
}
