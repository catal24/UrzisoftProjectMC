#pragma once
#include "GameObject.h"
#include <iostream>

class Wall : public GameObject
{
public:
	
	Wall(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible, bool hasBomb);

	bool HasBomb()const;

	void SetBomb(bool hasBomb);

	void Draw()override;

private:
	int m_id;
	int m_xStart;
	int m_yStart;
	int m_x;
	int m_y;
	bool m_isVisible;
	bool m_isBreakable;
	bool m_hasBomb;
};