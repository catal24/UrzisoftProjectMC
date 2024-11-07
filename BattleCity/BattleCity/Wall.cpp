#include <iostream>;
#include "Wall.h"


Wall::Wall(int id, int xStart, int yStart, bool isVisible, bool isBreakable, bool hasBomb)
	:m_id{ id },
	m_xStart{ xStart },
	m_yStart{ yStart },
	m_isBreakable{ isBreakable },
	m_isVisible{ isVisible },
	m_hasBomb{ hasBomb }

{}

bool Wall::IsBreakable() const
{
	return m_isBreakable;
}


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
