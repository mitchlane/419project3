#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string>
#include <vector>
#include <iostream>
#include "minicsv.h"
#include "ParseAndWrite.hpp"
#include "Route.h"
#include "Airport.h"
#include "City.hpp"
using namespace std;
using namespace csv;

int main(int argc, char *argv[])
{
  ParseAndWrite paw;
  unordered_map<string, City> sc;
  unordered_multimap<int, int> r;
  Airport ap;
  
  paw.parse(sc, &ap);
  paw.printCityMap(sc);
//  paw.printAirports(&ap);

  
  return 0;
}
