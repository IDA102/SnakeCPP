#include "../inc/Header.h"
#include "../inc/Rand.h"

std::string bufferDraw;
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
eAction act;

//functions
void Setup()
{
	system("cls");
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
	std::ifstream fileBest("bestScore.txt");
	fileBest>>bestScore;
	fileBest.close();

	system("cls");
	bufferDraw.clear();

	for(int i=0;i<=width;i++)//top
		bufferDraw+="#";

	bufferDraw+="\tScore = ";
	bufferDraw+=std::to_string(score);
	bufferDraw+="\tBestScore = ";
	bufferDraw+=std::to_string(bestScore);

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

	std::cout<<bufferDraw<<std::endl;
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
	if(act == eAction::RIGHT)
		Head.x+=1;
	else if(act == eAction::LEFT)
		Head.x-=1;
	else if(act == eAction::UP)
		Head.y-=1;
	else if(act == eAction::DOWN)
		Head.y+=1;



	//through
	if(Head.x == -1 || Head.x == width - 1 || Head.y == -1 || Head.y == height)
	{
		if(act == eAction::UP)
			Head.y = height;
		else if(act == eAction::DOWN)
			Head.y = 0;
		else  if(act == eAction::LEFT)
			Head.x = width - 2;
		else if(act == eAction::RIGHT)
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
			std::cout<<std::endl<<"GAME OVER! Press r for restart, or press x for exit...";
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

eAction input()
{
	switch(_getwch())
	{
// Клавиша "ENTER"
	  case 13:
		  return eAction::ENTER;
// Обработка английских строчных символов
		case 'a':
			return eAction::LEFT;
			//act = LEFT;
			//std::cout << 'a' << std::endl;
			//break;
		case 'd':
			return eAction::RIGHT;
			//act=RIGHT;
			//std::cout << 'd' << std::endl;
			//break;
		case 'w':
			return eAction::UP;
			//act=UP;
			//std::cout << 'w' << std::endl;
			//break;
		case 's':
			return eAction::DOWN;
			//act=DOWN;
			//std::cout << 's' << std::endl;
			//break;
		case 'x':
			return eAction::EMPTY;
			//gameOver=true;
			//std::cout << 'x' << std::endl;
			//break;
// Обработка английских заглавных символов
		case 'A':
			return eAction::LEFT;
			//act = LEFT;
			//std::cout << 'A' << std::endl;
			//break;
		case 'D':
			return eAction::RIGHT;
			//act = RIGHT;
			//std::cout << 'D' << std::endl;
			//break;
		case 'W':
			return eAction::UP;
			//act = UP;
			//std::cout << 'W' << std::endl;
			//break;
		case 'S':
			return eAction::DOWN;
			//act = DOWN;
			//std::cout << 'S' << std::endl;
			//break;
		case 'X':
			return eAction::EMPTY;
			//gameOver = true;
			//std::cout << 'X' << std::endl;
			//break;
// Обработка русских строчных
		case 1092:
			return eAction::LEFT;
			//act = LEFT;
			//std::cout << "left" << std::endl;
			//break;
		case 1074:
			return eAction::RIGHT;
			//act = RIGHT;
			//std::cout << "right" << std::endl;
			//break;
		case 1094:
			return eAction::UP;
			//act = UP;
			//std::cout << "up" << std::endl;
			//break;
		case 1099:
			return eAction::DOWN;
			//act = DOWN;
			//std::cout << "down" << std::endl;
			//break;
// Обработка русских заглавных
	 	case 1060:
		  return eAction::LEFT;
			//act = LEFT;
			//std::cout << "LEFT" << std::endl;
			//break;
		case 1042:
			return eAction::RIGHT;
			//act = RIGHT;
			//std::cout << "RIGHT" << std::endl;
			//break;
		case 1062:
			return eAction::UP;
			//act = UP;
			//std::cout << "UP" << std::endl;
			//break;
		case 1067:
			return eAction::DOWN;
			//act = DOWN;
			//std::cout << "DOWN" << std::endl;
			//break;
// Обработка стрелочек 224 + код клавиши	
		case 224:
			switch (_getwch())
			{
			  case 75:
					return eAction::LEFT;
				  //act = LEFT;
					//std::cout << char(triangleLEFT) << std::endl;
				  //break;
			  case 77:
					return eAction::RIGHT;
				  //act = RIGHT;
					//std::cout << char(triangleRIGHT) << std::endl;
				  //break;
				case 72:
					return eAction::UP;
				 	//act = UP;
					//std::cout << char(triangleUP) << std::endl;
				 	//break;
			  case 80:
					return eAction::DOWN;
			  	//act = DOWN;
					//std::cout << char(triangleDOWN) << std::endl;
			  	//break;
			}
		default:
			return eAction::EMPTY;
	}
}

uint32_t menu()
{
	uint32_t ret  = 1;
	bool flagEXIT = false; // Условие закрытия потока и выхода их функции
	// MENU_1
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "SELECT OR ENTER MAP SIZE" << std::endl;
	std::cout << " SELECT" << std::endl;
  std::cout << " ENTER"  << std::endl;
	
	//Анимация выбора меню
	COORD position1 = { 0,2 };     // Координаты строки "SELECT"
	COORD position2 = { 0,3 };     // Координаты строки "ENTER"
	COORD* pPosition = &position1; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO console{ DWORD(100), false }; // DWORD  dwSize , BOOL   bVisible
	                                                  // Выкручиваем прозрачность курсора на 100
	SetConsoleCursorInfo(hConsole, &console);
	// Мигание символа выполняет поток
	std::thread thAnimationMenu([&]()
		{
			while(!flagEXIT)
			{
				SetConsoleCursorPosition(hConsole, *pPosition);
				std::cout << char(menuG_1);
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
				SetConsoleCursorPosition(hConsole, *pPosition);
				std::cout << char(menuG_2);
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
			}
		});
	// Обработку ввода с клавиавтуры выполняем в главном потоке 
	while(!flagEXIT)
	{
		if (_kbhit())
		{
			switch( input() )
			{
				case eAction::UP:
					SetConsoleCursorPosition(hConsole, *pPosition);
					std::cout << ' ';
					pPosition = &position1;
					ret = 1;
					break;
				case eAction::DOWN:
					SetConsoleCursorPosition(hConsole, *pPosition);
					std::cout << ' ';
					pPosition = &position2;
					ret = 2;
					break;
				case eAction::ENTER:
					flagEXIT = true;
					break;
				default:
					break;
			}
		}
	}
	thAnimationMenu.join();
	return ret;
	//std::cout << std::endl << std::endl << "EXIT";
 }

preMAP presetMAP()
{
	preMAP   ret  = preMAP::SMALL;
	bool flagEXIT = false; // Условие закрытия потока и выхода их функции
	uint32_t pos  = 1;

	std::cout << "-----SIZE MAP-----" << std::endl;
	std::cout << " SMALL"  << std::endl;
	std::cout << " MIDDLE" << std::endl;
	std::cout << " BIG"    << std::endl;

	//Анимация выбора меню
	COORD  position1 = { 0,1 };                       // Координаты строки "SMALL"
	COORD  position2 = { 0,2 };                       // Координаты строки "MIDDLE"
	COORD  position3 = { 0,3 };                       // Координаты строки "BIG"
	COORD* pPosition = &position1;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO console{ DWORD(100), false }; // DWORD  dwSize , BOOL   bVisible
	                                                  // Выкручиваем прозрачность курсора на 100
	SetConsoleCursorInfo(hConsole, &console);
	// Мигание символа выполняет поток
	std::thread thAnimationMenu([&]()
		{
			while (!flagEXIT)
			{
				SetConsoleCursorPosition(hConsole, *pPosition);
				std::cout << char(menuG_1);
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
				SetConsoleCursorPosition(hConsole, *pPosition);
				std::cout << char(menuG_2);
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
			}
		});
	// Обработку ввода с клавиавтуры выполняем в главном потоке 
	while (!flagEXIT)
	{
		if (_kbhit())
		{
			switch( input() ) // Определяем позицию, всего 3 позиции - 1,2,3
			{
				case eAction::UP:
					if( pos > 1 )
						--pos;
					break;
				case eAction::DOWN:
					if( pos < 3  )
					++pos;
					break;
				case eAction::ENTER:
					flagEXIT = true;
					break;
				default:
					break;
			}
			SetConsoleCursorPosition(hConsole, *pPosition); // Устанавливаем анимацию в нужной строке
			std::cout << ' ';
			switch(pos)
			{
			  case 1:
					pPosition = &position1;
					ret = preMAP::SMALL;
					break;
			  case 2:
					pPosition = &position2;
					ret = preMAP::MIDDLE;
					break;
			  case 3:
					pPosition = &position3;
					ret = preMAP::BIG;
					break;
			  default:
				  break;
			}
		}
	}
	thAnimationMenu.join();
	return ret;
};

eSpeed presetSPEED()
{
	eSpeed   ret      = eSpeed::SLOW;
	bool     flagEXIT = false; // Условие закрытия потока и выхода их функции
	uint32_t pos      = 1;

	std::cout << "-----SPEED-----" << std::endl;
	std::cout << " SLOW" << std::endl;
	std::cout << " MEAN" << std::endl;
	std::cout << " FAST" << std::endl;

	//Анимация выбора меню
	COORD  position1 = { 0,1 };                       // Координаты строки "SLOW"
	COORD  position2 = { 0,2 };                       // Координаты строки "MEAN"
	COORD  position3 = { 0,3 };                       // Координаты строки "FAST"
	COORD* pPosition = &position1;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO console{ DWORD(100), false }; // DWORD  dwSize , BOOL   bVisible
	// Выкручиваем прозрачность курсора на 100
	SetConsoleCursorInfo(hConsole, &console);
	// Мигание символа выполняет поток
	std::thread thAnimationMenu([&]()
		{
			while (!flagEXIT)
			{
				SetConsoleCursorPosition(hConsole, *pPosition);
				std::cout << char(menuG_1);
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
				SetConsoleCursorPosition(hConsole, *pPosition);
				std::cout << char(menuG_2);
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
			}
		});
	// Обработку ввода с клавиавтуры выполняем в главном потоке 
	while (!flagEXIT)
	{
		if (_kbhit())
		{
			switch (input()) // Определяем позицию, всего 3 позиции - 1,2,3
			{
			case eAction::UP:
				if (pos > 1)
					--pos;
				break;
			case eAction::DOWN:
				if (pos < 3)
					++pos;
				break;
			case eAction::ENTER:
				flagEXIT = true;
				break;
			default:
				break;
			}
			SetConsoleCursorPosition(hConsole, *pPosition); // Устанавливаем анимацию в нужной строке
			std::cout << ' ';
			switch (pos)
			{
			case 1:
				pPosition = &position1;
				ret = eSpeed::SLOW;
				break;
			case 2:
				pPosition = &position2;
				ret = eSpeed::MEAN;
				break;
			case 3:
				pPosition = &position3;
				ret = eSpeed::FAST;
				break;
			default:
				break;
			}
		}
	}
	thAnimationMenu.join();
	return ret;
};

// Вывод фигур
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
// Рамка
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