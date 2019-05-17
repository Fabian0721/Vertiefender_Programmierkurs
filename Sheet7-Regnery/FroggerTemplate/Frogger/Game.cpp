#include "Game.h"
#include <random>
//#include "Terminal.h"
#include <curses.h>
#include "Teich.h"


Game::Game(Terminal& term) :
    _game_over(false),
    _is_done(false),
    _term(term)
{
  road();
  road2();
  road3();
  road4();
  road5();
}

bool Game::is_done()
{
    return _is_done;
}

void Game::update()
{
    char pressed = _term.get_key();
    _frog.update(pressed); //Tasten druck wird eingelesen, der Frosch wird bewegt
    //_car update();
    for (int i = 0; i < _road.size(); i++) {
      _road[i].update();
      if (_frog.collides_with(_road[i])) {
        _game_over = true;
      }
    }
    for (int i = 0; i < _road2.size(); i++) {
      _road2[i].update();
      if (_frog.collides_with(_road2[i])) {
        _game_over = true;
      }
    }
    for (int i = 0; i < _road3.size(); i++) {
      _road3[i].update();
      if (_frog.collides_with(_road3[i])) {
        _game_over = true;
      }
    }
    for (int i = 0; i < _road4.size(); i++) {
      _road4[i].update();
      if (_frog.collides_with(_road4[i])) {
        _game_over = true;
      }
    }
    for (int i = 0; i < _road5.size(); i++) {
      _road5[i].update();
      if (_frog.collides_with(_road5[i])) {
        _game_over = true;
      }
    }
    if (pressed == 'e') {
      _game_over = true;
    }
    if (_frog.collides_with(_teich)) {
      void draw_game_win();
    }
  /*  if (_frog.collides_with(_car)) {
      _game_over = true;
    }*/
    switch (pressed) {
        case 'r':
            _game_over = false;
              _frog = Frog();
            break;
        case 'q':
            _is_done = true;
            break;

        default:
            break;
    }
}

void Game::draw()
{
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  color_set(1, 0);
    if (_game_over) {
        draw_game_over();
        return;
    }
    _term.clear();
  //  color_set();
    _frog.draw(_term);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  color_set(2, 0);
    for (int i = 0; i < _road.size(); i++) {
      _road[i].draw(_term);
    }
    for (int i = 0; i < _road2.size(); i++) {
      _road2[i].draw(_term);
    }
    for (int i = 0; i < _road3.size(); i++) {
      _road3[i].draw(_term);
    }
    for (int i = 0; i < _road4.size(); i++) {
      _road4[i].draw(_term);
    }
    for (int i = 0; i < _road5.size(); i++) {
      _road5[i].draw(_term);
    }
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    color_set(2, 0);
    _teich.draw(_term);
  //  _car.draw(_term);

    _term.sleep(50);

}

void Game::draw_game_over()
{
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  color_set(2, 0);
    std::string score_text = "Game Over!";
    std::string reset_text = "Press 'r' to restart.";

    int half_width = _term.width() / 2;
    int half_height = _term.height() / 2;

    _term.draw_text(half_width - score_text.size()/2, half_height, score_text);
    _term.draw_text(half_width - reset_text.size()/2, half_height + 1, reset_text);
}

void Game::draw_game_win()
{
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  color_set(2, 0);
    std::string score_text = "Winnnnnnnnnnnnnnnerrrr";
    std::string reset_text = "Press 'r' to restart.";

    int half_width = _term.width() / 2;
    int half_height = _term.height() / 2;

    _term.draw_text(half_width - score_text.size()/2, half_height, score_text);
    _term.draw_text(half_width - reset_text.size()/2, half_height + 1, reset_text);
}

void Game::road() {
  for (int i = 0; i < 2; i++) {
    _road.push_back(_car);
  }
  for (int k = 0; k < _road.size(); k++) {
    _road[k].posi(_road[k], k);
  }
}

void Game::road2() {
  for (int i = 0; i < 3; i++) {
    _road2.push_back(_car);
  }
  for (int k = 0; k < _road2.size(); k++) {
    _road2[k].posi2(_road2[k], k);
  }
}

void Game::road3() {
  for (int i = 0; i < 4; i++) {
    _road3.push_back(_car);
  }
  for (int k = 0; k < _road3.size(); k++) {
    _road3[k].posi3(_road3[k], k);
  }
}

void Game::road4() {
  for (int i = 0; i < 3; i++) {
    _road4.push_back(_car);
  }
  for (int k = 0; k < _road4.size(); k++) {
    _road4[k].posi4(_road4[k], k);
  }
}

void Game::road5() {
  for (int i = 0; i < 1; i++) {
    _road5.push_back(_car);
  }
  for (int k = 0; k < _road5.size(); k++) {
    _road5[k].posi5(_road5[k], k);
  }
}
