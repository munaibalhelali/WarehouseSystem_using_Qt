#ifndef ADMIN_VIEW_
#define ADMIN_VIEW_
#include "warehouse_system/view.hpp"
#include "warehouse_system/databaseSQL.hpp"
#include "warehouse_system/person.hpp"
#include "warehouse_system/product.hpp"
#include "warehouse_system/zone.hpp"
#include "warehouse_system/util.hpp"
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