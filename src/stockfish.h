#ifndef STOCKFISH_H
#define STOCKFISH_H

#include <iostream>
#include <vector>

class Stockfish {
  std::vector<std::string> legalMoves;
  std::string bestMove;

 public:
  Stockfish(std::string FEN);
  //~Stockfish();

  std::vector<std::string> getLegalMoves();
  std::string getBestMove();
};

#endif
