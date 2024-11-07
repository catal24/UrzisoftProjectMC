#pragma once
#include <iostream>
#include <vector>
#include<windows.h>
#include "Tank.h"

class Map
{

public:
	Map() = default;

	Map(int width, int height);

	void drawMap();

	void addTank(Tank t);

private:
	int m_width;
	int m_height;
	std::vector<std::vector<char>> m_map;

};

