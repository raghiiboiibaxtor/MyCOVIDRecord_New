#include "classcitizen.h"

classCitizen::classCitizen(QString name, QString contactNumber, QString emailAddress, QString dateOfBirth, QString nhi, QString accessNumber)//cvn)
{
    this->name = name;
    this->contactNumber = contactNumber;
    this->emailAddress = emailAddress;
    this->dateOfBirth = dateOfBirth;
    this->nhi = nhi;
   // this->cvn = cvn;
    this->accessNumber = accessNumber;
}


// Login Setters
void classCitizen::setEmailAddress(QString emailAddress)
{
    this->emailAddress = emailAddress;
}

void classCitizen::setNHI(QString nhi)
{
    this->nhi = nhi;
}

void classCitizen::setAccessNumber(QString accessNumber)
{
    this->accessNumber = accessNumber;
}

void classCitizen::setLogin (QString emailAddress, QString nhi, QString accessNumber)
{
    this->emailAddress = emailAddress;
    this->nhi = nhi;
    this->accessNumber = accessNumber;
}

void classCitizen::setResult(bool result)
{
    this->result = result;
}

// Personal Info Setters
void classCitizen::setName(QString name)
{
    this->name = name;
}


void classCitizen::setDateOfBirth(QString dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

void classCitizen::setContactNumber(QString contactNumber)
{
    this->contactNumber = contactNumber;
}

void classCitizen::setAdditionalNotes(QString additionalNotes)
{
    this->additionalNotes = additionalNotes;
}

// Vaccine & Covid Info Setters
void classCitizen::setVaccineName(QString vaccineName)
{
    this->vaccineName = vaccineName;
}

void classCitizen::setBatchNumber(QString batchNumber)
{
    this->batchNumber = batchNumber;
}

void classCitizen::setDateGiven(QString dateGiven)
{
    this->dateGiven = dateGiven;
}

void classCitizen::setQRCode(QString qrCode)
{
    this->qrCode = qrCode;
}

void classCitizen::setCVN(QString cvn)
{
    this->cvn = cvn;
}

void classCitizen::setCertificate(QString certificate)
{
    this->certificate = certificate;
}

void classCitizen::setTestResult(QString testResult)
{
    this->testResult = testResult;
}

// Login Getters
QString classCitizen::getEmailAddress() const
{
    return emailAddress;
}

QString classCitizen::getNHI() const
{
    return nhi;
}
QString classCitizen::getAccessNumber() const
{
    return accessNumber;
}

bool classCitizen::getLogin()
{
    return true;
}

bool classCitizen::getResult()
{
    return true;
}

// Personal Info Getters
QString classCitizen::getName() const
{
    return name;
}


QString classCitizen::getContactNumber() const
{
    return contactNumber;
}

QString classCitizen::getDateOfBirth() const
{
    return dateOfBirth;
}

QString classCitizen::getAdditionalNotes() const
{
    return additionalNotes;
}

// Vaccine & Covid Info Getters
QString classCitizen::getVaccineName() const
{
    return vaccineName;
}

QString classCitizen::getBatchNumber() const
{
    return batchNumber;
}

QString classCitizen::getDateGiven() const
{
    return dateGiven;
}


QString classCitizen::getCVN() const
{
    return cvn;
}

QString classCitizen::getQRCode() const
{
    return qrCode;
}

QString classCitizen::getCertificate() const
{
    return certificate;
}

QString classCitizen::getTestResult() const
{
    return testResult;
}
