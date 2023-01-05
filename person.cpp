#include "warehouse_system/person.hpp"


Person::Person()
{
    name = "";
    id = "";
    role = "";
    password = "";
    empty = true;
}

Person::Person(std::string name, std::string id, std::string role, std::string password)
{
    this->name = name;
    this->id = id;
    this->role = role;
    this->password = password;
    empty = false;
}

void Person::setName(std::string name)
{
    this->name = name;
    empty = false;
}

void Person::setID(std::string id)
{
    this->id = id;
    empty = false;
}

void Person::setRole(std::string role)
{
    this->role = role;
    empty = false;
}

void Person::setPassword(std::string password)
{
    this->password = password;
    empty = false;
}

std::string Person::getName()
{
    return name;
}

std::string Person::getID()
{
    return id;
}

std::string Person::getRole()
{
    return role;
}

std::string Person::getPassword()
{
    return password;

}
bool Person::isPasswordCorrect(std::string password)
{
    return this->password == password;
}

bool Person::isEmpty(){
    return empty;
}
