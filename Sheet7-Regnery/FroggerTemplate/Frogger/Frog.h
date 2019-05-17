#ifndef FROG_H
#define FROG_H

#include "Terminal.h"
#include "Vec2D.h"
#include <vector>
#include "Car.h"
#include "Teich.h"

class Frog {
public:
  /**
  * Konstruktor des Frosch
  */
  Frog();
  /**
  * Zeichnet den Frosch ins Terminal
  */
  void draw(Terminal& term);
  /**
	* Update den Frosch im Spielverlauf .
	*/
  void update(char key);
  /**
  * Prüft ob der Frosch überfahren wird
  */
  bool collides_with(Car aut);

  /**
  * Prüft ob der Frosch im Ziel ist
  */
  bool collides_with(Teich nass);

private:
  std::vector<Vec2D> _segments; //Aussehen des Froschs
};

#endif
