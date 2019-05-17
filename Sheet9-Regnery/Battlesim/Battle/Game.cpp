#include "Game.h"
#include <random>
#include "curses.h"
#include "Terminal.h"
#include "Weiswanderer.h"
#include "Nachtwache.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>


Game::Game(Terminal& term) :
    _elapsed_time(0.f),
    _score(0),
    _game_over(false),
    _is_done(false),
    _term(term),
    _food(new_food_position()),
    _weiswanderer(time(NULL)),
    _nachtwache(time(NULL))
{
    _walls = {
        Wall(Vec2D(0, 0), Vec2D(0, _term.height()-1)), //Linke Wand
        Wall(Vec2D(0, 0), Vec2D(_term.width()-1, 0)), //Oben Wand
        Wall(Vec2D(_term.width()-1, 0), Vec2D(_term.width()-1, _term.height()-1)), //Rechte Wand
        Wall(Vec2D(0, _term.height()-1), Vec2D(_term.width()-1, _term.height()-1)), //Unten Wand
    };
    Dragon();
}

bool Game::is_done()
{
    return _is_done;
}

void Game::update(float dt)
{
    char pressed = _term.get_key();
    switch (pressed) {
        case 'r':
            _game_over = false;
            _food = Food(new_food_position());
            _weiswanderer = Weiswanderer(time(NULL));
            _nachtwache = Nachtwache(time(NULL));
            _dragon = Dragon();
            _nachtwachen.erase(_nachtwachen.begin(), _nachtwachen.end());
            _weiswanderern.erase(_weiswanderern.begin(), _weiswanderern.end());
            break;

        case 'q':
            _is_done = true;
            break;

        case 'e':
            _game_over = true;
            break;

        default:
            break;
    }
    _elapsed_time += dt;
    if (_elapsed_time >= 0.1f) //0,1
    {
        if (!_game_over) {
          //Möglichkeit die Anzahl der Kämpfer zu vergeringern
          /*  srand (time(NULL));
            int y = (rand() % 4);

            if (y == 3 ) {*/
            _dragon.update(_term.get_key());
            _nachtwache = Nachtwache(rand());
            _nachtwachen.push_back(_nachtwache);

          //  }
        //  _term.sleep(41);
            /*srand (time(NULL)+1);
            y = rand();
            if (y % 2==1 ) {*/
            _term.sleep(41);
            _weiswanderer = Weiswanderer(rand());
            _dragon.update(_term.get_key());
            _weiswanderern.push_back(_weiswanderer);

            _dragon.update(_term.get_key());

            //Prüfen auf Kolisionen mit Wand und Drachenfeuer, erzeugen der Blut lache
            for (int i = 0; i < _nachtwachen.size(); i++) {
              for (int l = 0; l < _weiswanderern.size(); l++) {
                if(_nachtwachen[i].collides_with(_weiswanderern[l])) {
                  if ((rand()% 100) % 2 == 1) {
                     _nachtwachen.erase(_nachtwachen.begin()+i);
                     _blood.push_back(_nachtwachen[i].get_segments());
                  } else {
                      _weiswanderern.erase(_weiswanderern.begin()+l); //i statt l
                      _blood.push_back(_weiswanderern[l].get_segments());
                  }

                  if (_weiswanderern[l].collides_with(_dragon)) {
                    _weiswanderern.erase(_weiswanderern.begin()+l);
                    _blood.push_back(_weiswanderern[l].get_segments());
                  }
                }
              }
            }
            //Updaten des Spieles
            for (int i = 0; i < _nachtwachen.size(); i++) {
              _nachtwachen[i].update();
            }
            for (int i = 0; i < _weiswanderern.size(); i++) {
              _weiswanderern[i].update();
            }
            _dragon.update(_term.get_key());


            if (_snake.collides_with(_food)) {
                _snake.grow();
                _food = Food(new_food_position());
                _score += 10;
            }

            for (int i = 0; i < _nachtwachen.size(); i++) {
              if (_nachtwachen[i].collides_with(_walls)) {
                  _game_over = true;
              }
            }

            for (int i = 0; i < _weiswanderern.size(); i++) {
              if (_weiswanderern[i].collides_with(_walls)) {
                  _game_over = true;
              }
            }
        }
        _elapsed_time = 0.f;
    }
}

void Game::draw()
{
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  bkgd(COLOR_PAIR(1));
    if (_game_over) {
        draw_game_over();
        return;
    }

    _term.clear();

    init_pair(7, COLOR_RED, COLOR_RED);
    color_set(7, 0);

    for (int i = 0; i < _blood.size(); i++) {
      _term.set_cell(_blood[i].x, _blood[i].y, 'O');
    }

    init_pair(8, COLOR_CYAN, COLOR_WHITE);
    color_set(8, 0);

    for (std::size_t i = 0; i < _walls.size(); ++i) {
        _walls[i].draw(_term);
    }

    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    color_set(4, 0);

    for (int i = 0; i < _nachtwachen.size(); i++) {
      _nachtwachen[i].draw(_term);
    }

    init_pair(2, COLOR_WHITE, COLOR_BLUE);
    color_set(2, 0);

    for (int i = 0; i < _weiswanderern.size(); i++) {
      _weiswanderern[i].draw(_term);
      _dragon.draw(_term);
    }

    init_pair(9, COLOR_BLACK, COLOR_WHITE);
    color_set(9, 0);
    _dragon.draw(_term);

    init_pair(3, 130, COLOR_WHITE);
    color_set(3, 0);
    _food.draw(_term);

    _term.sleep(24);
    }


void Game::draw_game_over()
{
    std::string score_text = "Game Over! You lost, a White Walkers conquers the wall " /*+ std::to_string(_score) + *//*+" points."*/;
    std::string reset_text = "Press 'r' to restart.";

    int half_width = _term.width() / 2;
    int half_height = _term.height() / 2;

    _term.draw_text(half_width - score_text.size()/2, half_height, score_text);
    _term.draw_text(half_width - reset_text.size()/2, half_height + 1, reset_text);
}

Vec2D Game::new_food_position()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis_x(1, _term.width()-2);
    static std::uniform_int_distribution<> dis_y(1, _term.height()-2);

    return { dis_x(gen), dis_y(gen) };
}
