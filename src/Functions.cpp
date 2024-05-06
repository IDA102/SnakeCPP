#include "../inc/Header.h"
#include "../inc/Rand.h"

string bufferDraw;
bool gameOver;
size_t score;	
const int width=40;
const int height=20;
int targetX,targetY;
int bestScore;

struct Snake
{
	int x,y;
};
Snake Head;

Snake snakeTail[100];
size_t countTail=0;

enum eAction{STOP=0,LEFT,RIGHT,UP,DOWN};
eAction act;

//functions
void Setup()
{
	system("cls");
	//std::cout << "SELECT OR ENTER MAP SIZE" << std::endl << "1 - SELECT" << std::endl << "2 - ENTER";
	//system("pause");
	//countTail=0;
	//gameOver=false;
	//score=0;
	//Head.x=width/2;
	//Head.y=height/2;
	//act=STOP;

	//srand(time(0)); //избавляемся от псевдорандомных чисел
	//targetX=rand() % (width-1);
	//targetY=rand() % (height-1);
}

void Draw()
{
	ifstream fileBest("bestScore.txt");
	fileBest>>bestScore;
	fileBest.close();

	system("cls");
	bufferDraw.clear();

	for(int i=0;i<=width;i++)//top
		bufferDraw+="#";

	bufferDraw+="\tScore = ";
	bufferDraw+=to_string(score);
	bufferDraw+="\tBestScore = ";
	bufferDraw+=to_string(bestScore);

	for(int i=0;i<height;i++)
	{
		bufferDraw+="\n";

		for(int j=0;j<width;j++)
		{
			if(j==0 || j==(width-1))
				bufferDraw+="#";

			if(i==Head.y && j==Head.x)
				bufferDraw+="0";
			else if(i==targetY && j==targetX)
				bufferDraw+="@";
			else
			{
				bool printTail=true;
				for(int k=0;k<countTail;k++)
				{
					if(snakeTail[k].y == i && snakeTail[k].x == j)
					{
						bufferDraw+="o";
						printTail=false;
						break;
					}
				}

				if(printTail)
					bufferDraw+=" ";
			}
				
		}
	}

	bufferDraw+="\n";
	for(int i=0;i<=width;i++)//bottom
		bufferDraw+="#";

	cout<<bufferDraw<<endl;
}

void Input()
{
	if(_kbhit()) //если нажата клавиша
	{
		switch(_getch())
		{
			case 'a':
				act=LEFT;
				break;
			case 'd':
				act=RIGHT;
				break;
			case 'w':
				act=UP;
				break;
			case 's':
				act=DOWN;
				break;
			case 'x':
				gameOver=true;
				break;
		}
	}
}

void Logic()
{
	Snake prev=snakeTail[0]; //сохраняем предыдущий нулевой эл-т
	Snake tmp;
	snakeTail[0]=Head; //записываем изменившийся Head
	for(int i=1;i<countTail;i++) // цикл начинает работу с countTail>=2, добавляем в Tail предыдущий Head, сдвигая элементы 
	{
		tmp=snakeTail[i];
		snakeTail[i]=prev;
		prev=tmp;
	}

	//Actions
	if(act == RIGHT)
		Head.x+=1;
	else if(act==LEFT)
		Head.x-=1;
	else if(act==UP)
		Head.y-=1;
	else if(act==DOWN)
		Head.y+=1;



	//through
	if(Head.x == -1 || Head.x == width - 1 || Head.y == -1 || Head.y == height)
	{
		if(act == UP)
			Head.y = height;
		else if(act == DOWN)
			Head.y = 0;
		else  if(act == LEFT)
			Head.x = width - 2;
		else if(act == RIGHT)
			Head.x = 0;
	}

	//break
	for(int i = 0; i < countTail; i++)
	{
		if(Head.x == snakeTail[i].x && Head.y == snakeTail[i].y)
		{
			bool choice=false; 
			//Draw();
			//act=STOP;
			cout<<endl<<"GAME OVER! Press r for restart, or press x for exit...";
			while(!choice)
			{
				if(_kbhit())
				{
					switch(_getch())
					{
						case 'r':
						Setup();
						choice = true;
						break;
						case 'x':
						gameOver = true;
						choice = true;
						break;
					}
				}
			}
		}
	}


	//taked target
	if(Head.x == targetX && Head.y == targetY)
	{
		srand(time(0)); //избавляемся от псевдорандомных чисел
		targetX=rand() % (width-1);
		targetY=rand() % (height-1);

		++score;

	//add tail
		++countTail;

	}
}


