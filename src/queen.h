#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece {
 public:
  Queen(Colour colour);
  std::string nameLongImpl() override;
  char nameShortImpl() override;
  char nameCharImpl() override;
};

#endif
