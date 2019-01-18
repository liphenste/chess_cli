#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
 public:
  Knight(Colour colour);
  std::string nameLongImpl() override;
  char nameShortImpl() override;
  char nameCharImpl() override;
};

#endif
