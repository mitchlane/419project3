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
    ParseAndWrite(string rf, string af);
    void parse(std::unordered_map<string, City>& r, Airport* ap);
    void write(Result* res);
    void printCityMap(std::unordered_map<string, City>& r);
    void printAirports(Airport* a);
    void createBackRoute(std::unordered_map<string, City>& sc);
  
  private:
    City createCity(int index, Airport* ap);
    string routeFile;
    string airportFile;
};
