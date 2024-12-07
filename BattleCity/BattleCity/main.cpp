#include<iostream>
#include <conio.h>
#include <cstdlib>
#include "Game.h";
#include "Road.h"
#include "GameScene.h";


int main()
{
    Game g( Game::Difficulty::EXTREME);
    g.startGame();
	return 0;
}