#include "warehouseSystem/adminView.hpp"

AdminView::AdminView() : View(){}

bool AdminView::addNewUser(){
    std::string name = _getStringFromKeyboard("Enter name");
    std::string role = _getRoleFromKeyboard();
    if(role == ""){
        return false;
    }
    std::string password = _getStringFromKeyboard("Enter your password");
    std::string confirmPassowrd = _getStringFromKeyboard("Confirm you password");
    if(password != confirmPassowrd){
        std::cout<<"Passwords does not match!"<<std::endl;
        return false;
    }
    std::string id = database.generateID("person");
    Person person(name, id, role, password);
    database.addUser(person);
    return true;
}

bool AdminView::removeUser(){
    std::string id = _getStringFromKeyboard("Enter user id to remove");
    Person person = database.getUser(id);
    if(person.isEmpty()){
        std::cout<<"User: "<<id<<" does not exist!"<<std::endl;
        return false;
    }
    database.removeUser(id);
    return true;
}

bool AdminView::createProduct()
{
    std::string name = _getStringFromKeyboard("Enter product name");
    std::string manufacturer = _getStringFromKeyboard("Enter manufacurer");
    std::string expDate = _getStringFromKeyboard("Enter expiry date");
    std::string dimensions = _getStringFromKeyboard("Enter size");
    std::string category = _getStringFromKeyboard("Enter category");
    std::string id = database.generateID("product");
    Product product(name, id, manufacturer, expDate, dimensions, category);
    database.addProduct(product);
    return true; 
}

bool AdminView::removeProduct() {
    std::string id = _getStringFromKeyboard("Enter product id to remove");
    Product product = database.getProduct(id);
    if(product.getID() == ""){
        std::cout<<"Product: "<<id<<" does not exist!"<<std::endl;
        return false;
    }
    database.removeProduct(id);
    return true;
}

bool AdminView::createZone() {
    std::string area = _getStringFromKeyboard("Enter zone area");
    std::string category = _getStringFromKeyboard("Enter zone category");
    std::string location = _getStringFromKeyboard("Enter zone's location");
    std::string id = database.generateID("zone");
    std::map<std::string, int> stock;
    Zone zone(area, id, category, location, stock);
    database.addZone(zone);
    return true; 
}
bool AdminView::removeZone() {
    std::string id = _getStringFromKeyboard("Enter zone id to remove");
    Zone zone = database.getZone(id);
    if(zone.getID() == ""){
        return false;
    }
    database.removeZone(id);
    return true;
}
bool AdminView::generateReport() {
    throw std::exception();
}
