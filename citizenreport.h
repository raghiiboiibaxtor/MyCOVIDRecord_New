#ifndef CITIZENREPORT_H
#define CITIZENREPORT_H

#include "classcitizen.h"
#include <QString>
#include <QVector>


class citizenReport
{
private:
    QString reportCategory;
    QString reportSubject;
    QString reportDetails;

public:
    explicit citizenReport(QString reportCategory, QString reportSubject, QString reportDetails);

    QString getCategory();
    QString getSubject();
    QString getDetails();

    void setCategory(QString reportCategory);
    void setSubject(QString reportSubject);
    void setDetails(QString reportDetails);
};

#endif // CITIZENREPORT_H
