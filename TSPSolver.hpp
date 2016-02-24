#include <vector>
#include <stack>
#include <cmath>
#include <float.h>
#include <iostream>
#include <algorithm>
#include "City.hpp"
#include <unordered_map>

using namespace std;
class TSPSolver
{
  public:
    TSPSolver(unordered_map<string, City>& sc, string start);
    void solve(string curr);
  
  private:
    double totalDist;
    unordered_map<string, City> sc;
    string start;
    vector<double> distsToDests(City curCity);

};
