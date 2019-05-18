#include "window.hpp"
#include <string>

class CircleDrawer {
  public:
    CircleDrawer(std::string const& selected, const Window& win) :
      selected_name_{selected},
		  window_(win)
    {}          
    void operator() (Circle const& c) {
      c.draw(window_, 36, 2.f, c.get_name() == selected_name_);
    }
  private:
    std::string selected_name_;
    const Window& window_;
};
