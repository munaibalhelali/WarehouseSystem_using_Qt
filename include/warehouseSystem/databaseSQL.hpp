/**
 * @file databaseSQL.hpp
 * @author Munaib Al-Helali (moneebalhelaly@gmail.com)
 * @brief This is a database class that uses SQLITE3 database. It designed as an interface for the warehouse system to write and read from the database easily. 
 * @version 0.1
 * @date 2023-01-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DATABASESQL_
#define DATABASESQL_
#include <iostream>
#include <stdlib.h>
#include <sqlite3.h>
#include <limits.h>
#include <map>
#include <string.h>
#include "warehouseSystem/person.hpp"
#include "warehouseSystem/product.hpp"
#include "warehouseSystem/zone.hpp"
#include "warehouseSystem/idGenerator.hpp"
#include <QtSql/QSqlDatabase>

/**
 * @brief MACROS to get the needed libraries for getcwd function. 
 * 
 */
#ifdef __win32__ 
#include <direct.h>
#define GetCurrentDir _getcwd
#elif __win64__ 
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif


class DatabaseSQL
{
private:
    sqlite3 * db;
    QSqlDatabase db2;
    char * zErrMsg = 0;
    // char * sql;
    const char* data = "Callback function called!";
    const char* dbPath=""; 
    IdGenerator idGen;
    
    /**
     * @brief A callback function for the sqlite3_exec function. 
     * 
     * @param data a null pointer that will be passed by sqlite3_exec
     * @param argc the number of items returned by the query
     * @param argv an array of the resulted items
     * @param azColName the headers or column names corresponding to the items
     * @return int 
     */
    static int  _sqlCallback(void *data, int argc, char **argv, char **azColName);
    
    /**
     * @brief A callback function for the sqlite3_exec dedicated for the search function.  
     * 
     * @param data a null pointer that will be passed by sqlite3_exec
     * @param argc the number of items returned by the query
     * @param argv an array of the resulted items
     * @param azColName the headers or column names corresponding to the items
     * @return int 
     */
    static int  _searchCallback(void *data, int argc, char **argv, char **azColName);
    
    /**
     * @brief an internal method to create a new table based on the given sql. 
     * 
     * @param sql provides the required table schema 
     */
    void _createNewTable(const char* sql);
    
    /**
     * @brief  An internal method to insert data into a table based on the provided sql
     * 
     * @param sql provides the sql query of the data to be inserted 
     * @return int return the operation status SQLITE_OK on success
     */
    int _insertIntoTable(const char* sql);

    /**
     * @brief An internal method to record a map of stock into the stock table. 
     * 
     * @param stock A map of the stock of differnt products to be recorded 
     * @param zone_id The targeted zone to record the stock
     * @return int return the operation status SQLITE_OK on success
     */
    int _recordStock(std::map<std::string, int> stock, std::string zone_id);

    /**
     * @brief Updates the current counters of the idGenerator
     * 
     * @param type counter type (person, product, zone, ...)
     * @param counter current counter value
     */
    void _updateIdGenInDatabase(std::string type, int counter);
    
    /**
     * @brief intialize the idGenerator from the database 
     * 
     */
    void _initializeIdGen();
    
    /**
     * @brief open database at a give path in dbPath
     * 
     * @return int returns operation status SQLITE_OK on success
     */
    int _openDatabase();

    /**
     * @brief close sqlite3 database before destroying the instance 
     * 
     * @return int  returns operation status SQLITE_OK on success
     */
    int _closeDatabase();

    
public:
    DatabaseSQL();

    /**
     * @brief Construct a new DatabaseSQL object
     * 
     * @param path path to database
     */
    DatabaseSQL(const char* path);

    /**
     * @brief Destroy the DatabaseSQL object
     * 
     */
    ~DatabaseSQL();

    /**
     * @brief add new user to the database 
     * 
     * @param newUser a Person object to be recoreded
     * @return true on success
     * @return false on failure
     */
    bool addUser(Person newUser);

    /**
     * @brief Get the user information from the database
     * 
     * @param personID id of the person to be retrived 
     * @return Person 
     */
    Person getUser(std::string personID);

    /**
     * @brief remove the information of the user with the given id from the database 
     * 
     * @param personID id of the person to be removed
     * @return true  on success
     * @return false on failure
     */
    bool removeUser(std::string personID);

