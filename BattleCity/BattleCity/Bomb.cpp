#include "Bomb.h"

Bomb::Bomb(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible, int radius)
	: GameObject{xStart, yStart, x, y, id, isBreakable, isVisible},
	m_radius{ radius } {}

int Bomb::GetRadius() const { return m_radius; }
void Bomb::SetRadius(int radius) { m_radius = radius; }

void Bomb::Draw()
{
	this->SetTextColor(4);
	std::cout << (char)254u;
	this->SetTextColor(7);
}

