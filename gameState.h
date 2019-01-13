#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "grid.h"
#include "model.h"

class GameState : public Model {
  bool whiteCastled;
  bool blackCastled;

  void emptyState();
  void startState();
};

#endif
