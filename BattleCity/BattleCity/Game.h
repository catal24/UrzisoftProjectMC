#pragma once


#include "Map.h";
#include "Vehicle.h";
#include "Bullet.h";
#include <cstdlib>
#include "GameScene.h";
#include <conio.h> 
#include <windows.h>
#include <utility>
import axis;
#include <random>
#include <fstream>

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
	Game( Difficulty = EASY);
	void startGame();

	Difficulty GetDifficulty();
	void SetDifficulty(Difficulty difficulty);
	void HandleBombCollision(Bomb* bomb, int bombX, int bombY);
	void HandleBulletCollision(std::vector<std::shared_ptr<Bullet>>::iterator& it, int newX, int newY);
	void BulletMoving();
	void Shoot(Vehicle v);
	void InputControll();
	Map& GetMap();
	GameScene* GetScene();
	std::vector<std::vector<int>> randomMap();
private:
	Vehicle m_v1,m_v2,m_v3,mv_4;
	Map m_map;
	Difficulty m_difficulty = EASY;
	std::vector<std::vector<int>> m_initMap;
	GameScene* m_scene;
	bool isStart;
	std::vector<std::shared_ptr<Bullet>> bullets;
	int m_playerCount;
};

