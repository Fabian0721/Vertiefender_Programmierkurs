#ifndef GAME_H
#define  GAME_H

#include <vector>
#include "Terminal.h"
#include "Vec2D.h"
#include "Frog.h"
#include "Car.h"
#include "Teich.h"

class Game {
public:
  /**
	* Initzialisiert ein neues Spiel
	*/
    Game(Terminal& term);

	/**
	* Prüft ob das Spiel beendet werden möchte
	*/
    bool is_done();

	/**
	* Rückt das Spiel fort (wird auch frame genannt)
	*/
    void update();

	/**
	* Zeichnet das Spiel
	*/
    void draw();

  /**
  * Inizialisiert eine Straße
  */
    void road();
    void road2();
    void road3();
    void road4();
    void road5();

    /**
    * Gewinn ausgabe
    */
    void draw_game_win();

private:
  void draw_game_over();
  bool _game_over;
  bool _is_done;
  Terminal& _term;
  Car _car;
  std::vector<Car> _road;
  std::vector<Car> _road2;
  std::vector<Car> _road3;
  std::vector<Car> _road4;
  std::vector<Car> _road5;
  Frog _frog;
  Teich _teich;
};

#endif
