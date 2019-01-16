#include "queen.h"

Queen::Queen(Colour colour) : Piece(colour) {}
std::string Queen::nameLongImpl() { return "Queen"; }
char Queen::nameShortImpl() {
  return (getColour() == Colour::WHITE ? 'Q' : 'q');
}
char Queen::nameCharImpl() {
  return (getColour() == Colour::WHITE ? 'Q' : 'q');
}
