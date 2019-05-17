#ifndef WEISWANDERER_H
#define WEISWANDERER_H

#include <vector>
#include "Vec2D.h"
#include "Terminal.h"
#include "Nachtwache.h"
#include "Wall.h"
#include "Dragon.h"
class Nachtwache;
class Wall;

class Weiswanderer {
public:
  /**
	* Initzialisiert einen Weiswanderer auf einer zufällige Position im Ödland
	*/
    Weiswanderer( int i);
  /**
  * Zeichne eine Nachtwache ins Terminal
  */
    void draw(Terminal& term);
  /**
  * Update den Ort der Nachtwache
  */
    void update();
  /**
  * Gibt standort zutück
  */
    Vec2D get_segments();
  /**
  * Checkt auf Kampf gegen Drachen
  */
    bool collides_with(Dragon drache);
  /**
  * Checkt ob der Kämpfer im Ziel ist
  */
    bool collides_with( std::vector<Wall>& walls);

private:
    std::vector<Vec2D> _segments;
};
#endif
