#ifndef GRID_H
#define GRID_H

#include <map>
#include <memory>
#include "piece.h"
#include "square.h"

class Grid {
  std::map<std::string, std::unique_ptr<Square>> theGrid;

 public:
  Grid();
  std::map<std::string, std::unique_ptr<Square>> &getTheGrid();
  void addPiece(Piece *s, std::string pos);
  void removePiece(std::string pos);
  void movePiece(std::string src, std::string dst);
  void playMove(std::string src, std::string dst, std::string ep);
  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
