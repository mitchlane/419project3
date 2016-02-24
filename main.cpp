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
#include "Result.h"

using namespace std;
using namespace csv;

int main(int argc, char *argv[])
{
//  string startCityTest = "\"city1\"\"country1\"";
  string startCity = "\"San Luis Obispo\"\"United States\"";
//  ParseAndWrite paw("testRoutes.dat", "testAirports.dat");
  ParseAndWrite paw("routes.dat", "airports.dat");
  unordered_map<string, City> sc;
  Airport ap;
  Result result;
  
  paw.parse(sc, &ap);
//  paw.printAirports(&ap);

  TreePruner tp(sc, startCity);
  sc = tp.prune();
//  tp.print();
  sc = paw.createBackRoute(sc);
//  paw.printCityMap(sc);
  
  TSPSolver tsp(sc, startCity);
  result = tsp.result;
  paw.write(&result);
  if(tp.isPathToSLO(result.city[result.city.size() - 1]))
  {
    cout << "yes" << endl;
  }
  
  return 0;
}
