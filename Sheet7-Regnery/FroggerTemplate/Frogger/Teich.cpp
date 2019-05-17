#include "Vec2D.h"
#include <vector>
#include "Terminal.h"
#include "Teich.h"

Teich::Teich() {
  _segments = { {70, 35},{69, 35},{68, 35},{67, 35},{66, 35},{65, 35},{64, 35},{63, 35},{62, 35},{61, 35},{60, 35},{70, 36},{69, 36},{68, 36},{67, 36},{66, 36},{65, 36},{64, 36},{63, 36},{62, 36},{61, 36},{60, 36}};
}

void Teich::draw(Terminal& term) {
  for (int i = 0; i < _segments.size(); i++) {
    term.set_cell(_segments[i].x, _segments[i].y, '~');
  }

}

Vec2D Teich::get_segment(int pos) {
  return this->_segments[pos];
}
