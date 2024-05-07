#include "../inc/Header.h"
#include "../inc/Score.h"
#include "../inc/Map.h"

//size_t

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
	
	return 0;
}