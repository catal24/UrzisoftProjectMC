#include "Bomb.h"

Bomb::Bomb(uint8_t xStart, uint8_t yStart, int id, bool isBreakable, bool isVisible)
	: GameObject{xStart, yStart, id, isBreakable, isVisible} {}
void Bomb::Draw()
{
	this->SetTextColor(4);
	std::cout << (char)254u;
	this->SetTextColor(7);
}

