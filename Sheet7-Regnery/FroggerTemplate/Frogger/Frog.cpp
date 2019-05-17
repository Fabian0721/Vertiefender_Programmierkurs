#include "Frog.h"
#include "Terminal.h"
#include <vector>
#include "Vec2D.h"
#include "Car.h"
#include "Teich.h"
/**
* Konstruktor
*/
Frog::Frog() {
    _segments = {                         {8, 1},                                    {13, 1},
                  {5, 2},         {7, 2}, {8, 2}, {9, 2}, {10, 2}, {11, 2}, {12, 2}, {13, 2}, {14, 2}, {15, 2},          {17, 2},
          {4, 3},         {6, 3},         {8, 3}, {9, 3}, {10, 3}, {11, 3}, {12, 3}, {13, 3}, {14, 3},          {16, 3},          {18, 3},
          {4, 4}, {5, 4}, {6, 4},                                                                               {16, 4}, {17, 4}, {18, 4} };
}

/**
* Methode die Objekt ins Terminal zeichnet
*/
void Frog::draw(Terminal& term) {
  int i = 0;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '(');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '@');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, ')');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '-');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '(');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '@');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, ')');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '(');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '\\');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '(');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '"');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, ')');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '/');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, ')');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '/');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '|');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '\\');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '/');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '|');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '\\');
  i++;

}
/**
* Update des Froschs
*/
void Frog::update(char key)
{

    switch(key) {
        case 'w':
        for (int i = 0; i < _segments.size(); i++) {
          _segments[i].y -= 4;
        }
            break;

        case 's':
        for (int i = 0; i < _segments.size(); i++) {
            _segments[i].y += 4;
        }
            break;

        case 'd':
        for (int i = 0; i < _segments.size(); i++) {
            _segments[i].x += 6;
        }
            break;

        case 'a':
        for (int i = 0; i < _segments.size(); i++) {
            _segments[i].x -= 6;
        }
            break;

        default:
            break;
    }
}

bool Frog::collides_with(Car aut) {
  for (int i = 0; i < _segments.size(); i++) {
    if (_segments[i] == aut.get_segments(i)) {
      return true;
    }
  }
  return false;
}

bool Frog::collides_with(Teich nass) {
  for (int i = 0; i < _segments.size(); i++) {
    if (_segments[i] == nass.get_segment(i)) {
      return true;
    }
  }
  return false;
}
