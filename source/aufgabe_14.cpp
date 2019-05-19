#define CATCH_CONFIG_RUNNER
#include "circle.hpp"

#include "catch.hpp"
#include <vector>
#include <algorithm>


std::vector<Circle> copied_circles;  
auto is_minimum_radius =  [] (Circle c) -> bool {
  return c.get_radius() > 4.0f;
};

TEST_CASE ("copy circles ", "[circles]")
{
  REQUIRE(std::all_of(copied_circles.begin(), copied_circles.end(), is_minimum_radius));

}

int main(int argc, char* argv[]) {

  Circle c_1{{200.f, 200.f}, 5.f, {1.f,0.f,0.0f}, {1.f,1.f,1.f}, "Rafael"};
  Circle c_2{{200.f, 600.f}, 3.f, {0.f,0.5f,0.8f}, {1.f,1.f,1.f}, "Leonardo"};
  Circle c_3{{600.f, 200.f}, 8.f, {0.2f,0.f,0.6f}, {1.f,1.f,1.f}, "Donatello"};
  Circle c_4{{600.f, 600.f}, 1.f, {1.f,0.6f,0.f}, {1.f,1.f,1.f}, "Michellangelo"};
  Circle c_5{{400.f, 400.f}, 5.f, {0.8f,0.6f,0.2f}, {1.f,1.f,1.f}, "Splinter"};
  std::vector<Circle> circles{c_1, c_2, c_3, c_4, c_5};

  std::copy_if(circles.begin(), circles.end(), std::back_inserter(copied_circles), is_minimum_radius);


  return Catch::Session().run(argc, argv);

}
