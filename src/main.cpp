#pragma once
#include <random>
#include "../inc/Header.h"
#include "../inc/Score.h"
#include "../inc/RandCoord.h"
#include "../inc/Map.h"

int main()
{
	uint32_t ret = 0;
	Score    score;
	bool flagEXIT = false;
	eAction eACT  = eAction::EMPTY;

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
					switch( input() )    // Нажатие вверх, вниз, влево, вправо  
					{
					case eAction::UP:    //std::cout << "UP"    << std::endl;
						map.setSnake(triangleUP);
						break;
					case eAction::DOWN:  //std::cout << "DOWN"  << std::endl;
						map.setSnake(triangleDOWN);
						break;
					case eAction::LEFT:  //std::cout << "LEFT"  << std::endl;
						map.setSnake(triangleLEFT);
						break;
					case eAction::RIGHT: //std::cout << "RIGHT" << std::endl;
						map.setSnake(triangleRIGHT);
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
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	
	//Setup();
	//while(!gameOver)
	//{
	//	Draw();
  //  input();
	//	Logic();
	//	this_thread::sleep_for(chrono::milliseconds(delay));
	//}

	// Запись рекорда в файл
	if( score.compare() )
		score.write();
	
	thInput.join();
	return 0;
}