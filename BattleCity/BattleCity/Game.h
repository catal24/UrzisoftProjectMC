#pragma once
#include "Map.h";
#include "Tank.h";
#include "Bullet.h";
#include <conio.h>
#include <cstdlib>

class Game
{
	void gameInit();

private:
	Map map = Map(50,20);


};

