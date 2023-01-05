#ifndef DRIVER_
#define DRIVER_
#include <iostream>
#include <string>

#include "warehouse_system/view.hpp"
#include "warehouse_system/adminView.hpp"
#include "warehouse_system/person.hpp"

class Driver
{

    Person currentUser;
    View *view;
    Driver(){}
    
public:
    Driver(Person user);
    ~Driver();
    void setCurrentUser(Person user);
    Person getCurrentUser();
    void run();

};

#endif //DRIVER_