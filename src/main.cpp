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

	ret = menu();
	if     ( ret == 1 ){ system("cls"); presetMAP();     }
	else if( ret == 2 ){ system("cls"); /*inputSIZE();*/ }
	else               {}
	
	system("cls");
	presetSPEED();
	
	system("cls");
	Map map;
	map.drawApple();
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
	
	return 0;
}