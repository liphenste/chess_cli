#include "square.h"

Square::Square(char file, char rank, Colour c)
    : file{file}, rank{rank}, c{c}, piece{nullptr} {}

Square::Square(char file, char rank, Colour c, Piece *piece)
    : file{file}, rank{rank}, c{c}, piece{piece} {}

void Square::setPiece(Piece *p) { piece = p; }

std::string Square::nameShort() { return piece ? piece->nameShort() : " "; }

char Square::nameChar() { return piece->nameChar(); }

std::ostream &operator<<(std::ostream &out, const Square &s) {
  if (s.piece == nullptr)
    out << "No piece";
  else
    out << (*s.piece).nameLong();
  out << " on ";
  out << s.file << s.rank;
  out << (s.c == Colour::WHITE ? " (white square)" : " (black square)");
  return out;
}
