#include "Bomb.h"

Bomb::Bomb(int xStart, int yStart, int id, bool isBreakable, bool isVisible, int radius)
	: GameObject{xStart, yStart, id, isBreakable, isVisible},
	m_radius{ radius } {}

int Bomb::getRadius() const { return m_radius; }
void Bomb::setRadius(int radius) { m_radius = radius; }

void Bomb::draw()
{
	this->setTextColor(4);
	std::cout << (char)254u;
	this->setTextColor(7);
}

