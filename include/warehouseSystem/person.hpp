#ifndef PERSON_
#define PERSON_

#include <string>
#include <iostream>

class Person
{
    std::string name;
    std::string id;
    std::string role;
    std::string password;
    bool empty;

public:
    Person();
    Person(std::string name, std::string id, std::string role, std::string password);
    void setName(std::string name);
    void setID(std::string id);
    void setRole(std::string role);
    void setPassword(std::string password);

    std::string getName();
    std::string getID();
    std::string getRole();
    std::string getPassword();

    bool isPasswordCorrect(std::string password);
    bool isEmpty();
};

#endif // PERSON_