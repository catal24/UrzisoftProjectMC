#pragma once
#include "Map.h"
#include "Road.h"
#include "Bomb.h"
#include "Game.h"
#include <typeinfo>
#include <cstdlib>
#include <queue>

class Game;

class GameScene
{
public:
	GameScene(std::vector<std::vector<int>> m);
	GameScene() = default;

	void addObj(GameObject* obj);

	void removeObj(int x, int y);

	bool checkObj(int x,int y);

	void moveObject(GameObject* obj, int x, int y);

	void drawTest(Game g);

	void drawQueue(std::queue<GameObject*>& q);

	GameObject* getObjectAt(int x, int y);

protected:
	Map m_map;
	
};

