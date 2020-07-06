#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>

using namespace std;

extern bool gameOver;
extern int delay;
extern int bestScore;
extern size_t score;

void Setup();
void Draw();
void Input();
void Logic();