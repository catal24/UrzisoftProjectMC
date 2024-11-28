#include <iostream>;
#include "Wall.h"


Wall::Wall(int xStart, int yStart, int id, bool isBreakable, bool isVisible, bool hasBomb)
	:GameObject{ xStart, yStart, id, isBreakable, isVisible },
	m_hasBomb{ hasBomb }
{}




bool Wall::HasBomb() const
{
	return m_hasBomb;
}


void Wall::SetDestructible(bool destructible)
{
	m_isBreakable = destructible;
}


void Wall::SetBomb(bool hasBomb)
{
	m_hasBomb = hasBomb;
}

int Wall::getXStart() const { return m_xStart; }
void Wall::setXStart(int xStart) { m_xStart = xStart; }

int Wall::getYStart() const { return m_yStart; }
void Wall::setYStart(int yStart) { m_yStart = yStart; }

int Wall::getId() const { return m_id; }
void Wall::setId(int id) { m_id = id; }

bool Wall::isBreakable() const { return m_isBreakable; }
void Wall::setBreakable(bool isBreakable) { m_isBreakable = isBreakable; }

bool Wall::isVisible() const { return m_isVisible; }
void Wall::setVisible(bool isVisible) { m_isVisible = isVisible; }

void Wall::Draw()
{
	if (!isBreakable())
	{
		this->SetTextColor(5);
	}
	else
		this->SetTextColor(3);
	std::cout << (char)254u;
	this->SetTextColor(7);
}
