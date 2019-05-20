#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>


bool is_10(unsigned int num) {
  return num == 10;
}

TEST_CASE (" all sums are 10 ", "[ sum ]")
{

  std::vector<int> v_1{1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
  std::vector<int> v_2{9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1};
  std::vector<int> v_3(9);

  for (int i = 0; i < v_3.size(); ++i) {
    v_3[i] = v_1.at(i) + v_2.at(i);
  }
  std::transform(v_1.begin(), v_1.end(), v_2.begin(), std::back_inserter(v_3), [](int a, int b) -> int { return a + b; });

  REQUIRE(std::all_of(v_3.begin(), v_3.end(), is_10));
}

int main (int argc , char * argv [])
{
  return Catch::Session (). run(argc , argv );
}
