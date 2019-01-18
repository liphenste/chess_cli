#include "knight.h"

Knight::Knight(Colour colour) : Piece(colour) {}
std::string Knight::nameLongImpl() { return "Knight"; }
char Knight::nameShortImpl() {
  return (getColour() == Colour::WHITE ? 'N' : 'n');
}
char Knight::nameCharImpl() {
  return (getColour() == Colour::WHITE ? 'N' : 'n');
}
