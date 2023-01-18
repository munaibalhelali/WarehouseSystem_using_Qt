/**
 * @file driver.hpp
 * @author Munaib Al-Helali (moneebalhelaly@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
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
    /**
     * @brief Construct a new Driver object
     * 
     * @param user 
     */
    Driver(Person user);

    /**
     * @brief Destroy the Driver object
     * 
     */
    ~Driver();

    /**
     * @brief Set the Current User object
     * 
     * @param user 
     */
    void setCurrentUser(Person user);

    /**
     * @brief Get the Current User object
     * 
     * @return Person 
     */
    Person getCurrentUser();

    /**
     * @brief 
     * 
     */
    void run();

};

#endif //DRIVER_
