#ifndef DRIVER_
#define DRIVER_
#include <iostream>
#include <string>

#include "warehouseSystem/view.hpp"
#include "warehouseSystem/adminView.hpp"
#include "warehouseSystem/person.hpp"

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
