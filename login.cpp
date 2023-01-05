#include "warehouse_system/login.hpp"
#include <stdlib.h>
#include <time.h>

Login::Login(){}

Person Login::login(){
    while(1){
        sleep(1);
        try{
        system("clear");
        }catch(exception e){
            std::cout<<e.what()<<std::endl;
        }

        std::string userID = _getStringFromKeyboard("Enter username");
        Person tempPerson = db.getUser(userID);
        if(tempPerson.isEmpty()){
            std::cout<<"Username does not exist!"<<std::endl;
            continue;
        }
        std::string userPassword;
        for(int i = 0; i<3; i++){
             userPassword = _getStringFromKeyboard("Enter your password");
            if(tempPerson.isPasswordCorrect(userPassword)){
                return tempPerson;
            }else{
                std::cout<<"Wrong password! ["<<i+1<<"/3]"<<std::endl;
            }
        }
        


    }
}
