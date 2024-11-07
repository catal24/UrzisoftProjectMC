#pragma once
#include <iostream>
#include <vector>
#include<windows.h>
#include "Tank.h"
import Wall;

class Map
{

public:
	Map() = default;

	Map(int width, int height);

	void drawMap();


private:
	int m_width;
	int m_height;
	std::vector<std::vector<GameObject*>> m_map;

};

