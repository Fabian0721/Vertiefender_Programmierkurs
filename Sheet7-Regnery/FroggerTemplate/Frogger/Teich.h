#ifndef TEICH_H
#define TEICH_H

#include "Vec2D.h"


class Teich {
public:
  Teich();
  void draw(Terminal& term);
  Vec2D get_segment(int pos);
private:
  std::vector<Vec2D> _segments;
};
#endif
