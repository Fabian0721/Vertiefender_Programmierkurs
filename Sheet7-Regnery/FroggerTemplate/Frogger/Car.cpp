#include "Car.h"
#include "Terminal.h"
#include <vector>
#include "Vec2D.h"
#include <curses.h>
/**
* Konstruktor
*/
Car::Car() {
    _segments = { {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}, {7, 6}, {8, 6}, {9, 6}, {10, 6}, {11, 6}, {12, 6}, {2, 7}, {11, 7}};

}

/**
* Methode die Objekt ins Terminal zeichnet
*/
void Car::draw(Terminal& term) {
  int i = 0;
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  color_set(4, 0);
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '/');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '-');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '-');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '-');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '-');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '\\');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, '_');
  i++;
  init_pair(3, COLOR_RED, COLOR_BLACK);
  color_set(3, 0);
  term.set_cell(_segments[i].x, _segments[i].y, 'o');
  i++;
  term.set_cell(_segments[i].x, _segments[i].y, 'o');
  i++;
}

/**
* Update das Auto im Spielverlauf.
*/
void Car::update() {
  for (int i = 0; i < _segments.size(); i++) {
      _segments[i].x += 1;
  }
  if (_segments[0].x == 88) {
    for (int i = 0; i < _segments.size(); i++) {
        _segments[i].x -= 88;
    }
  }
}

void Car::posi(Car& car, int n) {
  for (int i = 0; i < car._segments.size(); i++) {
    car._segments[i].x = car._segments[i].x - n * 70;

  }
}

void Car::posi2(Car& car, int n) {
  for (int i = 0; i < car._segments.size(); i++) {
    car._segments[i].x = car._segments[i].x - n * 55;
    car._segments[i].y += 4;
    car._segments[i].x += 12;
  }
}

void Car::posi3(Car& car, int n) {
  for (int i = 0; i < car._segments.size(); i++) {
    car._segments[i].x = car._segments[i].x - n * 55;
    car._segments[i].y += 12;
    car._segments[i].x += 6;
  }
}

void Car::posi4(Car& car, int n) {
  for (int i = 0; i < car._segments.size(); i++) {
    car._segments[i].x = car._segments[i].x - n * 30;
    car._segments[i].y += 23;
    car._segments[i].x += 12;
  }
}

void Car::posi5(Car& car, int n) {
  for (int i = 0; i < car._segments.size(); i++) {
    car._segments[i].x = car._segments[i].x - n * 30;
    car._segments[i].y += 18;
    car._segments[i].x += 8;
  }
}

Vec2D Car::get_segments(int pos) {
  return this->_segments[pos];
}
