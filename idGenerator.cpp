#include "warehouse_system/idGenerator.hpp"

IdGenerator::IdGenerator() {}

bool IdGenerator::isExists(std::string category){
    auto categoryIdx = categoriesList.find(category);
    if (categoryIdx == categoriesList.end())
        return false;
    return true;
}
int IdGenerator::createNewCounter(std::string category)
{
    std::cout << "Creating a new category: " << category << std::endl;
    categoriesList.insert(std::pair<std::string, int>(category, 0));
}

std::string IdGenerator::generateID(std::string category)
{
    if (!isExists(category))
        throw std::invalid_argument("Category [" + category + "] does not exist!");
    std::string ID = category + "_" + std::to_string(categoriesList[category]);
    categoriesList[category]++;
    return ID;
}

std::map<std::string, int> IdGenerator::getCategoriesList()
{
    std::map<std::string, int> acopy(categoriesList);
    return acopy;
}

void IdGenerator::setCategoriesList(std::map<std::string, int> categList)
{
    categoriesList = categList;
}

int IdGenerator::getCategoryCounter(std::string category){
    if (isExists(category)){
        return categoriesList[category];
    }else{
        return -1;
    }
}
