#include "contactslist.h"

// managing searchtab index using static member variable.

int ContactsList::contactIndex=0;

ContactsList::ContactsList() {

}

void ContactsList::AddNewContact(QString name, QString PhoneNumber, QString EmailAddress){
    Contacts contact=Contacts(name,PhoneNumber,EmailAddress);
    contactlist.append(contact);
    contactIndex++;
}
/*
    Add new contact in phonebook
    Require contents
        Name
        Phone number(unique)
        Nickname*/

std::vector<QString> ContactsList::SearchContacts(int index, bool bookmark){
    QString name=contactlist[index].getName();
    QString phone=contactlist[index].getPhoneNumber();
    QString email=contactlist[index].getEmailAddress();
    std::vector<QString> contact;
    contact.push_back(name);
    contact.push_back(phone);
    contact.push_back(email);
    if(bookmark){
        bookmarkedlist.append(contactlist[index]);
    }
    return contact;
}
// searchfun give you all contact in your contactlist and if you want to bookmark some index, you can.
// so editline -> push button(signal) -> showdetail(slots) and questionbox that would ask you bookmark or not. if bookmark, change color.



//get index or phonenumber from line_edit and press the btn signal, slot function activate, if phonenumber in contactlist, remove it.
int ContactsList::Remove(QString index,QString str){
    if(index!=""){
        contactlist.removeAt(index.toInt());
        contactIndex--;
    }
    else
    {
        for(int i=0;i<contactlist.size();i++){
            if(contactlist[i].getPhoneNumber()==str){
                contactlist.removeAt(i);

                contactIndex--;
                return i;
            }
        }

    }
    return 0;


}
// for debugging. show contact in contactlist using just console.
void ContactsList::show(){
    for(qint32 i=0;i<contactlist.size();i++){
        qDebug()<<contactlist[i].getName()<<" "<<contactlist[i].getPhoneNumber()<<" "<<contactlist[i].getEmailAddress();
    }
}

Contacts ContactsList::getContacts(int index){
    return contactlist[index];
}

qint32 ContactsList::getIndex(){
    return contactIndex;
}




