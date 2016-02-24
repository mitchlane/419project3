#include "TSPSolver.hpp"

TSPSolver::TSPSolver(unordered_map<string, City>& sc, string start)
{
  totalDist = 0;
  this->sc = sc;
  this->start = start;
  solve(start);
  checkAllVisited();
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
     cityStack.push(curCity->name + curCity->country);

     --cityNum; 
    }
    else
    {
      City* to = &sc.at(cityStack.top());
      currentDist += distance(*curCity, *to);
      curCity = to;
      cityStack.pop();
      cout << "going back to city " << to->name << endl;
    }
    
  }
}

double TSPSolver::distance(City from, City to)
{
  double deltaLat = to.lat - from.lat;
  double deltaLon = to.lon - from.lon;
  double a = (sin(deltaLat / 2) * sin(deltaLat / 2)) + cos(to.lat)
	     * cos(from.lat) * (sin(deltaLon / 2) * sin(deltaLon / 2));
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  return 6371 * c;
}

unordered_map<string, double> TSPSolver::distsToDests(City curCity)
{
  unordered_map<string, double> dtd;
//  for(auto const& dest : curCity->dests)
  for(int i = 0; i < curCity.dests.size(); ++i)
  {
    cout << "looking for " << curCity.dests[i] << endl;
    City dCity = sc.at(curCity.dests[i]);
    if(!dCity.visited)
    { 
      double dist = distance(curCity, dCity);
      dtd.insert({dCity.name + dCity.country, dist});
    }
  }
  
  return dtd;
}

void TSPSolver::checkAllVisited()
{
  for(auto const& it : sc)
  {
    if(!it.second.visited)
    {
      cout << "City " << it.first << " didn't get visited!!!!" << endl;
    }
  }
}
