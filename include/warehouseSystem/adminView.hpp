#ifndef ADMIN_VIEW_
#define ADMIN_VIEW_
#include "warehouseSystem/view.hpp"
#include "warehouseSystem/databaseSQL.hpp"
#include "warehouseSystem/person.hpp"
#include "warehouseSystem/product.hpp"
#include "warehouseSystem/zone.hpp"
#include "warehouseSystem/util.hpp"
#include <iostream>

class AdminView : public View
{


public:
    AdminView();
    bool addNewUser();
    bool removeUser();
    bool createProduct();
    bool removeProduct();
    bool createZone();
    bool removeZone();
    bool generateReport();
};

#endif // ADMIN_VIEW_
