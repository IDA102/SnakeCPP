#pragma once
#include "../inc/Define.h"
#include "../inc/Figure.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
//#include <consoleapi2.h>
#include <Windows.h>
#include <list>
//#include "./Score.h"


//using namespace std;

extern bool gameOver;
extern int delay;
extern int bestScore;
extern size_t score;

enum class eAction { STOP  = 0, LEFT , RIGHT , UP , DOWN, EMPTY, ENTER = 13 };
enum class preMAP  { EMPTY = 0, SMALL, MIDDLE, BIG};
enum class eSpeed  { EMPTY = 0, SLOW , MEAN  , FAST};

eAction  input();       // Обработчик символов
uint32_t menu();        // Меню
preMAP   presetMAP();   // Пресеты размеров карты
eSpeed   presetSPEED(); // Пресеты скоростей

//void Setup();
//void Draw();
//void Logic();
