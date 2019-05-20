# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>
# include <vector>


bool is_multiple_of_3(unsigned int num) {
  return num % 3 == 0;
}

TEST_CASE (" filter alle vielfache von drei ", "[ erase ]")
{

  std::vector<unsigned int> int_vector{};
  for (int i = 0; i < 100; ++i) {
    int_vector.push_back(rand() % 100);
  }
  int_vector.erase(
    std::remove_if(int_vector.begin(), int_vector.end(),
      [](unsigned int num) {return num % 3 != 0;}),
    int_vector.end() );

//  for (auto el : int_vector) {
//     std::cout << el << std::endl;
//  }

  REQUIRE(std::all_of(int_vector.begin(), int_vector.end(), is_multiple_of_3));
}

int main (int argc , char * argv [])
{
  return Catch :: Session (). run(argc , argv );
}
