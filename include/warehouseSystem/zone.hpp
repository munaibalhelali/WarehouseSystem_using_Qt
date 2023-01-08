#ifndef ZONE_
#define ZONE_
#include <string>
#include <map>
#include <iostream>
#include <jsoncons/json.hpp>
using namespace std;

class Zone
{
private:
  string ID;
  string area;
  string category;
  string location;
  map<string, int> stock;

public:
  Zone();
  Zone(string id_, string area_, string category_, string location_, map<string, int> stock_);
  void setArea(string area_);
  void setID(string id_);
  void setCategory(string category_);
  void setLocation(string location_);
  void setStock(map<string, int> stock_);

   string getID();
   string getArea();
   string getCategory();
   string getLocation();
   map<string, int> getStock();
   void addStock(string productID, int quantity);
   void dispatchStock(string productID, int quantity);
   jsoncons::json toJson();

};

#endif // ZONE_