void testMENU()
{
	/*
	std::cout << char(triangleUP)      << std::endl;
	std::cout << char(triangleRIGHT)   << std::endl;
	std::cout << char(triangleDOWN)    << std::endl;
	std::cout << char(triangleLEFT)    << std::endl;
	std::cout << char(circle)          << std::endl;
	std::cout << char(lineVERTICAL)    << std::endl;
	std::cout << char(lineHORIZONTAL)  << std::endl;
	std::cout << char(angleBottomRight)<< std::endl;
	std::cout << char(angleTopRight)   << std::endl;
	std::cout << char(angleBottomLeft) << std::endl;
	std::cout << char(angleTopLeft)    << std::endl;
	*/
	/*
	unsigned char MAP[SMALL_height][SMALL_width];
	MAP[0][0]                          = angleTopLeft;
	MAP[0][SMALL_width-1]              = angleTopRight;
	MAP[SMALL_height-1][0]             = angleBottomLeft;
	MAP[SMALL_height-1][SMALL_width-1] = angleBottomRight;
	//TOP LINE
	for (size_t i = 1; i < SMALL_width-1; i++)
	{ MAP[0][i] = lineHORIZONTAL; }
	for (size_t i = 0; i < SMALL_width; i++){	std::cout << MAP[0][i];	}
	std::cout << std::endl;

	//MID LINE
	for (size_t i = 1; i < SMALL_height-1; i++)
	{
		MAP[i][0] = lineVERTICAL;
	}
	for (size_t i = 1; i < SMALL_height-1; i++)
	{
		MAP[i][SMALL_width-1] = lineVERTICAL;
	}

	for (size_t i = 1; i < SMALL_height-1; i++)
	{
		for (size_t j = 0; j < SMALL_width; j++)
		{
			std::cout << MAP[i][j];
		}
		std::cout << endl;
	}
	 
	// DOWN LINE
	for (size_t i = 1; i < SMALL_width - 1; i++)
	{
		MAP[SMALL_height-1][i] = lineHORIZONTAL;
	}
	for (size_t i = 0; i < SMALL_width; i++) { std::cout << MAP[SMALL_height-1][i]; }
	std::cout << std::endl;
	*/
	// MENU 1
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "SELECT OR ENTER MAP SIZE" << std::endl;
	std::cout << " SELECT" << std::endl;
  std::cout << " ENTER"  << std::endl;
	
	//Анимация выбора меню
	COORD position1 = { 0,2 };
	COORD position2 = { 0,3 };
	COORD* pPosition = &position1;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//DWORD  dwSize;
	//BOOL   bVisible;
	CONSOLE_CURSOR_INFO gg{ DWORD(100), false };
	SetConsoleCursorInfo(hConsole, &gg);
	while (1)
	{
		SetConsoleCursorPosition(hConsole, *pPosition);
		std::cout << char(menuG_1);
		this_thread::sleep_for(chrono::milliseconds(250));
		SetConsoleCursorPosition(hConsole, *pPosition);
		std::cout << char(menuG_2);
		this_thread::sleep_for(chrono::milliseconds(250));
		if (_kbhit()) //если нажата клавиша
		{
			switch (_getch())
			{
			case 'w':
				SetConsoleCursorPosition(hConsole, *pPosition);
				std::cout << ' ';
				pPosition = &position1;
				break;
			case 's':
				SetConsoleCursorPosition(hConsole, *pPosition);
				std::cout << ' ';
				pPosition = &position2;
				break;
			}
		}
	}
	

 }