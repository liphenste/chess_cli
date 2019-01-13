#include "controller.h"
#include "model.h"
#include "view.h"

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  vector<string> args;
  for (int i = 1; i < argc; ++i) args.emplace_back(argv[i]);
  for (auto& a : args) cout << a << endl;
  return 0;
}
