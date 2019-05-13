#include "rect.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

#include <cmath>

Rect::Rect() :
  min_{0.f, 0.f},
  max_{1.f, 1.f},
  color_{0.5f,0.5f,0.5f}
{};

Rect::Rect(Rect const& r) :
  min_{r.min_},
  max_{r.max_},
  color_{r.color_}
{};

Rect::Rect(Vec2 const& min, Vec2 const& max, Color const& color) :
  min_{min},
  max_{max},
  color_{color}
{}

float Rect::circumference() const {
  return 2 * (abs(max_.x - min_.x) + abs(max_.y - min_.y));
}

void Rect::draw(Window const& window) const {
  window.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b);
  window.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b);
  window.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b);
  window.draw_line(max_.x, min_.y, min_.x, min_.y, color_.r, color_.g, color_.b);
}

void Rect::draw(Window const& window, float weight) const {
  window.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, weight);
  window.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b, weight);
  window.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b, weight);
  window.draw_line(max_.x, min_.y, min_.x, min_.y, color_.r, color_.g, color_.b, weight);
}

bool Rect::is_inside(Vec2 point) const {
  return point.x >= min_.x
         && point.x <= max_.x
         && point.y >= min_.y
         && point.y <= max_.y;
}

