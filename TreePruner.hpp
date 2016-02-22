#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include "City.hpp"

using namespace std;
class TreePruner
{
  public:
    TreePruner(unordered_map<string, City>& sc, string start);
    void prune();
    void dfs(string startCity);
    void removeUnvisited();
    bool isPathToSLO(string from);
    void print();
  private:
    void resetVisited();
    void setPathTrue();
    unordered_map<string, City> sc;
    unsigned int count;
    string start;
};
