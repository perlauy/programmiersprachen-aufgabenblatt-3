#include "circle.hpp"
#include "rect.hpp"
#include "window.hpp"

#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <set>
#include <vector>
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
  std::cout << "Schreiben Sie den Namen eines der folgenden Kreise: " << std::endl;
  std::cout << "Leonardo, Donatello, Rafael oder Michellangelo " << std::endl;
  std::string picked_circle;
  std::cin >> picked_circle;

  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

//    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
    auto mouse_position = win.mouse_position();

    auto t = win.get_time();

    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    //win.draw_text(text_offset_x, text_offset_y, font_size, "display_text");

    Circle c_1{{200.f, 200.f}, 75.f, {1.f,0.f,0.0f}, {1.f,1.f,1.f}, "Rafael"};
    Circle c_2{{200.f, 600.f}, 70.f, {0.f,0.5f,0.8f}, {1.f,1.f,1.f}, "Leonardo"};
    Circle c_3{{600.f, 200.f}, 65.f, {0.2f,0.f,0.6f}, {1.f,1.f,1.f}, "Donatello"};
    Circle c_4{{600.f, 600.f}, 80.f, {1.f,0.6f,0.f}, {1.f,1.f,1.f}, "Michellangelo"};
    std::set<Circle> set_circles{c_1, c_2, c_3, c_4};

    auto draw_circle = [&win, &picked_circle] (Circle const& c) {
      bool highlight = c.get_name() == picked_circle;
      c.draw(win, 36, 2.f, highlight);
    };
    std::for_each(set_circles.begin(), set_circles.end(), draw_circle);

    if (t >= 10 && picked_circle != "") picked_circle = "";

    win.update();
  }

  return 0;
}