    /**
     * @brief add the product information to the database
     * 
     * @param newProduct the product object to be recoreded  
     * @return true on success
     * @return false on failure
     */
    bool addProduct(Product newProduct);

    /**
     * @brief Get the product information 
     * 
     * @param productID id of the product to be retrieved
     * @return Product 
     */
    Product getProduct(std::string productID);

    /**
     * @brief remove product with given id from the database 
     * 
     * @param productID id of the product to be removed
     * @return true on success
     * @return false on failure
     */
    bool removeProduct(std::string productID);

    /**
     * @brief add the zone information to the database
     * 
     * @param newZone the zone object to be recoreded 
     * @return true on success
     * @return false on failure
     */
    bool addZone(Zone newZone);

    /**
     * @brief Get the zone information from the database
     * 
     * @param zoneID id of the targeted zone 
     * @return Zone 
     */
    Zone getZone(std::string zoneID);

    /**
     * @brief remove a zone from the database 
     * 
     * @param zoneID id of the zone to be removed  
     * @return true on success
     * @return false on failure
     */
    bool removeZone(std::string zoneID);

    /**
     * @brief add/update product stock in a given zone 
     * 
     * @param stockID id of the targeted product 
     * @param zoneID  id of the targeted zone
     * @param amount  amount/number of units to be added
     * @return true on success
     * @return false on failure
     */
    bool addStock(std::string stockID,std::string zoneID, int amount );

    /**
     * @brief opposite to addStock method. It reduces the stock of a product from all zones. [not implemented yet] 
     * 
     * @param stockID id of the targeted product 
     * @param amount amount/number of unites to be reduced
     * @return true on success
     * @return false on failure
     */
    bool reduceStock(std::string stockID, int amount);
    
    /**
     * @brief opposite to addStock method. It reduces the stock of a product from a given zone. 
     * 
     * @param productID id of the target product 
     * @param zoneID id of the targeted zone
     * @param amount amount/number of unites to be reduced
     * @return true on success
     * @return false on failure
     */
    bool reduceStock(std::string productID, std::string zoneID, int amount);

    /**
     * @brief Get the amount of stock of a given product
     * 
     * @param productID id of the targeted product 
     * @return int available stock
     */
    int getProductStock(std::string productID);

    /**
     * @brief Get the amount of stock of agiven product in agiven zone.
     * 
     * @param productID id of the targeted product
     * @param zoneID id of the targeted zone
     * @return int available stock
     */
    int getProductStock(std::string productID, std::string zoneID);

    /**
     * @brief Get the a map of the all the products' stock in a given zone
     * 
     * @param zoneID id of the targeted zone 
     * @return std::map<std::string, int>  a map contains the product id and its corresponding stock.
     */
    std::map<std::string, int> getZoneStock(std::string zoneID);

    /**
     * @brief return the overall stock in the system from all the zones and for all of the products
     * 
     * @return std::map<std::string, int> a map contains products' ids and their stock from all of the zones.
     */
    std::map<std::string, int> getAllStock();
    

    /**
     * @brief generate an id of the provided type 
     * 
     * @param type counter type 
     * @return std::string the generated id
     */
    std::string generateID(std::string type);

    /**
     * @brief Create a New counter type
     * 
     * @param category the name or type of counter 
     */
    void createNewCounter(std::string type);

    /**
     * @brief Get the zones where the given product is stocked
     * 
     * @param productID id of the targeted product 
     * @return std::vector<std::string>  a vector of all zones
     */
    std::vector<std::string> getProductAvailableZones(std::string productID);

    /**
     * @brief Get all of the available zones in the system
     * 
     * @return std::vector<std::string> a list of all zones 
     */
    std::vector<std::string> getAvailableZones();

    /**
     * @brief search for a product records in a given table. In the case of stock table, the functions search in both stock and products tables to retrieve the name of the product. 
     * 
     * @param searchKeyworkd a keyword to search for 
     * @param searchType a search type refers to which column of the table to search such as Name, id, Category, Amount
     * @param tableName the name of the targeted table
     * @return std::map<std::string, std::vector<std::string>> contains a map of the retrieved rows. The first row is headers while all other rows in the map has row_<number> keys. The keys are not necessery as the rows information are recorded in the vector under that key.
     */
    std::map<std::string, std::vector<std::string>> search(std::string searchKeyworkd, std::string searchType, std::string tableName);

    
};

#endif //DATABASESQL_
