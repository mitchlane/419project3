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

  paw.parse(&r, &ap);

  
  return 0;
}
