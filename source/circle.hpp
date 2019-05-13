#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
  
  public:
              Circle();
              Circle(Circle const& c);
              Circle(Vec2 const& center, float radius, Color const& color, Color const& highlight_color);
  
    double    circumference() const;
    void      draw(Window const& window, unsigned int facets, bool highlight = false) const;
    void      draw(Window const& window, unsigned int facets, float weight, bool highlight = false) const;
    bool      is_inside(Vec2 point) const;

  private:
    Vec2  center_;
    float radius_;
    Color color_;
    Color highlight_color_;
    std::string name_;
};

#endif
