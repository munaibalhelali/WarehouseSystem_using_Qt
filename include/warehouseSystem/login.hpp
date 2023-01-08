#ifndef LOGIN_
#define LOGIN_

#include <iostream>
#include <string>
#include "warehouseSystem/person.hpp"
#include "warehouseSystem/databaseSQL.hpp"
#include "warehouseSystem/util.hpp"

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
