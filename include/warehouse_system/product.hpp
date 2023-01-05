#ifndef PRODUCT_
#define PRODUCT_

#include <string>
#include <iostream>

using namespace std;
class Product
{
private:
  string ID;
  string name;
  string manufacturer;
  string expiryDate;
  string dimensions;
  string category;

public:
  Product();
  Product(string id_, string name_, string manufacturer_, string expiryDate_, string dimensions_, string category_);  
  void setName(string name_);
  void setID(string id_);
  void setManufacturer(string manufacturer_);
  void setExpiryDate(string expiryDate_);
  void setDimensions(string dimensions_);
  void setCategory(string category_);

   string getID();
   string getName();
   string getManufacturer();
   string getEexpiryDate();
   string getDimensions();
   string getCategory();
};

#endif // PRODUCT_