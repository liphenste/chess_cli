#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>

#include "colour.h"
#include "grid.h"
#include "model.h"

class GameState : public Model {
  // in FEN order
  Grid position;
  Colour turn;
  bool canWhiteCastleShort;
  bool canWhiteCastleLong;
  bool canBlackCastleShort;
  bool canBlackCastleLong;
  std::string enPassant;
  int halfMoveClock;  // 100 half moves for a draw
  int move;

 public:
  GameState();  // sets position to game start
  ~GameState();
  void emptyState();
  void startState();

  std::string halfMovesTilDraw() const;
  // ie. 1. e4 FEN: rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1
  void setFEN(std::string fen);  // assumes the given string is a valid FEN
  std::string getFEN();

  friend std::ostream &operator<<(std::ostream &out, const GameState &g);
};

#endif
