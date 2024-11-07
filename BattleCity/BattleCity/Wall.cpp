#include <iostream>;
#include "Wall.h"


Wall::Wall(bool isDestructible, bool hasBomb)
	:m_isDestructible{isDestructible}, m_hasBomb{hasBomb}
{}

bool Wall::IsDestructible() const
{
	return m_isDestructible;
}


bool Wall::HasBomb() const
{
	return m_hasBomb;
}


void Wall::SetDestructible(bool destructible)
{
	m_isDestructible = destructible;
}


void Wall::SetBomb(bool hasBomb)
{
	m_hasBomb = hasBomb;
}
