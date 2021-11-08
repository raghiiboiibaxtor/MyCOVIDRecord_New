#ifndef CLASSCITIZEN_H
#define CLASSCITIZEN_H

//
#include <QString>

class classCitizen
{
private:

    QString name;
    QString contactNumber;
    QString emailAddress;
    QString dateOfBirth;
    QString nhi;
    QString cvn;
    QString guardian;
    QString accessNumber; // Either default Admin# or User Auth#
    //bool result;
    QString additionalNotes;
    QString vaccineStatus;
    QString vaccineName;
    QString batchNumber;
    QString dateGiven;
    QString qrCode;
    QString certificate;
    QString testResult;

public:
    // Constructor
    explicit classCitizen(QString name, QString contactNumber, QString emailAddress, QString dateOfBirth, QString nhi, QString guardian, QString additionalNotes,
                          QString vaccineStatus, QString cvn);


    /*bool getLogin ();
    bool getResult();*/

    // Personal Info / Login Getters
    QString getName() const;
    QString getContactNumber() const;
    QString getEmailAddress() const;
    QString getDateOfBirth() const;
    QString getNHI() const;
    QString getGuardian() const;
    QString getAdditionalNotes() const;


    // Vaccine & Covid Info Getters
    QString getVaccineStatus() const;
    QString getVaccineName() const;
    QString getBatchNumber() const;
    QString getDateGiven() const;
    QString getCVN() const;
    QString getQRCode() const;
    QString getCertificate() const;
    QString getTestResult() const;

    /*void setLogin (QString emailAddress, QString nhi, QString accessNumber);
    void setResult(bool result);*/

    // Personal Info / Login Setters
    void setName(QString name);
    void setContactNumber(QString contactNumber);
    void setEmailAddress(QString emailAddress);
    void setDateOfBirth(QString dateOfBirth);
    void setNHI(QString nhi);
    void setCVN(QString cvn);
    void setGuardian(QString guardian);
    void setAdditionalNotes(QString additionalNotes);

    // Vaccine & Covid Info Setters
    void setVaccineStatus(QString vaccineStatus);
    void setVaccineName(QString vaccineName);
    void setBatchNumber(QString batchNumber);
    void setDateGiven(QString dateGiven);
    void setQRCode(QString qrCode);
    void setCertificate(QString location);
    void setTestResult(QString testResult);
};

#endif // CLASSCITIZEN_H
