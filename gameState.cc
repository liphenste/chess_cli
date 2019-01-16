#include "gameState.h"

#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

GameState::GameState()
    : turn{Colour::WHITE}, move{1}, whiteCastled{false}, blackCastled{false} {
  startState();
}

void GameState::startState() {
  position.addPiece(new Rook(Colour::WHITE), "a1");
  position.addPiece(new Knight(Colour::WHITE), "b1");
  position.addPiece(new Bishop(Colour::WHITE), "c1");
  position.addPiece(new Queen(Colour::WHITE), "d1");
  position.addPiece(new King(Colour::WHITE), "e1");
  position.addPiece(new Bishop(Colour::WHITE), "f1");
  position.addPiece(new Knight(Colour::WHITE), "g1");
  position.addPiece(new Rook(Colour::WHITE), "h1");
  for (char f = 'a'; f <= 'h'; f++)
    position.addPiece(new Pawn(Colour::WHITE), (std::string() + f + '2'));

  position.addPiece(new Rook(Colour::BLACK), "a8");
  position.addPiece(new Knight(Colour::BLACK), "b8");
  position.addPiece(new Bishop(Colour::BLACK), "c8");
  position.addPiece(new Queen(Colour::BLACK), "d8");
  position.addPiece(new King(Colour::BLACK), "e8");
  position.addPiece(new Bishop(Colour::BLACK), "f8");
  position.addPiece(new Knight(Colour::BLACK), "g8");
  position.addPiece(new Rook(Colour::BLACK), "h8");
  for (char f = 'a'; f <= 'h'; f++)
    position.addPiece(new Pawn(Colour::BLACK), (std::string() + f + '7'));
}

GameState::~GameState() {
  for (char f = 'a'; f <= 'h'; f++) {
    for (char r = '1'; r <= '8'; r++) {
      position.removePiece(std::string() + f + r);
    }
  }
}

std::ostream &operator<<(std::ostream &out, const GameState &g) {
  out << "Turn: " << (g.turn == Colour::WHITE ? "White" : "Black") << std::endl;
  out << "Move: " << g.move << std::endl;
  out << "White 0-0/0-0-0: " << g.whiteCastled << std::endl;
  out << "Black 0-0/0-0-0: " << g.blackCastled << std::endl;
  out << g.position << std::endl;
  return out;
}
