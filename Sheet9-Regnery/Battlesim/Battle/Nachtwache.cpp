#include "Nachtwache.h"
#include "Terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Weiswanderer.h"
#include "Wall.h"


Nachtwache::Nachtwache(int i) {
    //Spornt Random
    srand (i);
    int y = (rand() % 18) + 1;

    _segments = { {0, y} };
}

void Nachtwache::draw(Terminal& term) {
  term.set_cell(_segments[0].x, _segments[0].y, 'N');
}

void Nachtwache::update() {
  _segments[0].x += 1;
}

bool Nachtwache::collides_with(Weiswanderer& weis) {
  Vec2D vec = _segments[0];
  if (_segments[0] == weis.get_segments()) {
      return true;
  }
  vec.x = vec.x + 1;
  if (vec == weis.get_segments()) {
      return true;
  }
  vec.x = vec.x - 2;
  if (vec == weis.get_segments()) {
      return true;
  }

  return false;
}

Vec2D Nachtwache::get_segments() {
  return this->_segments[0];
}

bool Nachtwache::collides_with( std::vector<Wall>& walls)
{
    for (int i = 0; i < walls.size(); i++) {

      if (walls[i].collides_with(*this)) {
        return true;
      }
    }


    return false;
}
