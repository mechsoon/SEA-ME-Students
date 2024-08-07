#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]){
    std::string command(argv[1]);
    std::string str="";

    for(int i=2;i<argc;i++){
        if(i>2){
            str+=" ";
        }
        str+=argv[i];
    }
    
    std::string change="";
    if(command=="up"){
        for(auto& chr:str){
            change+=toupper(chr);
        }
    }
    else if(command=="down")
    {
        for(auto& chr:str){
            change+=tolower(chr);
        }
    }
    std::cout<<change;
}