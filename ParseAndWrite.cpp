#include "ParseAndWrite.hpp"

ParseAndWrite::ParseAndWrite()
{

}

void ParseAndWrite::parse(std::unordered_map<string, City>& sc, Airport* ap)
{
  string routeFile = "testRoutes.dat";
  string airportFile = "testAirports.dat";
  
  csv::ifstream routeIS(routeFile.c_str());
  routeIS.set_delimiter(',', "$$");
  csv::ifstream airportIS(airportFile.c_str());
  airportIS.set_delimiter(',', "$$");
  
  // Check that the airports file opened
  if(airportIS.is_open())
  {
    int tempID;
    string tempCity, tempCountry, tempBlank;
    double tempLat, tempLon, tempBlankDouble;
    
    // Read lines while there are more
    while(airportIS.read_line())
    {
      airportIS >> tempID >> tempBlank >> tempCity >> tempCountry >> tempBlank
                >> tempBlank >> tempLat >> tempLon;
      
      (*ap).city[tempID] = tempCity;
      (*ap).country[tempID] = tempCountry;
      (*ap).lat[tempID] = tempLat;
      (*ap).lon[tempID] = tempLon;
      
    }
  }

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
      //r.insert({tempSource, tempDest});
      string name = (*ap).city[tempSource];
      string country = (*ap).country[tempSource];
      double lat = (*ap).lat[tempSource];
      double lon = (*ap).lon[tempSource];
      sc.insert({name, City(name, country, lat, lon)});
    }
  }
  
  printf("%d keys\n", sc.size());
  printf("%d buckets\n", sc.bucket_count());
  int countT = 0;
    auto it = sc.begin();
    while(it != sc.end())
    {
      auto ao = it->first;
      ++countT;
      it=sc.equal_range(ao).second;
    }
  printf("%d count\n", countT);
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
    auto s = it->first;
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
  for(auto const& airport : (*a).city)
  {
    cout << airport << endl;
  }
  cout << "--------------" << endl;
}
