#pragma once
#include <string>
#include <vector>
#include <iostream>


class Phonebook{
    private:
        std::string name;
        int PhoneNumber;
        std::string Nickname;
        std::vector<Phonebook> phonebook;
        std::vector<Phonebook> BookmarkList;
    
    public:
        Phonebook();
        Phonebook(std::string name,int PhoneNumber,std::string Nickname);
        ~Phonebook();
        void ADD();
        void SEARCH();
        void REMOVE();
        void BOOKMARK();
        int EXIT();
};