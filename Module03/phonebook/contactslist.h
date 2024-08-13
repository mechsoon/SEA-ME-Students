#ifndef CONTACTSLIST_H
#define CONTACTSLIST_H
#include "contacts.h"
#include <QList>
#include <QDebug>
#include <QMessageBox>
#include <vector>
class ContactsList
{
private:
    QList<Contacts> contactlist;
    static int contactIndex;
    QList<Contacts> bookmarkedlist;

public:
    ContactsList();
    void AddNewContact(QString name, QString PhoneNumber, QString EmailAddress);
    /*
    Add new contact in phonebook
    Require contents
        Name
        Phone number(unique)
        Nickname*/
    std::vector<QString> SearchContacts(int index,bool bookmark);
    int Remove(QString index, QString PhoneNumber);
    void show();
    Contacts getContacts(int index);
    static qint32 getIndex();
};


#endif // CONTACTSLIST_H


