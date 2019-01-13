#ifndef GRID_H
#define GRID_H

#include <map>

class Grid {
  class Square;
  std::map<std::string, Square> theGrid;

 public:
  Grid();
  void addPiece(Piece *s, std::string pos);
  void removePiece(std::string pos);

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
