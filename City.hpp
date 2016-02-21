#ifndef CITY_HPP
#define CITY_HPP
#include <vector>
#include<string>

using namespace std;
class City
{
  public:
  City(string name, string country, double lat, double lon);
  bool equals(City c);
  
  string name;
  string country;
  double lat;
  double lon;
  vector<string> dests;
  bool visited;
  
  private:
  
};
#endif
