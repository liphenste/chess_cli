#ifndef SQUARE_H
#define SQUARE_H

#include "colour.h"
#include "piece.h"

class Square {
  char file;
  char rank;
  Colour c;

 public:
  Piece *piece;
  Square(char file, char rank, Colour c);
  Square(char file, char rank, Colour c, Piece *piece);

  void setPiece(Piece *p);
  std::string nameShort();
  friend std::ostream &operator<<(std::ostream &out, const Square &s);
};

#endif