#include "City.hpp"

City::City(string name, string country, double lat, double lon)
{
  this->name = name;
  this->country = country;
  this->lat = lat;
  this->lon = lon;
}

bool City::equals(City c)
{
  return (name.compare(c.name) == 0) && (country.compare(c.country) == 0);
}
