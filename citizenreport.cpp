#include "citizenreport.h"
#include <QString>

citizenReport::citizenReport(QString preferredName, QString preferredContact, QString reportCategory, QString reportSubject, QString reportDetails)
{
    this->preferredName = preferredName;
    this->preferredContact = preferredContact;
    this->reportCategory = reportCategory;
    this->reportSubject = reportSubject;
    this->reportDetails = reportDetails;
}

QString citizenReport::getName()
{
    return preferredName;
}

QString citizenReport::getContact()
{
    return preferredContact;
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

void citizenReport::setName(QString preferredName)
{
    this->preferredName = preferredName;
}

void citizenReport::setContact(QString preferredContact)
{
    this->preferredContact = preferredContact;
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
