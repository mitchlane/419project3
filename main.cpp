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
using namespace std;
using namespace csv;

int main(int argc, char *argv[])
{
  ParseAndWrite paw;
  unordered_multimap<int, int> r;
  Airport ap;

  paw.parse(r, &ap);
  paw.printRoutes(r);

  
  return 0;
}
