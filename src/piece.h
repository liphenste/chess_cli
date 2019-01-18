#ifndef PIECE_H
#define PIECE_H

#include <iostream>

#include "colour.h"

class Piece {
  Colour colour;

  virtual std::string nameLongImpl() = 0;
  virtual char nameShortImpl() = 0;
  virtual char nameCharImpl() = 0;

 public:
  Piece(Colour colour);
  Colour getColour();

  std::string nameLong();
  std::string nameShort();
  char nameChar();

  virtual ~Piece();
};

#endif
