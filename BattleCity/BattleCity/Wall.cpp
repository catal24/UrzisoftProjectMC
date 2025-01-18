#include <iostream>;
#include "Wall.h"


Wall::Wall(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible, bool hasBomb)
	:GameObject{ xStart, yStart, x, y, id, isBreakable, isVisible },
	m_hasBomb{ hasBomb }
{}

bool Wall::HasBomb() const
{
	return m_hasBomb;
}


void Wall::SetBomb(bool hasBomb)
{
	m_hasBomb = hasBomb;
}

void Wall::Draw()
{
	if (!IsBreakable())
	{
		this->SetTextColor(5);
	}
	else
		this->SetTextColor(3);
	std::cout << (char)254u;
	this->SetTextColor(7);
}
