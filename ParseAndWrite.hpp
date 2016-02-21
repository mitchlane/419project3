#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "minicsv.h"
#include "Route.h"
#include "Airport.h"
#include "Result.h"
#include "City.hpp"

class ParseAndWrite
{
  public:
    ParseAndWrite();
    void parse(std::unordered_map<string, City>& r, Airport* ap);
    void write(Result* res);
    void printCityMap(std::unordered_map<string, City>& r);
    void printAirports(Airport* a);
  
  private:
    City createCity(int index, Airport* ap);
};
