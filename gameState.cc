#include "gameState.h"

void GameState::emptyState() { Grid::Grid(); }

void GameState::startState() {
  Grid::Grid();

  Grid::addPiece(new Rook(WHITE), "a1");
  Grid::addPiece(new Knight(WHITE), "b1");
  Grid::addPiece(new Bishop(WHITE), "c1");
  Grid::addPiece(new Queen(WHITE), "d1");
  Grid::addPiece(new King(WHITE), "e1");
  Grid::addPiece(new Bishop(WHITE), "f1");
  Grid::addPiece(new Knight(WHITE), "g1");
  Grid::addPiece(new Rook(WHITE), "h1");
  for (char f = 'a'; f <= 'h'; f++) Grid::addPiece(new Pawn(WHITE), f + "2");

  Grid::addPiece(new Rook(BLACK), "a8");
  Grid::addPiece(new Knight(BLACK), "b8");
  Grid::addPiece(new Bishop(BLACK), "c8");
  Grid::addPiece(new Queen(BLACK), "d8");
  Grid::addPiece(new King(BLACK), "e8");
  Grid::addPiece(new Bishop(BLACK), "f8");
  Grid::addPiece(new Knight(BLACK), "g8");
  Grid::addPiece(new Rook(BLACK), "h8");
  for (char f = 'a'; f <= 'h'; f++) Grid::addPiece(new Pawn(BLACK), f + "7");
}
