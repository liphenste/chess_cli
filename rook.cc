#include "rook.h"

Rook::Rook(Colour colour) : Piece(colour) {}
std::string Rook::nameLongImpl() { return "Rook"; }
char Rook::nameShortImpl() { return 'R'; }
char Rook::nameCharImpl() { return 'R'; }
