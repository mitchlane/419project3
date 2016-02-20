#include <iostream>
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
    void parse(std::unordered_multimap<int, int>& r, Airport* ap);
    void write(Result* res);
    void printRoutes(std::unordered_multimap<int, int>& r);
    void printAirports(Airport* a);
  
  private:
};
