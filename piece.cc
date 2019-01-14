#include "piece.h"

Piece::Piece(Colour colour) : colour{colour} {}

Colour Piece::getColour() { return colour; }

std::string Piece::nameLong() {
  return (getColour() == Colour::WHITE ? "White" : "Black") + std::string(" ") +
         nameLongImpl();
}
std::string Piece::nameShort() {
  return (getColour() == Colour::WHITE ? "w" : "b") + nameShortImpl();
}
char Piece::nameChar() { return nameCharImpl(); }

Piece::~Piece() {}