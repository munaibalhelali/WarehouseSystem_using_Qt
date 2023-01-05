#ifndef ID_GENERATOR_
#define ID_GENERATOR_
#include <map>
#include <string>
#include <iostream>

class IdGenerator
{
    std::map<std::string, int> categoriesList;

public:
    IdGenerator();
    int createNewCounter(std::string category);
    std::string generateID(std::string category);

    std::map<std::string, int> getCategoriesList();
    void setCategoriesList(std::map<std::string, int> categList);
    int getCategoryCounter(std::string category);
    bool isExists(std::string category);
};

#endif // ID_GENERATOR_