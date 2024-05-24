#pragma once
//#include "Figure.h"
#include "Apple.h"
#include "Snake.h"
#include <Windows.h>
#include <iostream>

class Map : public RandCoord
{
  private:
    Apple apple;
    Snake snake;
    uint32_t height = 20;                        // Высота
    uint32_t width  = 80;                        // Ширина
    std::vector<std::vector<unsigned char>> map; // Карта
    void frame();
  public:
    //Map(preMAP);
    Map();
    ~Map();
    void drawApple();
    void drawSnake();
};

//Map::Map  ( preMAP pm ){}
Map::Map () : RandCoord(width, height), apple(width, height)
{
// Резервируем место под карту. // Ленивую инициализацию для map-хз как
  map   = std::move(std::vector<std::vector<unsigned char>>{height, std::vector<unsigned char>(width,' ')});
  apple = std::move(Apple(width, height));
  this->frame(); 
};
Map::~Map(){}
void Map::frame()
{
  // Углы рамки
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
  // Отрисовка
  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++){ std::cout << map[i][j]; }
    std::cout << std::endl;
  }
}

void Map::drawApple()
{
  uint32_t x,y;
  std::pair<uint32_t, uint32_t> coord;
  // Параметры курсора
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO console{ DWORD(100), false }; // DWORD  dwSize , BOOL   bVisible
  SetConsoleCursorInfo(hConsole, &console);         // Выкручиваем прозрачность курсора на 100
  
  // Стираем предыдущее тыблоко
  {
    coord = apple.getApple(); // Получаем координаты текущего тыблока.
    x = coord.first;
    y = coord.second;
    COORD  position{static_cast<short>(x),static_cast<short>(y)};
    SetConsoleCursorPosition(hConsole, position);
    std::cout << char(' ');
  }

  // Новые координаты тыблока
  coord = apple.get(); // Получаем координаты нового тыблока.
  x = coord.first;
  y = coord.second;
  // Записываем координаты тыблока в фрейм карты.
  
  // Отрисовываем.
  COORD  position{ static_cast<short>(y),static_cast<short>(x) };
  SetConsoleCursorPosition(hConsole, position);
  std::cout << char(circle);
};

void Map::drawSnake()
{
  uint32_t y;
  uint32_t x;
  std::pair<uint32_t, uint32_t> coord;
  // Параметры курсора
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO console{ DWORD(100), false }; // DWORD  dwSize , BOOL   bVisible
  SetConsoleCursorInfo(hConsole, &console);         // Выкручиваем прозрачность курсора на 100

  // Стираем голову и рисуем горизонтальную вертикальную линию
  {
    coord = snake.getHeadSnake(); // Получаем текущие координаты головы.
    std::tie(y, x) = coord;
    COORD  position{ static_cast<short>(y),static_cast<short>(x) };
    SetConsoleCursorPosition(hConsole, position);
    // Замена головы на линию
    /*
    switch()
    {
      case
        break;
      case
        break;
      case
        break;
      default:
       break;
    }
    */
    std::cout << char(lineHORIZONTAL);
    // Отрисовка головы
    x++;
    position.X = static_cast<short>(x);
    SetConsoleCursorPosition(hConsole, position);
    std::cout << char(triangleRIGHT);
    snake.setCoord(std::pair<uint32_t, uint32_t>{x, y});
  }
};