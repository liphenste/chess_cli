#include "pawn.h"

Pawn::Pawn(Colour colour) : Piece(colour) {}
std::string Pawn::nameLongImpl() { return "Pawn"; }
char Pawn::nameShortImpl() { return 'p'; }
char Pawn::nameCharImpl() { return 'p'; }
