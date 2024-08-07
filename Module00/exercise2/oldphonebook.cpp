#include "oldphonebook.h"

Phonebook::Phonebook(){}

Phonebook::Phonebook(std::string name,int PhoneNumber,std::string Nickname)
    :name(name), PhoneNumber(PhoneNumber), Nickname(Nickname){}

// Add new contact in vector

void Phonebook::ADD(){
    std::string AddName;
    int AddPhoneNumber;
    std::string AddNickname;
    std::cout<<"enter the name, phonenumber, nickname\n\n";
    std::cin>>AddName>>AddPhoneNumber>>AddNickname;
    Phonebook person=Phonebook(AddName,AddPhoneNumber,AddNickname);
    phonebook.push_back(person);
}

// display details of the contact and bookmark function.

void Phonebook::SEARCH(){
    int index;
    std::string bookmark;
    for(int i=0;i<phonebook.size();i++){
        std::cout<<"index : "<<i<<"st person's name is "<<phonebook[i].name<<"\n\n";
    }
    std::cout<<"do you want to display details of someone? then type the number of index\n\n";
    std::cin>>index;
    std::cout<<"name : "<<phonebook[index].name<<" PhoneNumber : "<<phonebook[index].PhoneNumber<<" Nickname : "<<phonebook[index].Nickname<<"\n\n";
    std::cout<<"do you want to bookmark the person? Press {Yes or NO.}\n\n";
    std::cin>>bookmark;
    if(bookmark=="Yes"){
        BookmarkList.push_back(phonebook[index]);
    }else{
        std::cout<<"Bookmark is cancelled";
    }
}

void Phonebook::REMOVE(){
    int RemoveNumber;
    int FindIndex{0};
    std::cout<<"Press the index or a phone number that you want to remove from contact.\n\n";
    std::cin>>RemoveNumber;
    // index case
    if(RemoveNumber<10000){
        phonebook.erase(phonebook.begin()+RemoveNumber);
    }else{
        for(int i=0;i<phonebook.size();i++){
            if(phonebook[FindIndex].PhoneNumber==RemoveNumber){
                phonebook.erase(phonebook.begin()+FindIndex);
            }
            FindIndex++;
        }
    }
}

void Phonebook::BOOKMARK(){
    for(int i=0;i<BookmarkList.size();i++){
        std::cout<<"BoomarkList\n";
        std::cout<<"index: "<<i<<" name: "<<BookmarkList[i].name<<" Phone number: "<<BookmarkList[i].PhoneNumber<<" Nickname: "<<BookmarkList[i].Nickname<<"\n\n";
    }
}

int Phonebook::EXIT(){
    return 0;
}
Phonebook::~Phonebook(){}