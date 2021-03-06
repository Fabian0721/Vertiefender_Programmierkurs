#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Terminal.h"
#include "Vec2D.h"
#include "Snake.h"
#include "Food.h"
#include "Wall.h"
#include "Weiswanderer.h"
#include "Nachtwache.h"
#include "Dragon.h"


class Game
{
public:
	/**
	* Initializes a new game
	*
	* @param term The terminal to draw our game on
	*/
    Game(Terminal& term);

	/**
	* Checks whether we are done with our game and should
	* end the game loop.
	*
	* @return True if the game loop is done
	*/
    bool is_done();

	/**
	* Advances the game by one step (also called frame)
	*
	* @param dt The time elapsed since the last step in seconds.
	*/
    void update(float dt);

	/**
	* Draw the game.
	*/
    void draw();

  /**
  * Initialisiert NAchtwachen
  */
    //void _nachtwachen();

private:
    void draw_game_over();
    Vec2D new_food_position();

    float _elapsed_time;
    int _score;
    bool _game_over;
    bool _is_done;
    Terminal& _term;
    Snake _snake;
    Dragon _dragon;
    std::vector<Vec2D> _blood;
    Nachtwache _nachtwache;
    Weiswanderer _weiswanderer;
    std::vector<Nachtwache> _nachtwachen;
    std::vector<Weiswanderer> _weiswanderern;

    //Nachtwache* _nacht;
    //Weiswanderer* _weis;

    Food _food;
    std::vector<Wall> _walls;
};

#endif
