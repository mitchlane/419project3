#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string>
#include <vector>
#include <iostream>
#include "minicsv.h"
#include "ParseAndWrite.hpp"
#include "TreePruner.hpp"
#include "Route.h"
#include "Airport.h"
#include "City.hpp"
using namespace std;
using namespace csv;

int main(int argc, char *argv[])
{
  string startCity = "\"city1\"\"country1\"";
  ParseAndWrite paw("testRoutes.dat", "testAirports.dat");
  unordered_map<string, City> sc;
  unordered_multimap<int, int> r;
  Airport ap;
  
  paw.parse(sc, &ap);
  paw.printCityMap(sc);
//  paw.printAirports(&ap);


  TreePruner tp(sc);
  cout << startCity << endl;
  tp.pruneGraph(startCity);
  
  return 0;
}
