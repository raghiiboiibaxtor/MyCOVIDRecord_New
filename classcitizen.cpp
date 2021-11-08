#include "classcitizen.h"
//
classCitizen::classCitizen(QString name, QString contactNumber, QString emailAddress, QString dateOfBirth,
                           QString nhi, QString guardian, QString additionalNotes, QString vaccineStatus, QString cvn) // , QString accessNumber)
{
    this->name = name;
    this->contactNumber = contactNumber;
    this->emailAddress = emailAddress;
    this->dateOfBirth = dateOfBirth;
    this->nhi = nhi;
    this->cvn = cvn;
    this->guardian = guardian;
    this->additionalNotes = additionalNotes;
    this->vaccineStatus = vaccineStatus;
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

void classCitizen::setGuardian(QString guardian)
{
    this->guardian = guardian;
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

void classCitizen::setCVN(QString cvn)
{
    this->cvn = cvn;
}

void classCitizen::setQRCode(QString qrCode)
{
    this->qrCode = qrCode;
}

void classCitizen::setCertificate(QString certificate)
{
    this->certificate = certificate;
}

void classCitizen::setTestResult(QString testResult)
{
    this->testResult = testResult;
}


/*bool classCitizen::getLogin()
{
    return true;
}

bool classCitizen::getResult()
{
    return true;
}*/

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

QString classCitizen::getGuardian() const
{
    return guardian;
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
