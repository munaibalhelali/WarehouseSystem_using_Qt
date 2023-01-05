#ifndef LOGIN_
#define LOGIN_

#include <iostream>
#include <string>
#include "warehouse_system/person.hpp"
#include "warehouse_system/databaseSQL.hpp"
#include "warehouse_system/util.hpp"

class Login
{
private:
  DatabaseSQL db;

public:
  Login();

  Person login();
  std::string getCurrentUser();
  std::string toJson(Person input);
};

#endif //LOGIN_