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
#include "TSPSolver.hpp"

using namespace std;
using namespace csv;

int main(int argc, char *argv[])
{
  string startCityTest = "\"city1\"\"country1\"";
  string startCity = "\"San Luis Obispo\"\"United States\"";
  ParseAndWrite paw("testRoutes.dat", "testAirports.dat");
  unordered_map<string, City> sc;
  unordered_multimap<int, int> r;
  Airport ap;
  
  paw.parse(sc, &ap);
//  paw.printAirports(&ap);


  TreePruner tp(sc, startCityTest);
  tp.prune();
  tp.print();
  paw.createBackRoute(sc);
  paw.printCityMap(sc);
  
  TSPSolver tsp(sc, startCityTest);
  
  return 0;
}
