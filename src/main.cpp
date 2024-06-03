#pragma once
#include <random>
#include "../inc/Header.h"
#include "../inc/Score.h"
#include "../inc/RandCoord.h"
#include "../inc/Map.h"

int main()
{
  uint32_t ret      = 0;
  Score    score;
  bool     flagEXIT = false;
  eAction  eACT     = eAction::EMPTY;

  ret = menu();
  if     ( ret == 1 ){ system("cls"); presetMAP();     }
  else if( ret == 2 ){ system("cls"); /*inputSIZE();*/ }
  else               {}
  
  system("cls");
  presetSPEED();
  
  system("cls");
  Map map;

  std::thread thInput([&]()
    {
      while(!flagEXIT)
      {
        if(_kbhit())
        {
          switch( input() )    // ������� �����, ����, �����, ������  
          {
          case eAction::UP:    //std::cout << "UP"    << std::endl;
            if ( map.snake.setDirection(eAction::UP) )
            {
              map.snake.setType(triangleUP);
              map.snake.checkAngleDirection(triangleUP);
            }
            break;
          case eAction::DOWN:  //std::cout << "DOWN"  << std::endl;
            if ( map.snake.setDirection(eAction::DOWN) )
            {
              map.snake.setType(triangleDOWN);
              map.snake.checkAngleDirection(triangleDOWN);
            }
            break;
          case eAction::LEFT:  //std::cout << "LEFT"  << std::endl;
            if ( map.snake.setDirection(eAction::LEFT) )
            {
              map.snake.setType(triangleLEFT);
              map.snake.checkAngleDirection(triangleLEFT);
            }
            break;
          case eAction::RIGHT: //std::cout << "RIGHT" << std::endl;
            if ( map.snake.setDirection(eAction::RIGHT) )
            {
              map.snake.setType(triangleRIGHT);
              map.snake.checkAngleDirection(triangleRIGHT);
            }
            break;
          case eAction::STOP:	 //std::cout << "STOP"  << std::endl;
            break;
            //case eAction::ENTER:
              //flagEXIT = true;
            //break;
          default:
            break;
          }
        }
      }
    });

  while (1)
  {
    //map.drawApple();
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    map.drawSnake();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
  
  //Setup();
  //while(!gameOver)
  //{
  //	Draw();
  //  input();
  //	Logic();
  //	this_thread::sleep_for(chrono::milliseconds(delay));
  //}

  // ������ ������� � ����
  if( score.compare() )
    score.write();
  
  thInput.join();
  return 0;
}