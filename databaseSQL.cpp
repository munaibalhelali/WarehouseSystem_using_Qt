#include "warehouseSystem/databaseSQL.hpp"
#include <QDir>
#include <QDebug>

static std::map<std::string, std::string> returnMap;

#include <typeinfo>
int _receiveAllStock(void* data, int argc, char **argv, char **azColName){
    int i;
    // std::cout<<"in receiveAllStock "<<std::endl;
    for (i = 0; i < argc; i+=2)
    {
        const char *fieldData1 = argv[i] ? argv[i] : "NULL";
        const char *fieldData2 = argv[i+1] ? argv[i+1] : "NULL";
        returnMap.insert(std::pair<std::string, std::string>((std::string)fieldData1, (std::string)fieldData2));
    }
    return 0;
}

int _receiveVector(void* outputVector, int argc, char **argv, char **azColName){
    
    for(int i = 0; i <argc; i++){
        const char* data = argv[i] ? argv[i] : "NULL";
        (*(std::vector<std::string>*)outputVector).push_back((std::string) data);
    }

    return 0;
}

DatabaseSQL::DatabaseSQL()
{
    char buffer[PATH_MAX];
    GetCurrentDir(buffer, PATH_MAX);
//    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
//     db2.setDatabaseName("warehouse_system");
//     bool ok = db2.open();
//     if(ok){
//         qDebug()<<"opend database successfully!";
//     }else{
//         qDebug()<<"failed to opend database!";
//     }
    strcat(buffer, "/data/warehouse_system.db");
    dbPath = buffer;
    _openDatabase();
    _initializeIdGen();

}

DatabaseSQL::DatabaseSQL(const char *path)
{
    dbPath = path;
    _openDatabase();
    _initializeIdGen();
}

DatabaseSQL::~DatabaseSQL()
{
    _closeDatabase();
}

void DatabaseSQL::_initializeIdGen(){
    char sql[4096] = "SELECT Class as counterType, Counter FROM id_generator;";
    std::map<std::string, int>tempMap;

    int rc = sqlite3_exec(db, sql, _receiveAllStock, 0, &zErrMsg);

    if(rc != SQLITE_OK){
        std::cout<<"Could not retrieved counters data!"<<std::endl;
    }else{
       if (!returnMap.empty())
        {   int productStock = 0;
            for (auto p: returnMap){
                if(p.second != "NULL" && p.second != ""){
                    productStock = std::stoi(p.second);
                }
                tempMap.insert(std::pair<std::string, int>(p.first, productStock ));
            }
            returnMap.clear(); 
            idGen.setCategoriesList(tempMap);
        }
    }
}

bool DatabaseSQL::addUser(Person newUser)
{
    char sql[4096] = "INSERT INTO persons (id, Name, Role, Password) VALUES('";
    strcat(sql, newUser.getID().c_str());
    strcat(sql, "', '");
    strcat(sql, newUser.getName().c_str());
    strcat(sql, "', '");
    strcat(sql, newUser.getRole().c_str());
    strcat(sql, "', '");
    strcat(sql, newUser.getPassword().c_str());
    strcat(sql, "');");
    int rc = _insertIntoTable(sql);
    return (rc == SQLITE_OK)? true: false;
}

Person DatabaseSQL::getUser(std::string personID)
{
    char sql[4096] = "SELECT * FROM persons WHERE id = '";
    strcat(sql, personID.c_str());
    strcat(sql, "';");

    int rc = sqlite3_exec(db, sql, _sqlCallback, (void *)data, &zErrMsg);
    if (rc)
    {
        std::cerr << "Can't read data!" << sqlite3_errmsg(db) << std::endl;
    }
    else
    {

        if (!returnMap.empty())
        {
            Person tempPerson(returnMap["Name"],
                              returnMap["id"],
                              returnMap["Role"],
                              returnMap["Password"]);
            returnMap.clear();
            return tempPerson;
        }
    }
    return Person();
}

bool DatabaseSQL::removeUser(std::string personID){
    char sql[4096] = "DELETE FROM persons WHERE id = '";
    strcat(sql, personID.c_str());
    strcat(sql, "';");
    int rc = sqlite3_exec(db, sql, _sqlCallback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        return false;
    }else{
        return true;
    }
}

