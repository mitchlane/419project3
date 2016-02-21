#include <vector>
#include <iostream>
#include <unordered_map>
#include "City.hpp"

using namespace std;
class TreePruner
{
  public:
    TreePruner(unordered_map<string, City>& sc);
    void pruneGraph(string start);
    void removeDeadEnds();
  private:
    unordered_map<string, City> sc;
    unsigned int count;
};
