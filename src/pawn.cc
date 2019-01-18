#include "pawn.h"

Pawn::Pawn(Colour colour) : Piece(colour) {}
std::string Pawn::nameLongImpl() { return "Pawn"; }
char Pawn::nameShortImpl() {
  return (getColour() == Colour::WHITE ? 'P' : 'p');
}
char Pawn::nameCharImpl() { return (getColour() == Colour::WHITE ? 'P' : 'p'); }
