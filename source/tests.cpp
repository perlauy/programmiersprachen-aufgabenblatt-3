#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

TEST_CASE (" describe_gcd ", "[gcd]")
{
  REQUIRE (1.f == 1);
}

int main (int argc , char * argv [])
{
  return Catch::Session().run(argc, argv);
}