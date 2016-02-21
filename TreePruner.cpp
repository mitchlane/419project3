#include "TreePruner.hpp"

TreePruner::TreePruner(unordered_map<string, City>& sc)
{
  this->sc = sc;
  count = 0;
}

void TreePruner::dfs(string start)
{
  ++count;
  City* cur = &sc.at(start);
  (*cur).visited = true;
  cout << "Visiting " << start.c_str() << endl;
  
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
  }
}

void TreePruner::removeUnvisited()
{
  cout << sc.size() << endl;
  for(auto it = sc.begin(); it != sc.end(); ++it)
  {
    if(!it->second.visited)
    {
      cout << it->first.c_str() << endl;
      sc.erase(it->first);
    }
  }
  cout << sc.size() << endl;
}

void TreePruner::removeDeadEnds()
{

}

void TreePruner::print()
{
  cout << count << endl;
}
