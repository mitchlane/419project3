#include <vector>
#include <iostream>
#include <unordered_map>
#include "City.hpp"

using namespace std;
class TreePruner
{
  public:
    TreePruner(unordered_map<string, City>& sc);
    void dfs(string start);
    void removeUnvisited();
    void removeDeadEnds();
    void print();
  private:
    unordered_map<string, City> sc;
    unsigned int count;
};
