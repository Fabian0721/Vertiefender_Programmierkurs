#ifndef DRAGON_H
#define DRAGON_H

#include "Vec2D.h"
#include <vector>
#include "Terminal.h"

class Dragon {
public:
  /**
	* Initzialisiert einn Drachen auf eine Position
	*/
    Dragon();
  /**
  * Zeichne einen Drache ins Terminal
  */
    void draw(Terminal& term);
  /**
  * Update den Ort des Drachen
  */
    void update(char key);
  /**
  * Returnt Feuerball
  */
    Vec2D feuer();
private:
  std::vector<Vec2D> _segments;
};

#endif
