#ifndef TILE_H
#define TILE_H

class Tile
{
private:
public:
  Tile(int posX, int posY, int tileType);
  ~Tile();
  
  const int x, y;
  int type;
};


#endif