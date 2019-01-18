#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
 public:
  Pawn(Colour colour);
  std::string nameLongImpl() override;
  char nameShortImpl() override;
  char nameCharImpl() override;
};

#endif
