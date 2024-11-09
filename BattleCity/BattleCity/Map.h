#pragma once
#include <iostream>
#include <vector>
#include<windows.h>
#include "Vehicle.h"
#include "Wall.h"

class Map
{

public:
	Map() = default;

	Map(std::vector<std::vector<int>> mat);

	void drawMap();

	std::vector<std::vector<GameObject*>>& getMap();

private:
	int m_width;
	int m_height;
	std::vector<std::vector<GameObject*>> m_map;

};
