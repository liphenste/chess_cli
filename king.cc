#include "king.h"

King::King(Colour colour) : Piece(colour) {}
std::string King::nameLongImpl() { return "King"; }
char King::nameShortImpl() { return 'K'; }
char King::nameCharImpl() { return 'K'; }
