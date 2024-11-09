#pragma once
#include "GameObject.h"
class Road:public GameObject
{
public:
	Road(int xStart = 0, int yStart = 0, int id = 0, bool isBreakable = false, bool isVisible = true);
	void draw() override;
};

