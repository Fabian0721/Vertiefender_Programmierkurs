#ifndef CAR_H
#define CAR_H

#include "Terminal.h"
#include "Vec2D.h"
#include <vector>

class Car {
public:
  /**
  * Konstruktor des Autos
  */
  Car();
  /**
  * Zeichnet das Auto ins Terminal
  */
  void draw(Terminal& term);
  /**
	* Update das Auto im Spielverlauf .
	*/
  void update();
  /**
  * Auto positionen
  */
  void posi(Car& car, int n);
  void posi2(Car& car, int n);
  void posi3(Car& car, int n);
  void posi4(Car& car, int n);
  void posi5(Car& car, int n);
  /**
  * Geter segements
  */
  Vec2D get_segments(int pos);
//std::vector<Vec2D> _segments; //Aussehen des Autos
private:
 std::vector<Vec2D> _segments; //Aussehen des Autos

};

#endif
