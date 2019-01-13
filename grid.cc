#include "grid.h"
#include <iostream>
#include "colour.h"
#include "piece.h"

// Square Class

struct Grid::Square {
  char file;
  char rank;
  Colour c;
  Piece *piece;

  Square(char file, char rank, Colour c)
      : file{file}, rank{rank}, c{c}, piece{nullptr} {}
  Square(char file, char rank, Colour c, Piece *piece)
      : file{file}, rank{rank}, c{c}, piece{piece} {}

  std::ostream &operator<<(std::ostream &out, const Square &s) {
    if (piece == nullptr)
      out << "No piece";
    else
      out << *piece;
    out << " on ";
    out << file << rank;
    out << (c == WHITE ? " (white square)" : " (black square)");
    return out;
  }
};

std::ostream &operator<<(std::ostream &out, const Square &s) {
  out << file << rank;
  out << (c == WHITE ? " (white)" : " (black)");
  return out;
}

// Grid Class

Grid::Grid() {
  for (char f = 'a'; f <= 'h'; f++) {
    for (char r = '1'; r <= '8'; r++) {
      if ((f + r) % 2)
        theGrid[string() + f + r] = Square(f, r, WHITE);
      else
        theGrid[string() + f + r] = Square(f, r, BLACK);
    }
  }
  std::cout << theGrid["h1"];  // h1 should be white
}

void Grid::addPiece(Piece *piece, std::string pos) {
  delete theGrid[pos].piece;  // in case a piece is here
  theGrid[pos].piece = piece;
}

void Grid::removePiece(std::string pos) {
  delete theGrid[pos].piece;
  theGrid[pos].piece = nullptr;
}

std::ostream &operator<<(std::ostream &out, const Grid &g) {}