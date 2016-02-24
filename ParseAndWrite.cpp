#include "ParseAndWrite.hpp"

ParseAndWrite::ParseAndWrite(string routeFile, string airportFile)
{
  this->routeFile = routeFile;
  this->airportFile = airportFile;
}

void ParseAndWrite::parse(std::unordered_map<string, City>& sc, Airport* ap)
{
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
      airportIS >> tempID >> tempBlank >> tempCity;
      if(tempCity[0] == '"' && tempCity[tempCity.size() -1] != '"')
      {
        string next;
        airportIS >> next;
        tempCity += next;
      }
      
      airportIS >> tempCountry >> tempBlank
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

      string cc = (*ap).city.at(tempSource) + (*ap).country.at(tempSource);
      string dcc = (*ap).city.at(tempDest) + (*ap).country.at(tempDest);
      
      unordered_map<string, City>::const_iterator got = sc.find(cc);
      
      if(got == sc.end())
      {
	// Create the source city
        City source = createCity(tempSource, ap);
	
        // Adds the new city to the map
	source.dests.push_back(dcc);
	
        // Insert the new name and source
        sc.insert({source.name + source.country, source});

/*
        if(sc.count(dcc))
        {
          City* temp = &sc.at(dcc);
          
          if(find(temp->dests.begin(), temp->dests.end(), cc) == temp->dests.end())
          {
	    sc.at(dcc).dests.push_back(cc);
          }
        }
        else
        {
          City newDest = createCity(tempDest, ap);
          cout << "adding new dest: " << newDest.name + newDest.country << endl;
          newDest.dests.push_back(cc);
          sc.insert({newDest.name + newDest.country, newDest});
        }
*/
      }
      else
      {
        vector<string> sDests = sc.at(cc).dests;
        
        if(find(sDests.begin(), sDests.end(), dcc) == sDests.end())
        {
          string dest = (*ap).city[tempDest] + (*ap).country[tempDest];
          
          // Get the airport at cc in the map and add a destination to it.
	  sc.at(cc).dests.push_back(dest);
        }
      }
      
      got = sc.find(dcc);
      
      if(got == sc.end())
      {
        City dest = createCity(tempDest, ap);
        dest.dests.push_back(cc);
        sc.insert({dest.name + dest.country, dest});
      }
      else
      {
        vector<string> cDests = sc.at(dcc).dests;
        if(find(cDests.begin(), cDests.end(), cc) == cDests.end())
        {
          string dest = ap->city[tempSource] + ap->country[tempSource];
        }
      }
    }
  }
  
  //printf("%d keys\n", sc.size());
 // printf("%d buckets\n", sc.bucket_count());
/*  int countT = 0;
    auto it = sc.begin();
    while(it != sc.end())
    {
      auto ao = it->first;
      ++countT;
      it=sc.equal_range(ao).second;
    }*/
  //printf("%d count\n", countT);
}

City ParseAndWrite::createCity(int index, Airport* ap)
{
  string name = (*ap).city[index];
  string country = (*ap).country[index];
  double lat = (*ap).lat[index];
  double lon = (*ap).lon[index];
  return City(name, country, lat, lon);
}

void ParseAndWrite::write(Result* res)
{
  
}

void ParseAndWrite::createBackRoute(unordered_map<string, City>& sc)
{
 // auto it = sc.begin();
 // while(it != sc.end())
  for(auto it = sc.begin(); it != sc.end(); ++it)
  {
    City* city = &sc.at(it->first);
    vector<string>* dests = &city->dests;
    for(auto dit = dests->begin(); dit != dests->end(); ++dit)
    {
      if(sc.count(*dit))
     {
	City* dCity = &sc.at(*dit);
	vector<string>* dDests = &dCity->dests;
	if(find(dDests->begin(), dDests->end(), it->first) == dDests->end())
	{
	  dDests->push_back(it->first);
	  //cout << "pushing " << *dit << " into " << city->name << "'s dests" << endl;
	}
      }
    }
  }
}

// A debug tool for printing out the results of the routes file
void ParseAndWrite::printCityMap(std::unordered_map<string, City>& r)
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
        for(auto const& dest : it->second.dests)
        {
          cout << dest.c_str() << ", ";
        }
        printf("\n");
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
  for(auto const& city : (*a).city)
  {
    cout << city.c_str() << endl;
  }
  cout << "--------------" << endl;
}
