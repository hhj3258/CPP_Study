#include<iostream>
#include "Game.h"
using namespace std;

// 오늘의 주제 : TextRPG #4

int main()
{
	srand((unsigned int)time(nullptr));

	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}


	return 0;
}