#ifndef AIRPORT_H
#define AIRPORT_H
#include <vector>
#include <string>

using namespace std;
struct Airport
{
  vector<int> aid;
  vector<std::string> name;
  vector<std::string> city;
  vector<std::string> code;
  vector<double> lat;
  vector<double> lon;
};
#endif
