#include <iostream>
#include "minicsv.h"
#include "Route.h"
#include "Airport.h"
#include "Result.h"

class ParseAndWrite
{
  public:
    ParseAndWrite();
    void parse(Route* r, Airport* ap);
    void write(Result* res);
  
  private:
};
