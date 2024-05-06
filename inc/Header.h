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
//#include <consoleapi2.h>
#include <Windows.h>
//#include "./Score.h"

using namespace std;

extern bool gameOver;
extern int delay;
extern int bestScore;
extern size_t score;

void Setup();
void Draw();
void Input();
void Logic();
void testMENU();