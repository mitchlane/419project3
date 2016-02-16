#include <iostream>
#include <unordered_map>
#include "minicsv.h"
#include "Route.h"
#include "Airport.h"
#include "Result.h"

class ParseAndWrite
{
  public:
    ParseAndWrite();
    void parse(const std::unordered_map<int, int>& r, Airport* ap);
    void write(Result* res);
  
  private:
};
