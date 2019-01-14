#include "queen.h"

Queen::Queen(Colour colour) : Piece(colour) {}
std::string Queen::nameLongImpl() { return "Queen"; }
char Queen::nameShortImpl() { return 'Q'; }
char Queen::nameCharImpl() { return 'Q'; }
