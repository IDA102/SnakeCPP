//#include "Figure.h"
#include <Windows.h>
#include <iostream>

class Map
{
  private:
    uint32_t height = 20;
    uint32_t width  = 40;
    unsigned char map[20][40];
    void frame();
  public:
	  //Map(preMAP);
    Map();
	  ~Map();
};

//Map::Map  ( preMAP pm ){}
Map::Map (){ this->frame(); };
Map::~Map(){}
void Map::frame()
{
  // ”глы рамки
  map[0][0]                  = angleTopLeft;
  map[0][width - 1]          = angleTopRight;
  map[height - 1][0]         = angleBottomLeft;
  map[height - 1][width - 1] = angleBottomRight; 
  // TOP LINE
  for(size_t i = 1; i < width - 1; i++) { map[0][i]         = lineHORIZONTAL;}
  //MID LINE
  for(size_t i = 1; i < height - 1; i++){ map[i][0]         = lineVERTICAL;  } // left
  for(size_t i = 1; i < height - 1; i++){ map[i][width - 1] = lineVERTICAL;  } // right
  // DOWN LINE
  for(size_t i = 1; i < width - 1; i++){  map[height - 1][i]= lineHORIZONTAL;}
  // ќтрисовка
  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++){ std::cout << map[i][j]; }
    std::cout << std::endl;
  }
}