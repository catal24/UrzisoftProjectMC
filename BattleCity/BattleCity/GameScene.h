#pragma once
#include "Map.h"
#include "Road.h"
#include <typeinfo>
#include <cstdlib>
#include <queue>

class GameScene
{
public:
	GameScene(std::vector<std::vector<int>> m);
	GameScene() = default;

	void addObj(GameObject* obj);

	void removeObj(int x, int y);

	bool checkObj(int x,int y);

	void moveObject(GameObject* obj, int x, int y);

	void drawTest();

	void drawQueue(std::queue<GameObject*>& q);

protected:
	Map m_map;
	
};

