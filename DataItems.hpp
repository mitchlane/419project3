#include <vector>
#include <string>

using namespace std;
typedef struct airport
{
  vector<int> aid;
  vector<std::string> name;
  vector<std::string> city;
  vector<std::string> code;
  vector<double> lat;
  vector<double> lon;
}airport;

typedef struct route{
  vector<int> id;
  vector<int> sourceID;
  vector<int> destID;

}route;

typedef struct result{
  vector<string> city;
  vector<string> code;
  vector<double> trip;
  vector<double> total;
}result;

