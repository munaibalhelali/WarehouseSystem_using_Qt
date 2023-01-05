/*
 *File name: Databse
 *Author: Ashraf Yahya
 *About:
 */

#include "warehouse_system/databaseFiles.hpp"
using namespace std;

DatabaseFiles::DatabaseFiles() : Database() {}

void DatabaseFiles::addUser(Person newUser)
{
    Person userToAdd;

    try
    {
        usersList.push_back(userToAdd);
    }
    catch (std::exception e)
    {
        cout << "User couldn't be added!" << e.what() << endl;
    }
    
}
void DatabaseFiles::addProduct(Product newProduct){}
void DatabaseFiles::addZone(Zone newZone){}

Person DatabaseFiles::getUser(string personID)
{
    Person returnedPerson;
    returnedPerson.setID("ADFG");
    usersList.push_back(returnedPerson);
    Person temp;
    try
    {
        for (auto i = usersList.begin(); i != usersList.end(); i++)
        {
            if (i->getID() == personID)
                temp = *i;
        }
    }
    catch (std::exception e)
    {
        cout << "User's ID is not available!" << e.what() << endl;
    }
    return temp;
}

Product DatabaseFiles::getProduct(string productID)
{
    Product returnedProduct;
    // try{
    //     for(auto i=productsList.begin(); i<= productsList.end(); i++){
    //     if( productsList.ID.at(i)== productID)
    //     returnedProduct= productsList.at(i);
    //     }
    // } catch(...){
    //     cout<< "Product's ID is not available!"<<endl;
    // }
    return returnedProduct;
}

Zone DatabaseFiles::getZone(string zoneID)
{
    Zone returnedZone;
    // try{
    //     for(auto i=zonesList.begin(); i<= zonesList.end(); i++){
    //     if( zonesList.ID.at(i)== zoneID)
    //     returnedZone= zonesList.at(i);
    //     }
    // } catch(...){
    //     cout<< "Product's ID is not available!"<<endl;
    // }
    return returnedZone;
}

void DatabaseFiles::addStock(std::string stockID, std::string zoneID, int amount)
{
}
void DatabaseFiles::reduceStock(std::string stockID, int amount)
{
}
int DatabaseFiles::getProductStock(std::string stockID)
{
}
std::map<std::string, int> DatabaseFiles::getAllStock()
{
}
std::string DatabaseFiles::generateID(std::string type){}
void DatabaseFiles::createNewCounter(std::string category){}