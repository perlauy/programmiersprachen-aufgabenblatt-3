#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>

template<class Container, class UnaryPredicate >
Container filter(Container cont, UnaryPredicate f) {
  cont.erase(std::remove_if(cont.begin(), cont.end(),
	  [f](auto el) {return !f(el); }),
    cont.end() );
  return cont;
} 

bool is_even(int n) {
  return n % 2 == 0;
}

TEST_CASE (" filter alle vielfache von drei ", "[ erase ]")
{
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  std::vector<int> all_even = filter(v, is_even);

  REQUIRE(std::all_of(all_even.begin(), all_even.end(), is_even));
}

int main (int argc , char * argv [])
{
  return Catch::Session().run(argc, argv);
}
