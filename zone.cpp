#include "warehouse_system/zone.hpp"

// class:
Zone::Zone()
{
  ID = "";
  area = "";
  category = "";
  location = "";
}

Zone::Zone(string id_, string area_, string category_, string location_, map<string, int> stock_)
{
  // ID =  db.generateID("zone"); 
  ID = id_;
  area = area_;
  category = category_;
  location = location_;
  stock = stock_;
}

// setters:
void Zone:: setID(string id_)
 { 
  ID = id_;
 }
void Zone::setArea(string area_)
{
  area = area_;
}
void Zone::setCategory(string category_)
{
  category = category_;
}

void Zone::setLocation(string location_)
{
  location = location_;
}
void Zone::setStock(map<string, int> stock_)
{
  stock = stock_;
}

// getters:
string Zone::getID()
{
  return ID;
}
string Zone::getArea()
{
  return area;
}
string Zone::getCategory()
{
  return category;
}
string Zone::getLocation()
{
  return location;
}
map<string, int> Zone::getStock()
{
  return stock;
}

void Zone::addStock(std::string productID, int quantitiy){
  stock.insert(std::pair<std::string, int>(productID, quantitiy));
}
void Zone::dispatchStock(string productID, int quantity)
 {                                      
  stock[productID]  -= quantity; 
  }

jsoncons::json Zone::toJson()
{
  jsoncons::json temp;

  temp.insert_or_assign("area", area);
  temp.insert_or_assign("id", ID);
  temp.insert_or_assign("category", category);
  temp.insert_or_assign("location", location);

  jsoncons::json stockMap;
  for (auto st : stock)
  {
    stockMap.insert_or_assign(st.first, st.second);
  }
  temp.insert_or_assign("stock", stockMap);
  return temp;
}
