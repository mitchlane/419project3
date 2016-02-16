#include "ParseAndWrite.hpp"

ParseAndWrite::ParseAndWrite()
{

}

void ParseAndWrite::parse(std::unordered_multimap<int, int>& r, Airport* ap)
{
  int count = 0;
  bool validAirports[10000] = {0};
  string routeFile = "testRoutes.dat";
  string airportFile = "testAirports.dat";
  
  csv::ifstream routeIS(routeFile.c_str());
  routeIS.set_delimiter(',', "$$");
  csv::ifstream airportIS(airportFile.c_str());
  airportIS.set_delimiter(',', "$$");
  
  
  // Checks that the routes file opened
  if(routeIS.is_open())
  {
    string tempID;
    int tempSource, tempDest;
    string tempBogus;
    
    // Read lines from the file while there are more
    while(routeIS.read_line())
    {
      routeIS >> tempBogus >> tempID >> tempBogus >> tempSource >> tempBogus >> tempDest;
      // insert the data into the routes hashmap
      r.insert({tempSource, tempDest});
      validAirports[tempSource] = true;
      validAirports[tempDest] = true;
    }
  }

  printf("%d keys\n", r.size());
  printf("%d buckets\n", r.bucket_count());
  int countT = 0;
    auto it = r.begin();
    while(it != r.end())
    {
      int ao = it->first;
      ++countT;
      it=r.equal_range(ao).second;
    }
  printf("%d count\n", countT);
  
  // Check that the airports file opened
  if(airportIS.is_open())
  {
    int tempID;
    string tempName, tempCity, tempCode, tempBlank;
    double tempLat, tempLon, tempBlankDouble;
    
    // Read lines while there are more
    while(airportIS.read_line())
    {
      airportIS >> tempID >> tempName >> tempCity >> tempBlank >> tempCode
                >> tempBlank >> tempLat >> tempLon;
      
      // Add the airport if it exists in the routes
      if(validAirports[tempID])
      {
        (*ap).aid.push_back(tempID);
        (*ap).name.push_back(tempName);
        (*ap).city.push_back(tempCity);
        (*ap).code.push_back(tempCode);
        (*ap).lat.push_back(tempLat);
        (*ap).lon.push_back(tempLon);
      }
    }
  }
  printf("%d airports\n", (*ap).aid.size());

}

void ParseAndWrite::write(Result* res)
{

}

void ParseAndWrite::printRoutes(std::unordered_multimap<int, int>& r)
{
    auto it = r.begin();
    while(it != r.end())
    {
      int s = it->first;
      if(r.count(s))
      {
        auto range = r.equal_range(s);
        cout << it->first << '\t';
        
        for(auto it = range.first; it != range.second; ++it)
        {
          cout << it->second << ", ";
        }
        printf("\n");
      }
      it=r.equal_range(s).second;
    }
}

/*
      routeIS >> tempID >> tempName >> tempCity >> tempBlank >> tempCode
         >> tempBlank >> tempLat >> tempLon >> tempBlankDouble >> tempBlankDouble;
*/
