#ifndef CLASSCITIZEN_H
#define CLASSCITIZEN_H


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
    QString accessNumber; // Either default Admin# or User Auth#
    bool result;
    QString additionalNotes;
    QString vaccineName;
    QString batchNumber;
    QString dateGiven;
    QString qrCode;
    QString certificate;
    QString testResult;

public:
public:
    // Constructor
    classCitizen(QString name, QString contactNumber, QString emailAddress, QString dateOfBirth, QString nhi, QString cvn);

    // Login Getters
    QString getEmailAddress() const;
    QString getNHI() const;
    QString getAccessNumber() const;
    bool getLogin ();
    bool getResult();

    // Personal Info Getters
    QString getName() const;
    QString getContactNumber() const;
    QString getDateOfBirth() const;
    QString getAdditionalNotes() const;

    // Vaccine & Covid Info Getters
    QString getVaccineName() const;
    QString getBatchNumber() const;
    QString getDateGiven() const;
    QString getCVN() const;
    QString getQRCode() const;
    QString getCertificate() const;
    QString getTestResult() const;

    // Login Setters
    void setEmailAddress(QString emailAddress);
    void setNHI(QString nhi);
    void setAccessNumber(QString accessNumber);
    void setLogin (QString emailAddress, QString nhi, QString accessNumber);
    void setResult(bool result);

    // Personal Info Setters
    void setName(QString name);
    void setContactNumber(QString contactNumber );
    void setDateOfBirth(QString dateOfBirth);
    void setAdditionalNotes(QString additionalNotes);

    // Vaccine & Covid Info Setters
    void setVaccineName(QString vaccineName);
    void setBatchNumber(QString batchNumber);
    void setDateGiven(QString dateGiven);

    void setQRCode(QString qrCode);
    void setCVN(QString cvn);
    void setCertificate(QString location);
    void setTestResult(QString testResult);
};

#endif // CLASSCITIZEN_H
