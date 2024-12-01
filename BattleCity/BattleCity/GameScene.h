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
	void ClearConsole();
	GameScene(std::vector<std::vector<int>> m);
	GameScene() = default;

	void AddObj(GameObject* obj);

	void RemoveObj(int x, int y);

	bool CheckObj(int x,int y);

	void MoveObject(GameObject* obj, int x, int y);

	void DrawTest(Game g);

	void DrawQueue(std::queue<GameObject*>& q);
	std::vector<std::pair<int,int>> GetStartingPositions();

	GameObject* GetObjectAt(int x, int y);

	void RespawnObj(Vehicle* obj, int x, int y);

protected:
	Map m_map;
	std::vector<std::pair<int, int>> m_startingPositions = { {1,1},{18,18},{1,18},{18,1} };
	
};

