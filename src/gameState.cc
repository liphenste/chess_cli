#include "gameState.h"
#include <sstream>
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

GameState::GameState()
    : turn{Colour::WHITE},
      canWhiteCastleShort{true},
      canWhiteCastleLong{true},
      canBlackCastleShort{true},
      canBlackCastleLong{true},
      enPassant{"-"},
      halfMoveClock{0},
      move{1} {}

GameState::~GameState() {
  for (char f = 'a'; f <= 'h'; f++) {
    for (char r = '1'; r <= '8'; r++) {
      position.removePiece(std::string() + f + r);
    }
  }
}

void GameState::emptyState() {
  position = Grid();
  turn = Colour::WHITE;
  canWhiteCastleShort = true;
  canWhiteCastleLong = true;
  canBlackCastleShort = true;
  canBlackCastleLong = true;
  enPassant = "-";
  halfMoveClock = 0;
  move = 1;
}

void GameState::startState() {
  emptyState();
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

const int halfMovesToDraw = 100;

std::string GameState::halfMovesTilDraw() const {
  int tilDraw = halfMovesToDraw - halfMoveClock;
  return std::to_string(tilDraw / 2) + (tilDraw % 2 == 1 ? ".5" : "");
}

// ie. 1. e4 FEN: rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1
void GameState::setFEN(std::string fen) {
  emptyState();
  std::stringstream ss{fen};
  std::string s;
  ss >> s;
  int i = 0;
  char f = 'a';
  char r = '8';
  while (s[i]) {
    // std::cout << i << " " << std::string() + s[i] + f + r << std::endl;
    switch (s[i]) {
      case '/':
        f = 'a' - 1;
        r--;
        break;
      case 'r':
        position.addPiece(new Rook(Colour::BLACK), std::string() + f + r);
        break;
      case 'R':
        position.addPiece(new Rook(Colour::WHITE), std::string() + f + r);
        break;
      case 'n':
        position.addPiece(new Knight(Colour::BLACK), std::string() + f + r);
        break;
      case 'N':
        position.addPiece(new Knight(Colour::WHITE), std::string() + f + r);
        break;
      case 'b':
        position.addPiece(new Bishop(Colour::BLACK), std::string() + f + r);
        break;
      case 'B':
        position.addPiece(new Bishop(Colour::WHITE), std::string() + f + r);
        break;
      case 'q':
        position.addPiece(new Queen(Colour::BLACK), std::string() + f + r);
        break;
      case 'Q':
        position.addPiece(new Queen(Colour::WHITE), std::string() + f + r);
        break;
      case 'k':
        position.addPiece(new King(Colour::BLACK), std::string() + f + r);
        break;
      case 'K':
        position.addPiece(new King(Colour::WHITE), std::string() + f + r);
        break;
      case 'p':
        position.addPiece(new Pawn(Colour::BLACK), std::string() + f + r);
        break;
      case 'P':
        position.addPiece(new Pawn(Colour::WHITE), std::string() + f + r);
        break;
      default:                          // i must be a number in [1,8]
        int numEmpty = s[i] - '0' - 1;  // -1 for the f++ in outer while
        while (numEmpty) {
          f++;
          numEmpty--;
        }
    }
    f++;
    i++;
  }
  ss >> s;
  turn = s == "w" ? Colour::WHITE : Colour::BLACK;
  ss >> s;
  canWhiteCastleShort = s.find('K') != std::string::npos ? true : false;
  canWhiteCastleLong = s.find('Q') != std::string::npos ? true : false;
  canBlackCastleShort = s.find('k') != std::string::npos ? true : false;
  canBlackCastleLong = s.find('q') != std::string::npos ? true : false;
  ss >> s;
  enPassant = s;
  int n;
  ss >> n;
  halfMoveClock = n;
  ss >> n;
  move = n;
}

// ie. 1. e4 FEN: rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1
std::string GameState::getFEN() {
  std::stringstream ss;
  for (char f = '8'; f >= '1'; f--) {
    char numEmpty = '0';
    for (char r = 'a'; r <= 'h'; r++) {
      char curChar =
          position.getTheGrid().at(std::string() + r + f)->nameShort()[0];
      if (curChar == ' ') {
        numEmpty++;
      } else {
        if (numEmpty != '0') {
          ss << numEmpty;
          numEmpty = '0';
        }
        ss << curChar;
      }
    }
    if (numEmpty != '0') {
      ss << numEmpty;
      numEmpty = '0';
    }
    if (f != '1') ss << '/';
  }
  ss << ' ';
  ss << (turn == Colour::WHITE ? 'w' : 'b');
  ss << ' ';
  ss << (canWhiteCastleShort ? "K" : "");
  ss << (canWhiteCastleLong ? "Q" : "");
  ss << (canBlackCastleShort ? "k" : "");
  ss << (canBlackCastleLong ? "q" : "");
  if (ss.str().back() == ' ') ss << '-';  // if no castles are legal
  ss << ' ';
  ss << enPassant;
  ss << ' ';
  ss << halfMoveClock;
  ss << ' ';
  ss << move;
  std::string FEN = ss.str();
  return FEN;
}

void GameState::playMove(std::string theMove) {
  std::string src = (theMove.substr(0, 2));
  std::string dst = (theMove.substr(2));
  std::string ep = enPassant;

  if (turn == Colour::BLACK) move++;
  turn = turn == Colour::WHITE ? Colour::BLACK : Colour::WHITE;
  enPassant = "-";
  if (dynamic_cast<Pawn *>(position.getTheGrid().at(src)->piece)) {
    halfMoveClock = 0;  // pawn advance
    if (src[1] == '2' && dst[1] == '4')
      enPassant = std::string() + src[0] + '3';
    else if (src[1] == '7' && dst[1] == '5')
      enPassant = std::string() + src[0] + '6';
  }
  if (position.getTheGrid().at(dst.substr(0, 2))->piece)
    halfMoveClock = 0;  // piece capture

  if (dynamic_cast<King *>(position.getTheGrid().at(src)->piece)) {
    if (src == "e1") {
      if (dst == "g1") {
        canWhiteCastleShort = false;
      } else if (dst == "c1") {
        canWhiteCastleLong = false;
      }
    } else if (src == "e8") {
      if (dst == "g8") {
        canBlackCastleShort = false;
      } else if (dst == "c8") {
        canBlackCastleLong = false;
      }
    }
  }

  position.playMove(src, dst, ep);
}

void GameState::printPosition() { std::cout << position; }

std::ostream &operator<<(std::ostream &out, const GameState &g) {
  out << "Turn: " << (g.turn == Colour::WHITE ? "White" : "Black") << std::endl;
  out << "Move: " << g.move << std::endl;
  out << "Moves until 50-move draw: " << g.halfMovesTilDraw() << std::endl;
  out << "En passant: " << g.enPassant << std::endl;
  out << std::boolalpha;
  out << "White 0-0/0-0-0: " << g.canWhiteCastleShort << '/'
      << g.canWhiteCastleLong << std::endl;
  out << "Black 0-0/0-0-0: " << g.canBlackCastleShort << '/'
      << g.canBlackCastleLong << std::endl;
  out << g.position << std::endl;
  return out;
}
