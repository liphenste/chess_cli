#include "stockfish.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <streambuf>

Stockfish::Stockfish(std::string FEN) {
  std::ofstream engineInput;
  engineInput.open("engineInput.temp");
  engineInput << "isready\nposition fen \"" << FEN << "\"\n";
  for (int i = 0; i < 25; i++) engineInput << "go depth 10\n";
  engineInput << "d";
  engineInput.close();

  system(
      "node ../node_modules/stockfish/src/stockfish.js < engineInput.temp > "
      "engineOutput.temp");

  std::ifstream engineOutput("engineOutput.temp");
  std::string outputStr((std::istreambuf_iterator<char>(engineOutput)),
                        std::istreambuf_iterator<char>());

  outputStr = outputStr.substr(outputStr.find("info depth 10"));
  bestMove = outputStr.substr(outputStr.find(" pv ") + 4, 4);
  outputStr = outputStr.substr(outputStr.find("Legal uci moves: ") + 17);

  std::stringstream ss{outputStr};
  std::string legalMove;
  while (ss >> legalMove) {
    legalMoves.push_back(legalMove);
  }
}

// Stockfish::~Stockfish() { system("rm engineInput.temp engineOutput.temp"); }

std::vector<std::string> Stockfish::getLegalMoves() { return legalMoves; }
std::string Stockfish::getBestMove() { return bestMove; }
