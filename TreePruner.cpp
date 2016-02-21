#include "TreePruner.hpp"

TreePruner::TreePruner(unordered_map<string, City>& sc)
{
  this->sc = sc;
  count = 0;
}

void TreePruner::pruneGraph(string start)
{
  ++count;
  City* cur = &sc.at(start);
  (*cur).visited = true;
  cout << "Visited " << start.c_str() << endl;
  
  for(auto const& dest : (*cur).dests)
  {
    City next = sc.at(dest);
    if(!next.visited)
    {
      pruneGraph(dest);
    }
  }
}

void TreePruner::removeDeadEnds()
{

}
