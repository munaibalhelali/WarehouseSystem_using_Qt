#include "warehouseSystem/util.hpp"

std::string _getStringFromKeyboard(std::string msg){
    std::string input = "";
    std::cout<<msg<<": ";
    std::getline(std::cin,input);
    std::cout<<std::endl;
    return input;
}

std::string _getRoleFromKeyboard(){
    std::string input = _getStringFromKeyboard("Choose one of the following roles: \n\
    [1] Admin\n\
    [2] Worker\n\
    Your choice");
    if(input != "1" && input != "2"){
        bool validInput = false;
        for(int i = 0; i<3; i++){
            input = _getStringFromKeyboard("Your choice is not valide! choose again.\nYour choice");
            if(input == "1" || input == "2"){
                validInput = true;
                break;
            }
        }
        if(!validInput){
            return "";
        }
    }
    std::string role = input == "1" ? "Admin" : "Worker";
    return role;
}
