#include "TreePruner.hpp"

TreePruner::TreePruner(unordered_map<string, City>& sc, string start)
{
  this->sc = sc;
  this->start = start;
  count = 0;
}

void TreePruner::prune()
{
  dfs(start);

/*
  removeUnvisited();
  
  sc.at(start).path = true;
  for(auto it = sc.begin(); it != sc.end(); ++it)
  {
    if(isPathToSLO(it->first))
    {
      setPathTrue();
    }
  }
*/
}

void TreePruner::dfs(string startCity)
{
  ++count;
  City* cur = &sc.at(startCity);
  (*cur).visited = true;
  
  for(auto const& dest : (*cur).dests)
  {
    if(sc.count(dest))
    {
      City next = sc.at(dest);
      if(!next.visited)
      {
	dfs(dest);
      }
    }
    else
    {
      vector<string>::iterator remove = find((*cur).dests.begin(), (*cur).dests.end(), dest);
      (*cur).dests.erase(remove);
    }
  }
}

void TreePruner::removeUnvisited()
{
  vector<string> rem;

  for(auto it = sc.begin(); it != sc.end(); ++it)
  {
    if(!it->second.visited)
    {
      rem.push_back(it->first);
    }
  }
  
  for(auto& it : rem)
  {
    sc.erase(it);
  }
}

void TreePruner::print()
{
  for(auto const& kv : sc)
  {
    if(kv.second.path)
    {
      cout << "City " << kv.second.name << " is part of the path" << endl;
    }
  }
  cout << sc.size() << endl;
}

bool TreePruner::isPathToSLO(string from)
{
  City* at = &sc.at(from);
  
  // base case
  // this handles both 'at' SLO, and cases where there has been
  // a path found from this city to SLO before.
  if((*at).path)
  {
    return true;
  }
  
  // set 'visited' values for all cities to false
  resetVisited();
  vector<string> queue;
  
  (*at).visited = true;
  queue.push_back(from);
  
  vector<string>::iterator it;
  
  while(!queue.empty())
  {
    from = queue.front();
    City* qc = &sc.at(from);
    queue.erase(queue.begin());
    
    for(it = (*qc).dests.begin(); it != (*qc).dests.end(); ++it)
    {
      City* dc = &sc.at(*it);
      if((*dc).path)
      {
        return true;
      }
      
      if(!(*dc).visited)
      {
        (*dc).visited = true;
        queue.push_back((*dc).name + (*dc).country);
      }
    }
  }
  
  return false;
}

void TreePruner::resetVisited()
{
  for(auto it = sc.begin(); it != sc.end(); ++it)
  {
    it->second.visited = false;
  }
}

void TreePruner::setPathTrue()
{
  for(auto it = sc.begin(); it != sc.end(); ++it)
  {
    if(it->second.visited == true)
    {
      it->second.path = true;
    }
  }
}
