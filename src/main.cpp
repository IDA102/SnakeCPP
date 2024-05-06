#include "../inc/Header.h"
#include "../inc/Score.h"

//size_t

int main()
{
	Score score;

	testMENU();
	//Setup();
	//while(!gameOver)
	//{
	//	Draw();
	//	Input();
	//	Logic();
	//	this_thread::sleep_for(chrono::milliseconds(delay));
	//}

	if( score.compare() )
		score.write();
	
	return 0;
}