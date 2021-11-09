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
    QString emergencyContact;
    QString accessNumber; // Either default Admin# or User Auth#
    //bool result;
    QString additionalNotes;
    QString vaccineStatus;
    QString vaccineName1;
    QString batchNumber1;
    QString dateGiven1;
    QString vaccineName2;
    QString batchNumber2;
    QString dateGiven2;
    QString qrCodeImage;
    QString certificateImage;
    QString testResultImage;

public:
    // Constructor
    explicit classCitizen(QString name, QString contactNumber, QString emailAddress, QString dateOfBirth, QString nhi, QString emergencyContact, QString additionalNotes,
                          QString vaccineStatus, QString cvn, QString vaccineName1, QString batchNumber1, QString dateGiven1, QString vaccineName2, QString batchNumber2, QString dateGiven2,
                          QString certificateImage = "none.png", QString qrCodeImage = "none.png", QString testResultImage = "none.png");

    // Personal Info / Login Getters
    QString getName() const;
    QString getContactNumber() const;
    QString getEmailAddress() const;
    QString getDateOfBirth() const;
    QString getNHI() const;
    QString getEmergencyContact() const;
    QString getAdditionalNotes() const;


    // Vaccine & Covid Info Getters
    QString getVaccineStatus() const;
    QString getVaccineName1() const;
    QString getBatchNumber1() const;
    QString getDateGiven1() const;
    QString getVaccineName2() const;
    QString getBatchNumber2() const;
    QString getDateGiven2() const;
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
    void setEmergencyContact(QString emergencyContact);
    void setAdditionalNotes(QString additionalNotes);

    // Vaccine & Covid Info Setters
    void setVaccineStatus(QString vaccineStatus);
    void setVaccineName1(QString vaccineName1);
    void setBatchNumber1(QString batchNumber1);
    void setDateGiven1(QString dateGiven1);
    void setVaccineName2(QString vaccineName2);
    void setBatchNumber2(QString batchNumber2);
    void setDateGiven2(QString dateGiven2);
    void setQRCode(QString qrCodeImage);
    void setCertificate(QString certificateImage);
    void setTestResult(QString testResultImage);
};

#endif // CLASSCITIZEN_H
