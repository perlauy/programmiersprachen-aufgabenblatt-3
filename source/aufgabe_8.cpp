#define CATCH_CONFIG_RUNNER
#include "circle.hpp"

#include "catch.hpp"
#include <vector>
#include <algorithm>


std::vector<Circle> sorted_circles;
struct compare_circles {
  bool operator() (Circle const& lhs, Circle const& rhs) const {
    return lhs.get_radius() < rhs.get_radius();
  }
};


TEST_CASE ("sorted_circles ", "[sorted_circles]")
{
  REQUIRE (std::is_sorted( sorted_circles.begin(), sorted_circles.end() ));
}

int main(int argc, char* argv[]) {

  Circle c_1{{200.f, 200.f}, 75.f, {1.f,0.f,0.0f}, {1.f,1.f,1.f}, "Rafael"};
  Circle c_2{{200.f, 600.f}, 60.f, {0.f,0.5f,0.8f}, {1.f,1.f,1.f}, "Leonardo"};
  Circle c_3{{600.f, 200.f}, 80.f, {0.2f,0.f,0.6f}, {1.f,1.f,1.f}, "Donatello"};
  Circle c_4{{600.f, 600.f}, 45.f, {1.f,0.6f,0.f}, {1.f,1.f,1.f}, "Michellangelo"};
  sorted_circles = std::vector<Circle>{c_1, c_2, c_3, c_4};

  std::sort(sorted_circles.begin(), sorted_circles.end(), compare_circles{});

  return Catch::Session().run(argc, argv);

}