bool DatabaseSQL::addProduct(Product newProduct)
{
    char sql[4096] = "INSERT INTO products (id, Name, Manufacturer, ExpiryDate, Size, Category) VALUES('";
    strcat(sql, newProduct.getID().c_str());
    strcat(sql, "', '");
    strcat(sql, newProduct.getName().c_str());
    strcat(sql, "', '");
    strcat(sql, newProduct.getManufacturer().c_str());
    strcat(sql, "', '");
    strcat(sql, newProduct.getEexpiryDate().c_str());
    strcat(sql, "', '");
    strcat(sql, newProduct.getDimensions().c_str());
    strcat(sql, "', '");
    strcat(sql, newProduct.getCategory().c_str());
    strcat(sql, "');");
    int rc = _insertIntoTable(sql);
    return (rc == SQLITE_OK)? true: false;
}

Product DatabaseSQL::getProduct(std::string productID) {
    char sql[4096] = "SELECT * FROM products WHERE id = '";
    strcat(sql, productID.c_str());
    strcat(sql, "';");

    int rc = sqlite3_exec(db, sql, _sqlCallback, (void *)data, &zErrMsg);
    if (rc)
    {
        std::cerr << "Can't read data!" << sqlite3_errmsg(db) << std::endl;
    }
    else
    {

        if (!returnMap.empty())
        {
            Product tempProduct(returnMap["Name"],
                              returnMap["id"],
                              returnMap["Manufacturer"],
                              returnMap["ExpiryDate"],
                              returnMap["Dimensions"],
                              returnMap["Category"]);
            returnMap.clear();
            return tempProduct;
        }
    }
    return Product();
}

bool DatabaseSQL::removeProduct(std::string productID){
    char sql[4096] = "DELETE FROM products WHERE id = '";
    strcat(sql, productID.c_str());
    strcat(sql, "';");
    int rc = sqlite3_exec(db, sql, _sqlCallback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        return false;
    }else{
        return true;
    }
}

bool DatabaseSQL::addZone(Zone newZone)
{
    char sql[4096] = "INSERT INTO zones (id, Area, Category, Location) VALUES('";
    strcat(sql, newZone.getID().c_str());
    strcat(sql, "', '");
    strcat(sql, newZone.getArea().c_str());
    strcat(sql, "', '");
    strcat(sql, newZone.getCategory().c_str());
    strcat(sql, "', '");
    strcat(sql, newZone.getLocation().c_str());
    strcat(sql, "');");
    int rc = _insertIntoTable(sql);
    std::map<std::string, int>stock = newZone.getStock();
    if(!stock.empty()){
        _recordStock(stock, newZone.getID());
    }
    return (rc == SQLITE_OK)? true: false;
    
}
Zone DatabaseSQL::getZone(std::string zoneID)
{
    char sql[4096] = "SELECT id, Area, Category, Location FROM zones WHERE id = '";
    strcat(sql, zoneID.c_str());
    strcat(sql, "';");
    std::map<std::string, int> zoneStock = getZoneStock(zoneID);
    int rc = sqlite3_exec(db, sql, _sqlCallback, (void *)data, &zErrMsg);
    if (rc)
    {
        std::cerr << "Can't read data!" << sqlite3_errmsg(db) << std::endl;
    }
    else
    {

        if (!returnMap.empty())
        {
            
            Zone tempZone(returnMap["Area"],
                        returnMap["id"],
                        returnMap["Category"],
                        returnMap["Location"],
                        zoneStock
                        );
            returnMap.clear();
            return tempZone;
        }
    }
    return Zone();
}

bool DatabaseSQL::removeZone(std::string zoneID){
    char sql[4096] = "DELETE FROM zones WHERE id = '";
    strcat(sql, zoneID.c_str());
    strcat(sql, "';");
    int rc = sqlite3_exec(db, sql, _sqlCallback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        return false;
    }else{
        return true;
    }
}

