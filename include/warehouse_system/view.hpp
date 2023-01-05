#ifndef VIEW_
#define VIEW_

#include <string>
#include <map>
#include <iostream>
#include "warehouse_system/product.hpp"
#include "warehouse_system/databaseSQL.hpp"

class View
{
protected:
    DatabaseSQL database;

public:
    View();
    virtual bool addNewUser();
    virtual bool removeUser();
    virtual bool createProduct();
    virtual bool removeProduct();
    virtual bool createZone();
    virtual bool removeZone();
    virtual bool generateReport();
    virtual bool addStock();
    virtual bool dispatchStock();
    virtual bool viewStock();
};

#endif // VIEW_