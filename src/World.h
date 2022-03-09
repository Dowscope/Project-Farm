#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Tile.h"

class World
{
private:
  const int _startTileAmt = 100;
  std::vector<Tile> _tiles;
public:
  World();
  ~World();
  std::vector<Tile> getTiles() {return _tiles;}
};

#endif