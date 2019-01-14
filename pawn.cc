#include "pawn.h"

Pawn::Pawn(Colour colour) : Piece(colour) {}
std::string Pawn::nameLongImpl() { return "Pawn"; }
char Pawn::nameShortImpl() { return '\0'; }
char Pawn::nameCharImpl() { return '\0'; }
