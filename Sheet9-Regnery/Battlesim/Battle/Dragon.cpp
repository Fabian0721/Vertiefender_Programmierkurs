#include "Dragon.h"
#include "Vec2D.h"
#include <vector>
#include "Terminal.h"

Dragon::Dragon()
{
    _segments = { {7, 4}, {8, 5}, {7, 5}, {6, 5}, {7, 6} };
}

void Dragon::update(char key)
{
  switch(key) {
      case 'w':
          for (int i = 0; i < _segments.size(); i++) {
            this->_segments[i].y -= 3;
          }
          break;

      case 's':
          for (int i = 0; i < _segments.size(); i++) {
          this->_segments[i].y += 3;
          }
          break;

      case 'd':
          for (int i = 0; i < _segments.size(); i++) {
          this->_segments[i].x += 6;
          }
          break;

      case 'a':
        for (int i = 0; i < _segments.size(); i++) {
          this->_segments[i].x -= 6;
        }
          break;

      default:
          break;
  }
}

void Dragon::draw(Terminal& term)
{
    term.set_cell(_segments[0].x, _segments[0].y, '_');
    term.set_cell(_segments[1].x, _segments[1].y, '/');
    term.set_cell(_segments[2].x, _segments[2].y, '|');
    term.set_cell(_segments[3].x, _segments[3].y, '\\');
    term.set_cell(_segments[4].x, _segments[4].y, '*');

}

Vec2D Dragon::feuer() {
  return _segments[4];
}
