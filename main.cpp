#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string>
#include <vector>
#include <iostream>
#include "minicsv.h"
#include "DataItems.hpp"
using namespace std;
using namespace csv;

int main(int argc, char *argv[])
{
  route r;
  
  airport ap = {vector<int>(10000), vector<string>(10000),
                vector<string>(10000), vector<string>(10000),
                vector<double>(10000), vector<double>(10000)};

  int count = 0;
  csv::ifstream is("airports.dat");
  is.set_delimiter(',', "$$");
  int tempID;
  string tempName, tempCity, tempCode, tempBlank;
  double tempLat, tempLon, tempBlankDouble;
  
  if(is.is_open())
  {
    while(is.read_line())
    {
      is >> tempID >> tempName >> tempCity >> tempBlank >> tempCode
         >> tempBlank >> tempLat >> tempLon >> tempBlankDouble >> tempBlankDouble;
      printf("%d\n", tempID);
    }
  }
  
  
  return 0;
}
