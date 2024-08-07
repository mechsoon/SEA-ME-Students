#include "oldphonebook.h"
using namespace std;

int main(){
    cout<<"Phonebook Application\n 1. ADD, 2. SEARCH, 3. REMOVE, 4. BOOKMARK, 5. EXIT\n\n";
    Phonebook pb;
    int flag=1;
    while(flag!=0){
        std::string command;
        cin>>command;
        if(command=="ADD"){
            pb.ADD();
        }
        else if(command=="SEARCH"){
            pb.SEARCH();
        }
        else if(command=="REMOVE"){
            pb.REMOVE();
        }
        else if(command=="BOOKMARK"){
            pb.BOOKMARK();
        }else{
            flag=pb.EXIT();
        }
        if(flag==0){
            return 0;
        }else{
        cout<<"Phonebook Application\n 1. ADD, 2. SEARCH, 3. REMOVE, 4. BOOKMARK, 5. EXIT\n\n";
        }
    }

}