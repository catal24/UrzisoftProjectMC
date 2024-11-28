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

int Wall::GetXStart() const { return m_xStart; }
void Wall::SetXStart(int xStart) { m_xStart = xStart; }

int Wall::GetYStart() const { return m_yStart; }
void Wall::SetYStart(int yStart) { m_yStart = yStart; }

int Wall::GetId() const { return m_id; }
void Wall::SetId(int id) { m_id = id; }

bool Wall::IsBreakable() const { return m_isBreakable; }
void Wall::SetBreakable(bool isBreakable) { m_isBreakable = isBreakable; }

bool Wall::IsVisible() const { return m_isVisible; }
void Wall::SetVisible(bool isVisible) { m_isVisible = isVisible; }

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
