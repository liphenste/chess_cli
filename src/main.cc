#include "controller.h"
#include "model.h"
#include "view.h"

#include "CLIController.h"
#include "CLIView.h"
#include "gameState.h"

#include "stockfish.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  GameState game;
  string input;

  cout << "Welcome to chess_cli!" << endl;
  cout << endl;

  bool vsStockfish = false;
  cout << "Play with Stockfish? (y/n) (Otherwise game will play as 2 player): ";
  if (cin >> input && input == "y") vsStockfish = true;

  bool visualDisplay = false;
  cout << "Visual display? (y/n): ";
  if (cin >> input && input == "y") visualDisplay = true;

  cout << "Load FEN? (y/n): ";
  if (cin >> input && input == "y") {
    cout << "Paste FEN." << endl;
    cout << "i.e. \"rnbqkb1r/1p2pppp/p2p1n2/8/3NP3/2N5/PPP2PPP/R1BQKB1R w KQkq "
            "- 0 6\""
         << endl;
    cin.ignore();
    getline(cin, input);
    game.setFEN(input);
  } else {
    game.startState();
  }

  cout << endl;
  cout << game;
  cout << "\"sf\": Stockfish plays your move." << endl;
  cout << "\"fen\": prints the FEN of this position." << endl;
  cout << "\"d\" prints detailed information of this position." << endl;
  cout << "\"q\": quits the program." << endl;
  cout << "\"help\": repeats these commands." << endl;
  cout << endl;
  cout << "Enter move (i.e. 'e2e4', 'e1g1' (short castle), 'c7c8q' (queen "
          "promotion))"
       << endl;
  while (!cin.fail()) {
    try {
      Stockfish sf(game.getFEN());
      std::vector<std::string> legalMoves = sf.getLegalMoves();

      cout << "> ";
      cin >> input;
      if (input == "q") break;

      if (find(legalMoves.begin(), legalMoves.end(), input) !=
              legalMoves.end() ||
          input == "sf") {
        if (input == "sf") {
          Stockfish sf(game.getFEN());
          game.playMove(sf.getBestMove());
          if (visualDisplay) game.printPosition();
          cout << sf.getBestMove() << endl;
        } else {
          game.playMove(input);
        }
        if (vsStockfish) {
          Stockfish sf(game.getFEN());
          game.playMove(sf.getBestMove());
          if (visualDisplay) game.printPosition();
          cout << "Stockfish plays " << sf.getBestMove() << endl;
        } else {
          if (visualDisplay) game.printPosition();
        }
      } else if (input == "fen") {
        cout << game.getFEN() << endl;
      } else if (input == "help") {
        cout << "\"sf\": Stockfish plays your move." << endl;
        cout << "\"fen\": prints the FEN of this position." << endl;
        cout << "\"d\" prints detailed information of this position." << endl;
        cout << "\"q\": quits the program." << endl;
        cout << "\"help\": repeats these instructions." << endl;
        cout << endl;
        cout
            << "Enter move (i.e. 'e2e4', 'e1g1' (short castle), 'c7c8q' (queen "
               "promotion))"
            << endl;
      } else if (input == "d") {
        cout << game;
      } else {
        cout << "(Invalid move)" << endl;
      }
    } catch (std::out_of_range&) {
      std::cout << "Game Over" << std::endl;
      return 0;
    }
  }
}
