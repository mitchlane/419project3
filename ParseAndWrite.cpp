#include "ParseAndWrite.hpp"

ParseAndWrite::ParseAndWrite()
{

}

void ParseAndWrite::parse(std::unordered_multimap<int, int>& r, Airport* ap)
{
  string routeFile = "testRoutes.dat";
  string airportFile = "testAirports.dat";
  
  csv::ifstream routeIS(routeFile.c_str());
  routeIS.set_delimiter(',', "$$");
  csv::ifstream airportIS(airportFile.c_str());
  airportIS.set_delimiter(',', "$$");
  
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
      
      (*ap).aid.push_back(tempID);
      (*ap).name.push_back(tempName);
      (*ap).city.push_back(tempCity);
      (*ap).code.push_back(tempCode);
      (*ap).lat.push_back(tempLat);
      (*ap).lon.push_back(tempLon);
      
    }
  }

  printf("%d airports\n", (*ap).aid.size());
  
  // Checks that the routes file opened
  if(routeIS.is_open())
  {
    string tempID;
    int tempSource, tempDest;
    string tempBogus;
    
    // Read lines from the file while there are more
    while(routeIS.read_line())
    {
      routeIS >> tempBogus >> tempID >> tempBogus >> tempSource
              >> tempBogus >> tempDest;
      // insert the data into the routes hashmap
      r.insert({tempSource, tempDest});
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

}

void ParseAndWrite::write(Result* res)
{

}

void ParseAndWrite::printRoutes(std::unordered_multimap<int, int>& r)
{
  cout << endl << "---list of routes---" << endl;
  cout << "From" << '\t' << "To" << endl;
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
  cout << "--------------" << endl;
}

void ParseAndWrite::printAirports(Airport* a)
{
  cout << endl << "---list of airport ids---" << endl;
  for(auto const& airport : (*a).aid)
  {
    cout << airport << endl;
  }
  cout << "--------------" << endl;
}
