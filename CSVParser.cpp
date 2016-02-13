#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <string>
#include <vector>
#include "csv.h"
using namespace std;
using namespace io;

/**
 * CSV Reader functions
template<
  unsigned column_count,
  class trim_policy = trim_chars<' ', '\t'>, 
  class quote_policy = no_quote_escape<','>,
  class overflow_policy = throw_on_overflow,
  class comment_policy = no_comment
>
class CSVReader{
public:
  // Constructors
  // same as for LineReader

  // Parsing Header
  void read_header(ignore_column ignore_policy, some_string_type col_name1, some_string_type col_name2, ...);
  void set_header(some_string_type col_name1, some_string_type col_name2, ...);
  bool has_column(some_string_type col_name)const;

  // Read
  bool read_row(ColType1&col1, ColType2&col2, ...);

  // File Location 
  void set_file_line(unsigned);
  unsigned get_file_line(unsigned)const;
  void set_file_name(some_string_type file_name);
  const char*get_truncated_file_name()const;
};

*/

typedef struct airport
{
  vector<int> aid;
  vector<std::string> name;
  vector<std::string> city;
//  std::vector<std::string> country;
  vector<std::string> code;
  vector<double> lat;
  vector<double> lon;
}airport;

typedef struct route{
//  std::vector<std::string> code;
  vector<int> id;
  vector<int> sourceID;
  vector<int> destID;
  
}route;

int main(int argc, char *argv[])
{
  airport ap = {vector<int>(10000), vector<string>(10000),
                vector<string>(10000), vector<string>(10000),
                vector<double>(10000), vector<double>(10000)};
  string bogus;

  CSVReader<12> in("airports.csv");
  in.set_header("aid", "name", "city", "country", "code", "icao", "lat", "lon", "alt", "timeZone", "dst","tz");

  // Forcing me to read in every column...
 // in.read_header(ignore_extra_column, "aid", "name", "city", "country","code", "icao","lat", "lon", "alt", "timeZone", "dst","tz");

  int count = 0;
  printf("here\n");
  while(in.read_row(ap.aid[count], ap.name[count], ap.city[count], bogus, ap.code[count], bogus, ap.lat[count], ap.lon[count], bogus, bogus, bogus, bogus))
  {
    cout << ap.name[count] << endl;
    ++count;
  }
  
  for(int i : ap.aid)
  {
    cout << "aid = " << i << endl;
  } 
  
  return 0;
}