bool DatabaseSQL::addStock(std::string productID,std::string zoneID, int quantity)
{
    Product product = getProduct(productID);
    if(product.getID() == ""){
        std::cout<<"Product: "<<productID<<" does not exist!"<<std::endl;
        return false;
    }

    char sql[4096] = "";
    int productStock = getProductStock(productID, zoneID);
    if (productStock == -1){
        strcpy(sql, "INSERT INTO stock (Product_id, Zone_id, Quantity) VALUES('" );
        strcat(sql, productID.c_str());
        strcat(sql, "', '");
        strcat(sql, zoneID.c_str());
        strcat(sql, "', ");
        strcat(sql, std::to_string(quantity).c_str());
        strcat(sql, ");");
    }else{
        std::string updatedStock = std::to_string(productStock + quantity);
        
        strcpy(sql, "UPDATE stock SET Quantity = ");
        strcat(sql, updatedStock.c_str());
        strcat(sql, " WHERE Product_id = '");
        strcat(sql, productID.c_str());
        strcat(sql, "' AND Zone_id = '");
        strcat(sql, zoneID.c_str());
        strcat(sql, "' ;");
    }
    int rc = _insertIntoTable(sql);
    return (rc == SQLITE_OK)? true: false;
}
bool DatabaseSQL::reduceStock(std::string productID, int amount) { return false;}
bool DatabaseSQL::reduceStock(std::string productID, std::string zoneID, int quantity) {
    char sql[4096] = "";
    int productStock = getProductStock(productID, zoneID);
    if (productStock == -1){
        std::cout<<"No stock of product: "<< productID<< " in zone : "<< zoneID<<std::endl;
    }else{
        if(quantity > productStock){
            std::cout<<"Not enough stock in zone: "<<zoneID<<std::endl;
            return false;
        }

        std::string updatedStock = std::to_string(productStock - quantity);
        
        strcpy(sql, "UPDATE stock SET Quantity = ");
        strcat(sql, updatedStock.c_str());
        strcat(sql, " WHERE Product_id = '");
        strcat(sql, productID.c_str());
        strcat(sql, "' AND Zone_id = '");
        strcat(sql, zoneID.c_str());
        strcat(sql, "' ;");
    }
    int rc = _insertIntoTable(sql);
    return (rc == SQLITE_OK)? true: false;
}

int DatabaseSQL::getProductStock(std::string productID) {
    char sql[4096] = "SELECT SUM(Quantity) AS Quantity FROM stock WHERE Product_id = '";
    strcat(sql, productID.c_str());
    strcat(sql, "';");

    int rc = sqlite3_exec(db, sql, _sqlCallback, &data, &zErrMsg);
    if(rc != SQLITE_OK){
        std::cout<<"Could not execute query: "<<sql<<std::endl;
    } else{

        if (!returnMap.empty())
        {
            if(returnMap["Quantity"] == "NULL"){
                return -1;
            }
            int quant = std::stoi(returnMap["Quantity"]);
            returnMap.clear(); 
            return quant;
        }
    }
    return -1;

    
}

int DatabaseSQL::getProductStock(std::string productID, std::string zoneID) {
    char sql[4096] = "SELECT SUM(Quantity) AS Quantity FROM stock WHERE Product_id = '";
    strcat(sql, productID.c_str());
    strcat(sql, "' AND Zone_id = '");
    strcat(sql, zoneID.c_str());
    strcat(sql, "';");


    int rc = sqlite3_exec(db, sql, _sqlCallback, &data, &zErrMsg);
    if(rc != SQLITE_OK){
        std::cout<<"Could not execute query: "<<sql<<std::endl;
    } else{

        if (!returnMap.empty())
        {
            if(returnMap["Quantity"] == "NULL"){
                return -1;
            }
            int quant = std::stoi(returnMap["Quantity"]);
            returnMap.clear(); 
            return quant;
        }
    }
    return -1;

    
}

