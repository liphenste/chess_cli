#include "piece.h"

Piece::Piece(Colour colour) : colour{colour} {}

Colour Piece::getColour() { return colour; }

std::string Piece::nameLong() {
  return std::string() + (getColour() == Colour::WHITE ? "White" : "Black") +
         ' ' + nameLongImpl();
}
std::string Piece::nameShort() {
  return std::string() + (getColour() == Colour::WHITE ? "w" : "b") +
         nameShortImpl();
}
char Piece::nameChar() { return nameCharImpl(); }

Piece::~Piece() {}