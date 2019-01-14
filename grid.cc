#include "grid.h"
#include <iostream>
#include <string>
#include "colour.h"
#include "piece.h"

Grid::Grid() {
  for (char f = 'a'; f <= 'h'; f++) {
    for (char r = '1'; r <= '8'; r++) {
      if ((f + r) % 2)
        theGrid[std::string() + f + r] =
            std::make_unique<Square>(f, r, Colour::WHITE);
      else
        theGrid[std::string() + f + r] =
            std::make_unique<Square>(f, r, Colour::BLACK);
    }
  }
  std::cout << *(theGrid["h1"]);  // h1 should be white
}

void Grid::addPiece(Piece *piece, std::string pos) {
  theGrid[pos]->piece = piece;
}

void Grid::removePiece(std::string pos) {
  if (theGrid[pos]->piece) delete theGrid[pos]->piece;
  theGrid[pos]->piece = nullptr;
}

std::ostream &operator<<(std::ostream &out, const Grid &g) {
  out << "__________________" << std::endl;
  for (char f = '8'; f >= '1'; f--) {
    out << "|";
    for (char r = 'a'; r <= 'h'; r++) {
      out << g.theGrid.at(std::string() + f + r)->piece->nameLong();
    }
    out << "|" << std::endl;
  }
  out << "__________________" << std::endl;
  return out;
}
