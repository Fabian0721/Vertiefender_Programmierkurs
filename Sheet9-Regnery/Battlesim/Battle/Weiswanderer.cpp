#include "Weiswanderer.h"
#include "Terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Nachtwache.h"
#include "Wall.h"
#include "Dragon.h"
#include "Vec2D.h"

Weiswanderer::Weiswanderer(int i) {
  //Spornt Random
  srand (i);
  int y = (rand() % 18) + 1;

  _segments = { {79, y} };
}

void Weiswanderer::draw(Terminal& term) {
  term.set_cell(_segments[0].x, _segments[0].y, 'W');
}

void Weiswanderer::update() {
  _segments[0].x -= 1;
}

bool Weiswanderer::collides_with(Dragon drache) {
  if (_segments[0] == drache.feuer()) {
      return true;
  }
  return false;
}

Vec2D Weiswanderer::get_segments() {
  return this->_segments[0];
}

bool Weiswanderer::collides_with( std::vector<Wall>& walls)
{
    for (int i = 0; i < walls.size(); i++) {

      if (walls[i].collides_with(*this)) {
        return true;
      }
    }


    return false;
}
/*bool Weiswanderer::collides_with(const std::vector<Wall>& walls) const
{
    for (int i = 0; i < walls.size(); i++) {

      if (walls[i].collides_with(*this)) {
        return true;
      }
    }


    return false;
}*/
