#include "controller.h"
#include "model.h"
#include "view.h"

#include "CLIController.h"
#include "CLIView.h"
#include "gameState.h"

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  /*
  vector<string> args;
  for (int i = 1; i < argc; ++i) args.emplace_back(argv[i]);
  for (auto& a : args) cout << a << endl;
  */
  GameState game;
  std::cout << game << std::endl;
}
