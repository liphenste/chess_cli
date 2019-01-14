#include "knight.h"

Knight::Knight(Colour colour) : Piece(colour) {}
std::string Knight::nameLongImpl() { return "Knight"; }
char Knight::nameShortImpl() { return 'N'; }
char Knight::nameCharImpl() { return 'N'; }
