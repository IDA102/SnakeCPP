#pragma once
//#include "Figure.h"
#include "Apple.h"
#include "Snake.h"
#include <Windows.h>
#include <iostream>

class Map : public RandCoord
{
private:
  uint32_t height = 20;                        // ������
  uint32_t width  = 60;                        // ������
  std::vector<std::vector<unsigned char>> map; // �����
  void frame();
public:
  //Map(preMAP);

  Apple apple;
  Snake snake;

  Map();
  ~Map();
  void drawApple();
  void drawSnake();
};

//Map::Map  ( preMAP pm ){}
Map::Map() : RandCoord(width, height), apple(width, height)
{
  // ����������� ����� ��� �����. // ������� ������������� ��� map-�� ���
  map = std::move(std::vector<std::vector<unsigned char>>{height + 2, std::vector<unsigned char>(width + 2, ' ')});
  apple = std::move(Apple(width, height));
  this->frame();
};
Map::~Map() {}
void Map::frame()
{
  // ���� �����
  map[0][0] = angleTopLeft;
  map[0][width + 1] = angleTopRight;
  map[height + 1][0] = angleBottomLeft;
  map[height + 1][width + 1] = angleBottomRight;
  // TOP LINE
  for (size_t i = 1; i < width + 1; i++) { map[0][i] = lineHORIZONTAL; }
  //MID LINE
  for (size_t i = 1; i < height + 1; i++) { map[i][0] = lineVERTICAL; }         // left
  for (size_t i = 1; i < height + 1; i++) { map[i][width + 1] = lineVERTICAL; } // right
  // DOWN LINE
  for (size_t i = 1; i < width + 1; i++) { map[height + 1][i] = lineHORIZONTAL; }
  // ���������
  for (size_t i = 0; i < height + 2; i++)
  {
    for (size_t j = 0; j < width + 2; j++) { std::cout << map[i][j]; }
    std::cout << std::endl;
  }
}

void Map::drawApple()
{
  uint32_t x, y;
  std::pair<uint32_t, uint32_t> coord;
  // ��������� �������
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO console{ DWORD(100), false }; // DWORD  dwSize , BOOL   bVisible
  SetConsoleCursorInfo(hConsole, &console);         // ����������� ������������ ������� �� 100

  // ������� ���������� �������
  {
    coord = apple.getApple(); // �������� ���������� �������� �������.
    y = coord.second;
    x = coord.first;
    COORD  position{ static_cast<short>(x),static_cast<short>(y) };
    SetConsoleCursorPosition(hConsole, position);
    std::cout << char(' ');
  }

  // ����� ���������� �������
  coord = apple.get(); // �������� ���������� ������ �������.
  x = coord.first;
  y = coord.second;
  // ���������� ���������� ������� � ����� �����.

  // ������������.
  COORD  position{ static_cast<short>(x),static_cast<short>(y) };
  SetConsoleCursorPosition(hConsole, position);
  std::cout << char(circle);
};

void Map::drawSnake()
{
  // ��������� �������
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO console{ DWORD(100), false };              // DWORD  dwSize , BOOL   bVisible.
  SetConsoleCursorInfo(hConsole, &console);                      // ����������� ������������ ������� �� 100.

  // ������� ������ � ������ �������������� ������������ �����
  {
    std::pair<uint32_t, uint32_t> coord = snake.getHeadSnake();  // �������� ������� ���������� ������.
    COORD  position{ static_cast<short>(coord.first),static_cast<short>(coord.second) };
    SetConsoleCursorPosition(hConsole, position);

    // ������ ������ �� ����
    if (snake.flag)
    { 
      std::cout << char(snake.qq);
      coord      = snake.getCoordAfterTriangle();                // ���������� ����� ����.
      position.X = coord.first;
      position.Y = coord.second;
      snake.flag = false;
    }
    else
    {
      // ������ ������ �� ����� // ����������� ����� ���� 
      switch (snake.getDirection())
      {
        case eAction::UP:
          std::cout << char(lineVERTICAL);
          position.Y = static_cast<short>(--coord.second);
          break;
        case eAction::DOWN:
          std::cout << char(lineVERTICAL);
          position.Y = static_cast<short>(++coord.second);
          break;
        case eAction::LEFT:
          std::cout << char(lineHORIZONTAL);
          position.X = static_cast<short>(--coord.first);
          break;
        case eAction::RIGHT:
          std::cout << char(lineHORIZONTAL);
          position.X = static_cast<short>(++coord.first);
          break;
        default:
          break;
      }
    }
    // ��������� ������
    SetConsoleCursorPosition(hConsole, position);
    std::cout << char(snake.getType());
    snake.setCoord(coord);
  }
};