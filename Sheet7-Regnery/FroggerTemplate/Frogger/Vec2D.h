#ifndef VEC2D_H
#define VEC2D_H

class Vec2D
{
public:
    Vec2D() {};
    Vec2D(int x, int y) :
        x(x), y(y) {}

	int x;
	int y;
  friend bool operator== (Vec2D a, Vec2D b) {
    if (a.x == b.x && a.y == b.y) {
      return true;
    } else {
      return false;
    }
  }
};

#endif
