#include "ParseAndWrite.hpp"

ParseAndWrite::ParseAndWrite()
{

}

void ParseAndWrite::parse(Route* r, Airport* ap)
{
  int count = 0;
  csv::ifstream routeIS("routes.dat");
  routeIS.set_delimiter(',', "$$");
  csv::ifstream airportIS("airports.dat");
  airportIS.set_delimiter(',', "$$");
  
  
  if(routeIS.is_open())
  {
    string tempID;
    int tempSource, tempDest;
    string tempBogus;
    
    routeIS >> tempBogus >> tempID >> tempBogus >> tempSource >> tempBogus >> tempDest;
    
    while(routeIS.read_line())
    {
      
      (*r).id.push_back(tempID);
      printf("%d\n", tempID);
    }
  }
  
  if(airportIS.is_open())
  {
    int tempID;
    string tempName, tempCity, tempCode, tempBlank;
    double tempLat, tempLon, tempBlankDouble;
    
    while(airportIS.read_line())
    {
      (*ap).aid.push_back(tempID);
    }
  }

}

void ParseAndWrite::write(Result* res)
{

}

/*
      routeIS >> tempID >> tempName >> tempCity >> tempBlank >> tempCode
         >> tempBlank >> tempLat >> tempLon >> tempBlankDouble >> tempBlankDouble;
*/
