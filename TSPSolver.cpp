#include "TSPSolver.hpp"

TSPSolver::TSPSolver(unordered_map<string, City>& sc, string start)
{
  totalDist = 0;
  this->sc = sc;
  this->start = start;
  solve(start);
}

void TSPSolver::solve(string cur)
{
  City* curCity = &sc.at(cur);
  curCity->visited = true;
  int citiesVisited = 0;
  double closest = DBL_MAX;
  double currentDist = 0;
  stack<string> cityStack;
  cityStack.push(cur);
  string closestCity;
  unsigned int cityNum = sc.size();
  int smallestIndex;
  cout << cityNum << endl;
  
  while(cityNum > 0)
  {
    closest = DBL_MAX;
    vector<double> destsDists = distsToDests(*curCity);
    for(int i = 0; i < destsDists.size(); ++i)
    {
      cout << destsDists[i] << endl;
      if(destsDists[i] < closest)
      {
        closest = destsDists[i];
        smallestIndex = i;
      }
    }
    
    cout << "choosing city " << curCity->dests[smallestIndex] << " with distance " << closest << endl;
    
   --cityNum; 
  }
}

vector<double> TSPSolver::distsToDests(City curCity)
{
  vector<double> dtd;
//  for(auto const& dest : curCity->dests)
  for(int i = 0; i < curCity.dests.size(); ++i)
  {
    City* dCity = &sc.at(curCity.dests[i]);
    double deltaLat = dCity->lat - curCity.lat;
    double deltaLon = dCity->lon - curCity.lon;
    double a = (sin(deltaLat / 2) * sin(deltaLat / 2)) + cos(curCity.lat)
               * cos(dCity->lat) * (sin(deltaLon / 2) * sin(deltaLon / 2));
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = 6371 * c;
    dtd.push_back(d);
  }
  
  return dtd;
}
