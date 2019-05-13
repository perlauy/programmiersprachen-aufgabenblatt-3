#ifndef RECT_HPP
#define RECT_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rect {
  
  public:
              Rect();
              Rect(Rect const& r);
              Rect(Vec2 const& min, Vec2 const& max, Color const& color);

    float     circumference() const;
    void      draw(Window const& window) const;
    void      draw(Window const& window, float weight) const;
    bool      is_inside(Vec2 point) const;

  private:
    Vec2  min_;
    Vec2  max_;
    Color color_;
};

#endif
