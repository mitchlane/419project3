#include "ParseAndWrite.hpp"

ParseAndWrite::ParseAndWrite()
{

}

void ParseAndWrite::parse(Route* r, Airport* ap)
{
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

}

void ParseAndWrite::write(Result* res)
{

}
