#include "warehouse_system/driver.hpp"
#include <stdlib.h>
#include <time.h>

enum functionsEnum {addNewUser=1, removeUser, createProduct, removeProduct, createZone, removeZone, generateReport, addStock, dispatchStock, viewStock};
std::vector<std::string> functionsDescription;

Driver::Driver(Person user){
    setCurrentUser(user);
}
Driver::~Driver(){
    delete view;
}
void Driver::setCurrentUser(Person user){
    currentUser = user;
    if (currentUser.getRole() == "Admin"){
        view = new AdminView();
    }else{
        view = new View();
    }
}
Person Driver::getCurrentUser(){
    return currentUser;
}
void Driver::run(){
    functionsDescription.push_back("");
    functionsDescription.push_back("Add new user");
    functionsDescription.push_back("Remove a user");
    functionsDescription.push_back("Create new product");
    functionsDescription.push_back("Remove a product");
    functionsDescription.push_back("Create new zone");
    functionsDescription.push_back("Remove a zone");
    functionsDescription.push_back("Generate a report");
    functionsDescription.push_back("Add stock");
    functionsDescription.push_back("Dispatch stock");
    functionsDescription.push_back("View available stock");

    while (1){
        sleep(1);
        system("clear");

        int input;
        int start, end;
        if(currentUser.getRole() == "Admin"){
            start = addNewUser;
            end = viewStock;
        }else{
            start = addStock;
            end = viewStock;
        }

        std::cout<<"Choose one of the following functions:"<<std::endl;
        for(int idx=start; idx<=end; idx++){
            std::cout<<"["<<idx<<"] "<<functionsDescription[idx]<<std::endl;
        }
        std::cout<<"Enter your input [Enter 100 to terminate the program]: ";
        std::cin>>input;
        std::cin.ignore(10000, '\n');
        if(input < start || input > end){
            if(input == 100){
                std::cout<<"Terminating the program! Good bye!"<<std::endl;
                break;
            }
            continue;
        }

        switch (input)
        {
        case addNewUser:
            view->addNewUser();
            break;
        case removeUser:
            view->removeUser();
            break;
        case createProduct:
            view->createProduct();
            break;
        case removeProduct:
            view->removeProduct();
            break;
        case createZone:
            view->createZone();
            break;
        case removeZone:
            view->removeZone();
            break;
        case generateReport:
            view->generateReport();
            break;
        case addStock:
            view->addStock();
            break;
        case dispatchStock:
            view->dispatchStock();
            break;
        case viewStock:
            view->viewStock();
            break;
        default:
            break;
        }
        

    }

}
