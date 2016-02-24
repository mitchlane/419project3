#include "TSPSolver.hpp"

TSPSolver::TSPSolver(unordered_map<string, City>& sc, string start)
{
  totalDist = 0;
  this->sc = sc;
  this->start = start;
  solve(start);
  checkAllVisited();
}

/*
 * I apologize that this looks so nasty. I had to make some last minuit, frantic, design decisionsc
 *
*/
Result TSPSolver::solve(string cur)
{
  City* curCity = &sc.at(cur);
  curCity->visited = true;
  double closest = DBL_MAX;
  double currentDist = 0;
  stack<string> cityStack;
  cityStack.push(cur);
  string closestCity;
  unsigned int cityNum = sc.size() - 1;
  int smallestIndex;
  cout << cityNum << endl;

  result.city.push_back(cur);
  result.trip.push_back(currentDist);
  result.total.push_back(currentDist);
  
  while(cityNum)
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
      sc.at(closestCity).visited = true;
      currentDist += closest;
      curCity = &sc.at(closestCity);
      cityStack.push(curCity->name + curCity->country);
      result.city.push_back(closestCity);
      result.trip.push_back(closest);
      result.total.push_back(currentDist);

      --cityNum; 
    }
    else
    {
      if(cityStack.size() == 0)
      {
        string curCityString = findUnvisited();
        curCity = &sc.at(curCityString);
        cityStack.push(curCityString);
        curCity->visited = true;
        --cityNum;
      }
      City* to = &sc.at(cityStack.top());
      double backDistance = distance(*curCity, *to);
      currentDist += backDistance;
      curCity = to;
      cityStack.pop();
      result.city.push_back(to->name + to->country);
      result.trip.push_back(backDistance);
      result.total.push_back(currentDist);
    }
  }
  
  if(start != (curCity->name + curCity->country))
  {
    double distant = distance(*curCity, sc.at(start));
    result.city.push_back(start);
    result.trip.push_back(distant);
    result.total.push_back(currentDist + distant);
  }
  
  return result;
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
  for(int i = 0; i < curCity.dests.size(); ++i)
  {
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

string TSPSolver::findUnvisited()
{
  for(auto const& it : sc)
  {
    if(!it.second.visited)
    {
      return it.first;
    }

  }
  return NULL;
}