std::map<std::string, int> DatabaseSQL::getZoneStock(std::string zoneID){
    char sql[4096] = "SELECT Product_id as productID, SUM(Quantity) AS Quantity FROM stock WHERE Zone_id = '";
    strcat(sql, zoneID.c_str());
    strcat(sql, "' GROUP BY Product_id;");
    
    std::map<std::string, int> tempMap;

    int rc = sqlite3_exec(db, sql, _receiveAllStock, &data, &zErrMsg);
    if(rc != SQLITE_OK){
        std::cout<<"Could not execute query: "<<sql<<std::endl;
    } else{
        if (!returnMap.empty())
        {   int productStock = 0;
            for (auto p: returnMap){
                if(p.second != "NULL" && p.second != ""){
                    productStock = std::stoi(p.second);
                }
                tempMap.insert(std::pair<std::string, int>(p.first, productStock ));
            }
            returnMap.clear(); 
            return tempMap;
        }
    }
    return tempMap; 
}

std::map<std::string, int> DatabaseSQL::getAllStock() {
    char sql[4096] = "SELECT Product_id as productID, SUM(Quantity) AS Quantity FROM stock GROUP BY Product_id;";
    
    std::map<std::string, int> tempMap;

    int rc = sqlite3_exec(db, sql, _receiveAllStock, &data, &zErrMsg);
    if(rc != SQLITE_OK){
        std::cout<<"Could not execute query: "<<sql<<std::endl;
    } else{

        if (!returnMap.empty())
        {   int productStock = 0;
            for (auto p: returnMap){
                if(p.second != "NULL" && p.second != ""){
                    productStock = std::stoi(p.second);
                }
                tempMap.insert(std::pair<std::string, int>(p.first, productStock ));
            }
            returnMap.clear(); 
            return tempMap;
        }
    }
    return tempMap; 

}

int DatabaseSQL::_openDatabase()
{
    int rc = sqlite3_open(dbPath, &db);
    if (rc)
    {
        std::cerr << "Can't open database: %s\n", sqlite3_errmsg(db);
        return (0);
    }
    else
    {
        std::cerr << "Opened database successfully\n";
    }
    return rc;
}

int DatabaseSQL::_closeDatabase()
{
    int rc = sqlite3_close(db);
    return rc;
}

void DatabaseSQL::_createNewTable(const char *sql)
{
    int rc = sqlite3_exec(db, sql, _sqlCallback, 0, &zErrMsg);
    if (rc)
    {
        std::cerr << "Can't create a table!" << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cerr << "created the table successfully!" << std::endl;
    }
}

int DatabaseSQL::_insertIntoTable(const char *sql)
{
    std::cout<<sql<<std::endl;
    int rc = sqlite3_exec(db, sql, _sqlCallback, &data, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cout << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        std::cout << "Records created successfully" << std::endl;
    }
    return rc;
}

int DatabaseSQL::_sqlCallback(void *data, int argc, char **argv, char **azColName)
{
    std::map<std::string, std::string> rMap;
    int i;

    for (i = 0; i < argc; i++)
    {
        const char *fieldData = argv[i] ? argv[i] : "NULL";
        rMap.insert(std::pair<std::string, std::string>((std::string)azColName[i], (std::string)fieldData));
        // std::cout<<azColName[i]<<": "<<fieldData<<std::endl;
    }
    std::cout << std::endl;
    returnMap = rMap;
    return 0;
}

int DatabaseSQL::_searchCallback(void *outputMap, int argc, char **argv, char **azColName)
{
    std::vector<std::string> tempVec;
    std::vector<std::string> headers;
    for(int i = 0; i <argc; i++){
        const char* data = argv[i] ? argv[i] : "NULL";
        tempVec.push_back((std::string) data);
        headers.push_back(azColName[i]);
    }
    int currRow = (*(std::map<std::string,std::vector<std::string>>*)outputMap).size();
    (*(std::map<std::string,std::vector<std::string>>*)outputMap)["headers"] = headers;
    (*(std::map<std::string,std::vector<std::string>>*)outputMap)["row_"+std::to_string(currRow)] = tempVec;

    return 0;
}

int DatabaseSQL::_recordStock(std::map<std::string, int> stock, std::string zoneID){

    char sql[4096] = "";
    int rc;
    for(auto p: stock){
        addStock(p.first, zoneID, p.second);
        }
    return rc;
}

