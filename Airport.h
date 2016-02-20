#ifndef AIRPORT_H
#define AIRPORT_H
#include <vector>
#include <string>

#define APNUM 10000

using namespace std;
class Airport
{
  public:
  vector<std::string> city;
  vector<std::string> country;
  vector<double> lat;
  vector<double> lon;
  
    Airport() : city(APNUM), country(APNUM), lat(APNUM), lon(APNUM) {}
};
#endif
