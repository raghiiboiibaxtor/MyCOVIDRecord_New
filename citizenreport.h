#ifndef CITIZENREPORT_H
#define CITIZENREPORT_H

#include "classcitizen.h"
#include <QString>
#include <QVector>


class citizenReport //: public classCitizen
{
private:
    QString preferredName;
    QString preferredContact;
    QString reportCategory;
    QString reportSubject;
    QString reportDetails;

public:
    explicit citizenReport(QString preferredName, QString preferredContact, QString reportCategory, QString reportSubject, QString reportDetails); //: classCitizen(name, email)

    QString getName();
    QString getContact();
    QString getCategory();
    QString getSubject();
    QString getDetails();

    void setName(QString preferredName);
    void setContact(QString preferredContact);
    void setCategory(QString reportCategory);
    void setSubject(QString reportSubject);
    void setDetails(QString reportDetails);
};

#endif // CITIZENREPORT_H
