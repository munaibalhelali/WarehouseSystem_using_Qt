/*
 *File name: databse.hpp
 *Author: Ashraf Yahya
 *About: Ths file is an abstract class, that will be implemented in two ways:
 *        First way is database files and is writtin by Ashraf Yahya
 *        Second way is database SQML and is writtin by Munaib Al-Helali
 */

#ifndef DATABASE_
#define DATABASE_

#include <iostream>
#include <string>
#include <map>
#include "warehouse_system/person.hpp"
#include "warehouse_system/product.hpp"
#include "warehouse_system/zone.hpp"

class Database
{

public:
    Database(){};
    virtual ~Database(){};
    virtual void addUser(Person newUser) = 0;
    virtual Person getUser(std::string personID) = 0;
    virtual void addProduct(Product newProduct) = 0;
    virtual Product getProduct(std::string productID) = 0;
    virtual void addZone(Zone newZone) = 0;
    virtual Zone getZone(std::string zoneID) = 0;
    virtual void addStock(std::string productID, std::string zoneID, int amount) = 0;
    virtual void reduceStock(std::string stockID, int amount) = 0;
    virtual int getProductStock(std::string stockID) = 0;
    virtual std::map<std::string, int> getAllStock() = 0;
    virtual std::string generateID(std::string type)=0;
    virtual void createNewCounter(std::string category)=0;
};
#endif // DATABASE_