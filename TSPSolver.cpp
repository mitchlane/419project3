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
  unsigned int cityNum = sc.size() - 1;
  int smallestIndex;
  cout << cityNum << endl;
  
  while(cityNum > 0)
  {
    closest = DBL_MAX;
    unordered_map<string, double> destsDists = distsToDests(*curCity);

/*
    for(int i = 0; i < destsDists.size(); ++i)
    {
      cout << destsDists[i] << endl;
      if(destsDists[i] < closest)
      {
        closest = destsDists[i];
        smallestIndex = i;
      }
    }
*/    
    if(!destsDists.empty())
    {
      for(auto it = destsDists.begin(); it != destsDists.end(); ++it)
      {
        if(it->second < closest)
        {
          closest = it->second;
          closestCity = it->first;
        }
      }
      cout << "choosing city " << closestCity << " with distance " << closest << endl;
     sc.at(closestCity).visited = true;
     currentDist += closest;
     curCity = &sc.at(closestCity);

     --cityNum; 
    }
    else
    {
      cout << "all cities are visites. " << "need to go back a city." << endl;
      curCity = &sc.at(cityStack.top());
      cityStack.pop();
    }
    
  }
}

unordered_map<string, double> TSPSolver::distsToDests(City curCity)
{
  unordered_map<string, double> dtd;
//  for(auto const& dest : curCity->dests)
  for(int i = 0; i < curCity.dests.size(); ++i)
  {
    City* dCity = &sc.at(curCity.dests[i]);
    if(!dCity->visited)
    {
      double deltaLat = dCity->lat - curCity.lat;
      double deltaLon = dCity->lon - curCity.lon;
      double a = (sin(deltaLat / 2) * sin(deltaLat / 2)) + cos(curCity.lat)
		 * cos(dCity->lat) * (sin(deltaLon / 2) * sin(deltaLon / 2));
      double c = 2 * atan2(sqrt(a), sqrt(1 - a));
      double d = 6371 * c;
    dtd.insert({dCity->name + dCity->country, d});
    }
  }
  
  return dtd;
}
