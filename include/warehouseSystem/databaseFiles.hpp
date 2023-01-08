/*
 *File name: databseFiles.hpp
 *Author: Ashraf Yahya
 *About:
 */

#ifndef DATABASE_FILES_
#define DATABASE_FILES_
#include <vector>
#include "warehouse_system/database.hpp"
#include "warehouse_system/person.hpp"

class DatabaseFiles : public Database
{
private:
    std::vector<Person> usersList;
    std::vector<Product> productsList;
    std::vector<Zone> zonesList;
    int stock;

public:
    DatabaseFiles();
    ~DatabaseFiles(){};

    void addUser(Person newUser);
    Person getUser(std::string personID);
    void addProduct(Product newProduct);
    Product getProduct(std::string productID);
    void addZone(Zone newZone);
    Zone getZone(std::string zoneID);
    void addStock(std::string stockID,std::string zoneID, int amount);
    void reduceStock(std::string stockID, int amount);
    int getProductStock(std::string stockID);
    std::map<std::string, int> getAllStock();
    std::string generateID(std::string type);
    void createNewCounter(std::string category);
};

#endif // DATABASE_FILES_