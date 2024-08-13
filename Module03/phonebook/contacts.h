#ifndef CONTACTS_H
#define CONTACTS_H
#include <QString>

class Contacts
{
private:
    QString name;
    QString PhoneNumber;
    QString EmailAddress;
public:
    Contacts(QString name,QString PhoneNumber,QString EmailAddress);
    Contacts();
    Contacts(const Contacts& contact);
    Contacts &operator=(const Contacts& contact);
    ~Contacts();

    const QString getName();
    QString getPhoneNumber();
    const QString getEmailAddress();
    void setName(QString name);
    void setPhoneNumber(QString PhoneNumber);
    void setEmailAddress(QString EmailAddress);

};

#endif // CONTACTS_H
