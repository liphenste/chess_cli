#ifndef PIECE_H
#define PIECE_H

class Piece {
  Piece(Colour c);

  friend std::ostream &operator<<(std::ostream &out, const Piece &p);
};

#endif
