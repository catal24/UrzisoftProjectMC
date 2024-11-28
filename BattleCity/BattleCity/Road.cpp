#include "Road.h"

Road::Road(int xStart, int yStart, int id, bool isBreakable, bool isVisible)
	:GameObject{ xStart, yStart, id, isBreakable, isVisible } {}

void Road::Draw()
{
	std::cout << " ";
}


