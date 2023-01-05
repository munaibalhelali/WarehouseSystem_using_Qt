#include "warehouse_system/view.hpp"

// Helper functionw
std::string _getProductIDFromKeyboard()
{
    string product_id;
    std::cout << "Enter product ID: ";
    std::cin >> product_id;
    return product_id;
}

int _getAmountFromKeyboard(string msg = "")
{
    int num_units;
    if (msg == "")
    {
        std::cout << "Enter the number of units to dispatch: ";
    }
    else
    {
        std::cout << msg << " : ";
    }
    std::cin >> num_units;
    return num_units;
}

void _printProductStock(map<std::string, int> stockList)
{
    std::cout << "Product: Available stock" << std::endl;

    for (auto product : stockList)
    {
        std::cout << product.first << " : " << product.second << std::endl;
    }
}

std::string _getZoneFromKeyboard(vector<std::string> availableZones)
{
    int choice;
    std::cout << "Choose one of the following zones: " << std::endl;
    int counter = 0;
    for (auto i = availableZones.begin(); i != availableZones.end(); ++i)
    {
        std::cout << "[" << ++counter << "] " << *i << std::endl;
    }
    std::cout << "Your choice: ";
    std::cin >> choice;
    return availableZones[choice-1];
}

// Class defination
View::View() {}
bool View::addNewUser(){return false;}
bool View::removeUser(){return false;}
bool View::createProduct(){return false;}
bool View::removeProduct(){return false;}
bool View::createZone(){return false;}
bool View::removeZone(){return false;}
bool View::generateReport(){return false;}
bool View::addStock()
{

    std::string product_id = _getProductIDFromKeyboard();
    Product product = database.getProduct(product_id);
    if(product.getID() == ""){
        std::cout<<"Produt: "<<product_id<<" does not exist. Please add it first to the system before you can add stock"<<std::endl;
        return false;
    }
    int num_units = _getAmountFromKeyboard("Enter then number of new units");
    vector<std::string> availableZones = database.getAvailableZones();
    std::string zone = _getZoneFromKeyboard(availableZones);
    database.addStock(product_id, zone,num_units);
    return true;
}

bool View::dispatchStock()
{
    std::string product_id = _getProductIDFromKeyboard();
    Product product = database.getProduct(product_id);
    if(product.getID() == ""){
        std::cout<<"Produt: "<<product_id<<" does not exist. Please add it first to the system before you can dispatch stock"<<std::endl;
        return false;
    }
    int num_units = _getAmountFromKeyboard("Enter the number of units to dispatch");
    vector<std::string> availableZones = database.getProductAvailableZones(product_id);
    std::string zone = _getZoneFromKeyboard(availableZones);
    database.reduceStock(product_id, zone, num_units);
}

bool View::viewStock()
{
    while (1)
    {
        int choice = 0;
        std::cout << "Choose one of the following:\
                    \n[1] View specific product\
                    \n[2] View all products\
                    \n[99] Cancel"
                  << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string productID = _getProductIDFromKeyboard();
            int stock = database.getProductStock(productID);
            pair<std::string, int> product(productID, stock);
            std::map<std::string, int> stockList;
            stockList.insert(product);
            _printProductStock(stockList);
            break;
        }
        case 2:
        {
            std::map<std::string, int> allStock = database.getAllStock();
            _printProductStock(allStock);
            break;
        }

        case 99:
            return true;

        default:
            std::cout << "Wrong choice!" << std::endl;
            break;
        }
    }
    return true;
}
