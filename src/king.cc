#include "king.h"

King::King(Colour colour) : Piece(colour) {}
std::string King::nameLongImpl() { return "King"; }
char King::nameShortImpl() {
  return (getColour() == Colour::WHITE ? 'K' : 'k');
}
char King::nameCharImpl() { return (getColour() == Colour::WHITE ? 'K' : 'k'); }
