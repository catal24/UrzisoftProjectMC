#pragma once
#include "GameObject.h"
class Road:public GameObject
{
public:
	Road(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible);
	void Draw() override;

private:
	int m_xStart;
	int m_yStart;
	int m_x;
	int m_y;
	int m_id;
	bool m_isBreakable;
	bool m_isVisible;
};

