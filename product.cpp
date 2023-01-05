#include "warehouse_system/product.hpp"
using namespace std;
// class
Product::Product()
{
  name = "";
  ID = "";
  manufacturer = "";
  expiryDate = "";
  dimensions = "";
  category = "";
}

Product::Product(string name_, string id_, string manufacturer_, string expiryDate_, string dimensions_, string category_)
{
  name = name_;
  ID = id_;
  manufacturer = manufacturer_;
  expiryDate = expiryDate_;
  dimensions = dimensions_;
  category = category_;
}

// setters

    void Product::setID(string id_)
    {
      ID = id_;
    }
    void Product::setName(string name_) {
      name=name_;
    }
    void Product::setManufacturer(string manufacturer_) {
      manufacturer=manufacturer_;
    }
    
    void Product::setExpiryDate(string expiryDate_) {
      expiryDate=expiryDate_;
    }
    void Product::setDimensions(string dimensions_) {
      dimensions=dimensions_;
    } 
    void Product::setCategory(string category_) {
      category=category_;
    }
    
    //getters
    string Product::getID() {
      return ID;
    }
    string Product::getName() {
      return name;
    }
     string Product::getManufacturer() {
      return manufacturer;
    }
     string Product::getEexpiryDate() {
      return expiryDate;
    }
         string Product::getDimensions() {
      return dimensions;
    }
         string Product::getCategory() {
      return category;
    }
