#pragma once
#include "Map.h"
#include <typeinfo>;
#include "Road.h";
#include <cstdlib>
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

protected:
	Map m_map;
	
};

