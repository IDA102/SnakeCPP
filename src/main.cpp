#include "Header.h"

int delay=100;

int main()
{
	cout<<"Do you want start the game?"<<endl;
	system("pause");

	Setup();
	while(!gameOver)
	{
		Draw();
		Input();
		Logic();
		this_thread::sleep_for(chrono::milliseconds(delay));
	}

	if(score>bestScore)
	{
		ofstream fileBest("BestScore.txt");
		fileBest<<score;	
		fileBest.close();
	}
	
	return 0;
}