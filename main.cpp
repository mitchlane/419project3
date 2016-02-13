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
  Route r;
  Airport ap;
/*
  airport ap = {vector<int>(10000), vector<string>(10000),
                vector<string>(10000), vector<string>(10000),
                vector<double>(10000), vector<double>(10000)};
*/
  paw.parse(&r, &ap);

  
  return 0;
}
