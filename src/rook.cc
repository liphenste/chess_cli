#include "rook.h"

Rook::Rook(Colour colour) : Piece(colour) {}
std::string Rook::nameLongImpl() { return "Rook"; }
char Rook::nameShortImpl() {
  return (getColour() == Colour::WHITE ? 'R' : 'r');
}
char Rook::nameCharImpl() { return (getColour() == Colour::WHITE ? 'R' : 'r'); }
