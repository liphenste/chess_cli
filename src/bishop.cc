#include "bishop.h"

Bishop::Bishop(Colour colour) : Piece(colour) {}
std::string Bishop::nameLongImpl() { return "Bishop"; }
char Bishop::nameShortImpl() {
  return (getColour() == Colour::WHITE ? 'B' : 'b');
}
char Bishop::nameCharImpl() {
  return (getColour() == Colour::WHITE ? 'B' : 'b');
}
