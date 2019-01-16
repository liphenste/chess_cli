#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>

#include "colour.h"
#include "grid.h"
#include "model.h"

class GameState : public Model {
  Colour turn;
  int move;
  bool whiteCastled;
  bool blackCastled;
  Grid position;

 public:
  GameState();  // sets position to game start
  ~GameState();
  void startState();

  friend std::ostream &operator<<(std::ostream &out, const GameState &g);
};

#endif
