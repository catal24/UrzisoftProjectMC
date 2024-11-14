#pragma once
#include "Map.h";
#include "Vehicle.h";
#include "Bullet.h";
#include <conio.h>
#include <cstdlib>
#include "GameScene.h";
#include <conio.h> 
#include <windows.h>
#include <utility>
#include "Axis.h"

class GameScene;

class Game
{
public:
	enum Difficulty {
		EASY,
		MEDIUM,
		HARD,
		EXTREME
	};

	Game() = default;
	Game(std::vector<std::vector<int>> m_initMap, Difficulty = EASY);
	void startGame();

	Difficulty GetDifficulty();
	void SetDifficulty(Difficulty difficulty);

private:
	Vehicle m_v;
	Difficulty m_difficulty = EASY;
	std::vector<std::vector<int>> m_initMap;
	GameScene* m_scene;
	std::vector<Bullet> bullets;
};

