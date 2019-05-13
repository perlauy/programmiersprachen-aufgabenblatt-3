#define _USE_MATH_DEFINES

#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "window.hpp"

#include <cmath>


Circle::Circle() :
  center_{0.f, 0.f},
  radius_{1.f},
  color_{0.5f,0.5f,0.5f},
  highlight_color_{1.f,1.f,0.f}
{}

Circle::Circle(Circle const& c) :
  center_{c.center_},
  radius_{c.radius_},
  color_{c.color_},
  highlight_color_{c.highlight_color_}
{}

Circle::Circle(Vec2 const& center, float radius, Color const& color, Color const& highlight_color) :
  center_{center},
  radius_{radius},
  color_{color},
  highlight_color_{highlight_color}
{}

double Circle::circumference() const {
  return 2 * radius_ * M_PI;
}

void Circle::draw(Window const& window, unsigned int facets, bool highlight) const {

  Mat2 rotation_matrix = make_rotation_mat2(2 * M_PI / facets);
  Vec2 start_point{center_.x + radius_, center_.y};
  Vec2 next_point;
  Color use_color{highlight ? highlight_color_ : color_};

  for(unsigned int i = 0; i < facets; i++) {
    next_point = start_point * rotation_matrix;
    
    window.draw_line(start_point.x, start_point.y, next_point.x, next_point.y, use_color.r, use_color.g, use_color.b);
    
    start_point = next_point;
  }

}

void Circle::draw(Window const& window, unsigned int facets, float weight, bool highlight) const {

  Mat2 rotation_matrix = make_rotation_mat2(2 * M_PI / facets);
  Vec2 start_point{(center_.x + radius_), center_.y};
  Vec2 next_point;
  Color use_color{highlight ? highlight_color_ : color_};

  for(unsigned int i = 0; i < facets; i++) {
    next_point = (start_point - center_) * rotation_matrix;
    next_point += center_;
    
    window.draw_line(start_point.x, start_point.y, next_point.x, next_point.y, use_color.r, use_color.g, use_color.b, weight);
    
    start_point = next_point;
  }

}

bool Circle::is_inside(Vec2 point) const {
  return pow(radius_, 2) > (pow(point.x - center_.x, 2) + pow(point.y - center_.y, 2));
};

