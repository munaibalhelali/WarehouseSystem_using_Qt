#ifndef DATABASESQL_
#define DATABASESQL_
#include <iostream>
#include <stdlib.h>
#include <sqlite3.h>
#include <limits.h>
#include <map>
#include <string.h>
#include "warehouseSystem/person.hpp"
#include "warehouseSystem/database.hpp"
#include "warehouseSystem/idGenerator.hpp"
#include <QtSql/QSqlDatabase>

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


class DatabaseSQL : public Database
{
private:
    sqlite3 * db;
    QSqlDatabase db2;
    char * zErrMsg = 0;
    // char * sql;
    const char* data = "Callback function called!";
    const char* dbPath=""; 
    IdGenerator idGen;
    

    static int  _sqlCallback(void *data, int argc, char **argv, char **azColName);
    static int  _searchCallback(void *data, int argc, char **argv, char **azColName);
    void _createNewTable(const char* sql);
    int _insertIntoTable(const char* sql);
    int _recordStock(std::map<std::string, int> stock, std::string zone_id);
    void _updateIdGenInDatabase(std::string type, int counter);
    void _initializeIdGen();
    int _openDatabase();
    int _closeDatabase();

    
public:
    DatabaseSQL();
    DatabaseSQL(const char* path);
    ~DatabaseSQL();

    void addUser(Person newUser);
    Person getUser(std::string personID);
    bool removeUser(std::string personID);
    void addProduct(Product newProcut);
    Product getProduct(std::string productID);
    bool removeProduct(std::string productID);
    void addZone(Zone newZone);
    Zone getZone(std::string zoneID);
    bool removeZone(std::string zoneID);
    void addStock(std::string stockID,std::string zoneID, int amount );
    void reduceStock(std::string stockID, int amount);
    void reduceStock(std::string productID, std::string zoneID, int amount);
    int getProductStock(std::string stockID);
    int getProductStock(std::string stockID, std::string zoneID);
    std::map<std::string, int> getZoneStock(std::string zoneID);
    std::map<std::string, int>getAllStock();
    
    std::string generateID(std::string type);
    void createNewCounter(std::string category);
    std::vector<std::string> getProductAvailableZones(std::string productID);
    std::vector<std::string> getAvailableZones();

    std::map<std::string, std::vector<std::string>> search(std::string searchKeyworkd, std::string searchType, std::string tableName);

    
};

#endif //DATABASESQL_
