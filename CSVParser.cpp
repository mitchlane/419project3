#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string>
#include <vector>
#include "minicsv.h"
#include <iostream>
using namespace std;
using namespace csv;

typedef struct airport
{
  vector<int> aid;
  vector<std::string> name;
  vector<std::string> city;
//  std::vector<std::string> country;
  vector<std::string> code;
  vector<double> lat;
  vector<double> lon;
}airport;

typedef struct route{
//  std::vector<std::string> code;
  vector<int> id;
  vector<int> sourceID;
  vector<int> destID;
  
}route;

int main(int argc, char *argv[])
{
  airport ap = {vector<int>(10000), vector<string>(10000),
                vector<string>(10000), vector<string>(10000),
                vector<double>(10000), vector<double>(10000)};

  int count = 0;
  csv::ifstream is("airports.dat", std::ios_base::in);
  is.set_delimiter(',');
  int tempID;
  string tempName, tempCity, tempCode, tempBlank;
  double tempLat, tempLong, tempBlankDouble;
  
  if(is.to_open())
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
