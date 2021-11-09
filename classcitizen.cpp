#include "classcitizen.h"
//
classCitizen::classCitizen(QString name, QString contactNumber, QString emailAddress, QString dateOfBirth, QString nhi, QString emergencyContact, QString additionalNotes,
                           QString vaccineStatus, QString cvn, QString vaccineName1, QString batchNumber1, QString dateGiven1, QString vaccineName2, QString batchNumber2, QString dateGiven2,
                           QString certificateImage, QString qrCodeImage, QString testResultImage)
{
    this->name = name;
    this->contactNumber = contactNumber;
    this->emailAddress = emailAddress;
    this->dateOfBirth = dateOfBirth;
    this->nhi = nhi;
    this->cvn = cvn;
    this->emergencyContact = emergencyContact;
    this->additionalNotes = additionalNotes;
    this->vaccineStatus = vaccineStatus;
    this->vaccineName1 = vaccineName1;
    this->batchNumber1 = batchNumber1;
    this->dateGiven1 = dateGiven1;
    this->vaccineName2 = vaccineName2;
    this->batchNumber2 = batchNumber2;
    this->dateGiven2 = dateGiven2;
    this->certificateImage = certificateImage;
    this->qrCodeImage = qrCodeImage;
    this->testResultImage = testResultImage;
}

// Personal Info / Login Setters
void classCitizen::setName(QString name)
{
    this->name = name;
}

void classCitizen::setContactNumber(QString contactNumber)
{
    this->contactNumber = contactNumber;
}

void classCitizen::setEmailAddress(QString emailAddress)
{
    this->emailAddress = emailAddress;
}


void classCitizen::setDateOfBirth(QString dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

void classCitizen::setNHI(QString nhi)
{
    this->nhi = nhi;
}

void classCitizen::setEmergencyContact(QString emergencyContact)
{
    this->emergencyContact = emergencyContact;
}

void classCitizen::setAdditionalNotes(QString additionalNotes)
{
    this->additionalNotes = additionalNotes;
}

// Vaccine & Covid Info Setters
void classCitizen::setVaccineStatus(QString vaccineStatus)
{
    this->vaccineStatus = vaccineStatus;
}

void classCitizen::setVaccineName1(QString vaccineName1)
{
    this->vaccineName1 = vaccineName1;
}

void classCitizen::setBatchNumber1(QString batchNumber1)
{
    this->batchNumber1 = batchNumber1;
}

void classCitizen::setDateGiven1(QString dateGiven1)
{
    this->dateGiven1 = dateGiven1;
}

void classCitizen::setVaccineName2(QString vaccineName2)
{
    this->vaccineName2 = vaccineName2;
}

void classCitizen::setBatchNumber2(QString batchNumber2)
{
    this->batchNumber2 = batchNumber2;
}

void classCitizen::setDateGiven2(QString dateGiven2)
{
    this->dateGiven2 = dateGiven2;
}

void classCitizen::setCVN(QString cvn)
{
    this->cvn = cvn;
}

void classCitizen::setQRCode(QString qrCodeImage)
{
    this->qrCodeImage = qrCodeImage;
}

void classCitizen::setCertificate(QString certificateImage)
{
    this->certificateImage = certificateImage;
}

void classCitizen::setTestResult(QString testResultImage)
{
    this->testResultImage = testResultImage;
}

// Personal Info / Login Getters
QString classCitizen::getName() const
{
    return name;
}

QString classCitizen::getContactNumber() const
{
    return contactNumber;
}

QString classCitizen::getEmailAddress() const
{
    return emailAddress;
}

QString classCitizen::getDateOfBirth() const
{
    return dateOfBirth;
}

QString classCitizen::getNHI() const
{
    return nhi;
}

QString classCitizen::getEmergencyContact() const
{
    return emergencyContact;
}

QString classCitizen::getAdditionalNotes() const
{
    return additionalNotes;
}


// Vaccine & Covid Info Getters
QString classCitizen::getVaccineStatus() const
{
    return vaccineStatus;
}

QString classCitizen::getVaccineName1() const
{
    return vaccineName1;
}

QString classCitizen::getBatchNumber1() const
{
    return batchNumber1;
}

QString classCitizen::getDateGiven1() const
{
    return dateGiven1;
}

QString classCitizen::getVaccineName2() const
{
    return vaccineName2;
}

QString classCitizen::getBatchNumber2() const
{
    return batchNumber2;
}

QString classCitizen::getDateGiven2() const
{
    return dateGiven2;
}

QString classCitizen::getCVN() const
{
    return cvn;
}

QString classCitizen::getQRCode() const
{
    return qrCodeImage;
}

QString classCitizen::getCertificate() const
{
    return certificateImage;
}

QString classCitizen::getTestResult() const
{
    return testResultImage;
}
