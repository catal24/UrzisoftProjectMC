#pragma once
#include "Map.h";
#include "Vehicle.h";
#include "Bullet.h";
#include <conio.h>
#include <cstdlib>
#include "GameScene.h";
#include <conio.h> 
#include <windows.h>

class Game
{
public:
	Game(std::vector<std::vector<int>> m_initMap);
	void startGame();

private:
	Vehicle m_v;
	std::vector<std::vector<int>> m_initMap;
	GameScene m_scene;

};

