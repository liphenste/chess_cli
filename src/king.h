#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
 public:
  King(Colour colour);
  std::string nameLongImpl() override;
  char nameShortImpl() override;
  char nameCharImpl() override;
};

#endif
