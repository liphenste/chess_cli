#include "bishop.h"

Bishop::Bishop(Colour colour) : Piece(colour) {}
std::string Bishop::nameLongImpl() { return "Bishop"; }
char Bishop::nameShortImpl() { return 'B'; }
char Bishop::nameCharImpl() { return 'B'; }
