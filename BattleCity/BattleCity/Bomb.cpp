#include "Bomb.h"

Bomb::Bomb(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible)
	: GameObject{xStart, yStart, x, y, id, isBreakable, isVisible} {}

void Bomb::Draw()
{
	this->SetTextColor(4);
	std::cout << (char)254u;
	this->SetTextColor(7);
}

