#pragma once
#include <iostream>
#include <crow.h>
#include <thread>
#include <vector>
#include<windows.h>
#include "Vehicle.h"
#include "Wall.h"
#include "Bomb.h"

class Map
{

public:
	Map() = default;

	std::string EncodeMap2();

	Map(std::vector<std::vector<int>> mat);

	void DrawMap();

	std::vector<std::vector<int>> EncodeMap();

	std::vector<std::vector<GameObject*>>& GetMap();

	void GenerateRandomBombsOnWalls(int numBombs);
	void GenerateRandomIndestructibleWalls(int count);
	void SetIndestructibleBorders();

	GameObject* GetObjectAt(int x, int y);

	std::vector<GameObject*>& operator[](int index); // pentru accesare scrisa
	const std::vector<GameObject*>& operator[](int index) const; // pentru citire

	int GetWidth();
	int GetHeight();
	int GetNumberOfRoads();
	int GetNumberOfWalls();
	void SetWidth(int width);
	void SetHeight(int height);
	void SetNumberOfRoads(int numberOfRoads);
	void SetNumberOfWalls(int numberOfWalls);

private:
	int m_width;
	int m_height;
	int m_numberOfRoads = 0;
	int m_numberOfWalls = 0;
	std::vector<std::vector<GameObject*>> m_map;

};
