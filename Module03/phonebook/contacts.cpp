#include "contacts.h"

Contacts::Contacts(QString name,QString PhoneNumber,QString EmailAddress):name(name),PhoneNumber(PhoneNumber),EmailAddress(EmailAddress){}
Contacts::Contacts(){}
Contacts::Contacts(const Contacts& contact):name(contact.name),PhoneNumber(contact.PhoneNumber),EmailAddress(contact.EmailAddress){}
Contacts& Contacts::operator=(const Contacts& contact){
    if(this!=&contact){
        name=contact.name;
        PhoneNumber=contact.PhoneNumber;
        EmailAddress=contact.EmailAddress;
    }
    return *this;
}
Contacts::~Contacts(){}

const QString Contacts::getName(){
    return name;
}
QString Contacts::getPhoneNumber(){
    return PhoneNumber;
}
const QString Contacts::getEmailAddress(){
    return EmailAddress;
}
void Contacts::setName(QString name){
    this->name=name;
}
void Contacts::setPhoneNumber(QString PhoneNumber){
    this->PhoneNumber=PhoneNumber;
}
void Contacts::setEmailAddress(QString EmailAddress){
    this->EmailAddress=EmailAddress;
}
