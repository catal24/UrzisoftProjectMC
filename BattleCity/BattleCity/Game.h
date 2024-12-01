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
	Game(const std::vector<std::vector<int>>& initMap, Difficulty = EASY);
	void startGame();

	Difficulty GetDifficulty();
	void SetDifficulty(Difficulty difficulty);
	void HandleBombCollision(Bomb* bomb, int bombX, int bombY);
	void HandleBulletCollision(std::vector<std::shared_ptr<Bullet>>::iterator& it, int newX, int newY);
	void BulletMoving();
	void Shoot();
private:
	Vehicle m_v;
	Difficulty m_difficulty = EASY;
	std::vector<std::vector<int>> m_initMap;
	GameScene* m_scene;

	std::vector<std::shared_ptr<Bullet>> bullets;
	int m_playerCount;
};

