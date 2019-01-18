#include "grid.h"
#include <iostream>
#include <string>
#include "bishop.h"
#include "colour.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "piece.h"
#include "queen.h"
#include "rook.h"

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
  // std::cout << *(theGrid["h1"]) << std::endl;  // h1 should be white
}

std::map<std::string, std::unique_ptr<Square>> &Grid::getTheGrid() {
  return theGrid;
}

void Grid::addPiece(Piece *thePiece, std::string pos) {
  theGrid[pos]->setPiece(thePiece);
}

void Grid::removePiece(std::string pos) {
  if (theGrid[pos]->piece) delete theGrid[pos]->piece;
  theGrid[pos]->piece = nullptr;
}

// assumes theGrid.at(dst) has no piece
void Grid::movePiece(std::string src, std::string dst) {
  theGrid.at(dst)->piece = theGrid.at(src)->piece;
  theGrid.at(src)->piece = nullptr;
}

void Grid::playMove(std::string src, std::string dst, std::string ep) {
  Piece *thePiece = theGrid.at(src)->piece;

  removePiece(dst.substr(0, 2));
  if (dynamic_cast<Pawn *>(thePiece)) {
    if (dst[1] == '1') {
      removePiece(src);
      switch (dst[2]) {
        case 'r':
          addPiece(new Rook(Colour::BLACK), dst.substr(0, 2));
          break;
        case 'b':
          addPiece(new Bishop(Colour::BLACK), dst.substr(0, 2));
          break;
        case 'n':
          addPiece(new Knight(Colour::BLACK), dst.substr(0, 2));
          break;
        case 'q':
          addPiece(new Queen(Colour::BLACK), dst.substr(0, 2));
          break;
      }
    } else if (dst[1] == '8') {
      removePiece(src);
      switch (dst[2]) {
        case 'r':
          addPiece(new Rook(Colour::WHITE), dst.substr(0, 2));
          break;
        case 'b':
          addPiece(new Bishop(Colour::WHITE), dst.substr(0, 2));
          break;
        case 'n':
          addPiece(new Knight(Colour::WHITE), dst.substr(0, 2));
          break;
        case 'q':
          addPiece(new Queen(Colour::WHITE), dst.substr(0, 2));
          break;
      }
    } else if (dst == ep) {
      removePiece(std::string() + dst[0] + src[1]);
      movePiece(src, dst);
    } else {
      movePiece(src, dst);
    }
  } else if (dynamic_cast<King *>(thePiece)) {
    if (src == "e1") {
      if (dst == "g1") {
        movePiece(src, dst);
        movePiece("h1", "f1");
      } else if (dst == "c1") {
        movePiece(src, dst);
        movePiece("a1", "d1");
      }
    } else if (src == "e8") {
      if (dst == "g8") {
        movePiece(src, dst);
        movePiece("h8", "f8");
      } else if (dst == "c8") {
        movePiece(src, dst);
        movePiece("a8", "d8");
      }
    } else {
      movePiece(src, dst);
    }
  } else {
    movePiece(src, dst);
  }
}

std::ostream &operator<<(std::ostream &out, const Grid &g) {
  out << "-----------------" << std::endl;
  for (char f = '8'; f >= '1'; f--) {
    out << "|";
    for (char r = 'a'; r <= 'h'; r++) {
      out << g.theGrid.at(std::string() + r + f)->nameShort() << "|";
    }
    out << std::endl;
    out << "-----------------" << std::endl;
  }
  return out;
}
