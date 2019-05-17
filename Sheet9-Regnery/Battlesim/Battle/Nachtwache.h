#ifndef NACHTWACHE_H
#define NACHTWACHE_H

#include "Vec2D.h"
#include <vector>
#include "Terminal.h"
#include "Weiswanderer.h"
#include "Wall.h"
#include "Vec2D.h"
class Weiswanderer;
class Wall;
class Nachtwache {
public:
  /**
	* Initzialisiert eine Nachtwache auf eine zufällige Position am Wall
	*/
    Nachtwache(int i);
  /**
  * Zeichne eine Nachtwache ins Terminal
  */
    void draw(Terminal& term);
  /**
  * Update den Ort der Nachtwache
  */
    void update();
  /**
  * Checkt ob Kampf stattfindet
  */
    bool collides_with(Weiswanderer& weis);
  /**
  * Gibt standort zutück
  */
  Vec2D get_segments();
  /**
  * Checkt ob der Kämpfer im Ziel ist
  */
  bool collides_with( std::vector<Wall>& walls);

private:
  std::vector<Vec2D> _segments;
};
#endif