std::string DatabaseSQL::generateID(std::string category){
    std::string id = idGen.generateID(category);
    int updatedCounter = idGen.getCategoryCounter(category);
    if(updatedCounter != -1){
        _updateIdGenInDatabase(category, updatedCounter);
        return id;
    
    }
    return "";

}

void DatabaseSQL::_updateIdGenInDatabase(std::string type, int counter){
    char sql[9046] = "UPDATE id_generator SET Counter = ";
    strcat(sql, std::to_string(counter).c_str());
    strcat(sql, " WHERE Class = '");
    strcat(sql, type.c_str());
    strcat(sql, "';");
    int rc = sqlite3_exec(db, sql, _sqlCallback, 0, &zErrMsg);
}

void DatabaseSQL::createNewCounter(std::string category){
    idGen.createNewCounter(category);
    int counter = idGen.getCategoryCounter(category);
    std::cout<<"new counter "<<counter<<std::endl;
    if(counter != -1){
        char sql[4096] = "INSERT INTO id_generator(Class, Counter) VALUES('";
        strcat(sql, category.c_str());
        strcat(sql, "', ");
        strcat(sql, std::to_string(counter).c_str());
        strcat(sql, ");");
        int rc = sqlite3_exec(db, sql, _sqlCallback, 0, &zErrMsg);
        if(rc != SQLITE_OK){
            std::cout<<"Could not save new counter: "<<zErrMsg<<std::endl;
        }
    
    }
}

std::vector<std::string> DatabaseSQL::getProductAvailableZones(std::string productID){
    char sql[4096] = "SELECT DISTINCT Zone_id FROM stock WHERE Product_id = '";
    strcat(sql, productID.c_str());
    strcat(sql, "' ORDER BY CAST(SUBSTR(Zone_id, 6) AS INTEGER) ASC;");
    std:vector<std::string> outputVector;
    int rc = sqlite3_exec(db, sql, _receiveVector, &outputVector, &zErrMsg); 
    if(rc != SQLITE_OK){
        std::cout<<"Error: "<<zErrMsg<<std::endl;
    }

    return outputVector;
}

std::vector<std::string> DatabaseSQL::getAvailableZones(){
    const char* sql = "SELECT id FROM zones ORDER BY CAST(SUBSTR(id, 6) AS INTEGER) ASC;";
    std:vector<std::string> outputVector;
    int rc = sqlite3_exec(db, sql, _receiveVector, &outputVector, &zErrMsg); 
    if(rc != SQLITE_OK){
        std::cout<<"Error: "<<zErrMsg<<std::endl;
    }
    return outputVector;

}

std::map<string, std::vector<string> > DatabaseSQL::search(string searchKeyworkd, string searchType, string tableName)
{
    char sql[4096] = "";
    if(tableName == "stock"){
        strcat(sql, "SELECT stock.Product_id as Product_id, products.Name as Product_name, stock.Zone_id as Zone_id, stock.Quantity as Quantity FROM stock JOIN products on stock.Product_id=products.id where ");
        strcat(sql, searchType.c_str());
        strcat(sql, " LIKE '%");
        strcat(sql, searchKeyworkd.c_str());
        strcat(sql, "%';");
    }else{
        strcat(sql, "SELECT * FROM ");
        strcat(sql, tableName.c_str());
        strcat(sql, " where ");
        strcat(sql, searchType.c_str());
        strcat(sql, " LIKE '%");
        strcat(sql, searchKeyworkd.c_str());
        strcat(sql, "%';");
    }
    std::map<std::string, std::vector<std::string>> resultsMap;
    int rc = sqlite3_exec(db, sql, _searchCallback, &resultsMap , &zErrMsg);
    if(rc != SQLITE_OK){
        std::cout<<"Could not save new counter: "<<zErrMsg<<std::endl;
    }else{
        for(auto item: resultsMap){
            std::cout<<item.first<<std::endl;
            for(auto data: item.second){
                std::cout<<data<<", ";
            }
            std::cout<<std::endl;
        }
    }
    return resultsMap;
}
