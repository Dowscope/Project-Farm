#include "World.h"

World::World()
{
  for(int y = 0; y < _startTileAmt; y++)
  {
    for(int x = 0; x < _startTileAmt; x++)
    {
      _tiles.push_back(Tile(x, y, 1));
    }
  }
}

World::~World()
{
}