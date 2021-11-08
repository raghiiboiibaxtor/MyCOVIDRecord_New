#include "citizenreport.h"
#include <QString>

citizenReport::citizenReport(QString reportCategory, QString reportSubject, QString reportDetails)
{
    this->reportCategory = reportCategory;
    this->reportSubject = reportSubject;
    this->reportDetails = reportDetails;
}

QString citizenReport::getCategory()
{
    return reportCategory;
}

QString citizenReport::getSubject()
{
    return reportSubject;
}

QString citizenReport::getDetails()
{
    return reportDetails;
}

void citizenReport::setCategory(QString reportCategory)
{
    this->reportCategory = reportCategory;
}

void citizenReport::setSubject(QString reportSubject)
{
    this->reportSubject = reportSubject;
}

void citizenReport::setDetails(QString reportDetails)
{
    this->reportDetails = reportDetails;
}
