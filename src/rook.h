#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
 public:
  Rook(Colour colour);
  std::string nameLongImpl() override;
  char nameShortImpl() override;
  char nameCharImpl() override;
};

#endif
