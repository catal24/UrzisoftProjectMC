#include "Road.h"

Road::Road(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible)
	:GameObject{ xStart, yStart, x, y, id, isBreakable, isVisible } {}

void Road::Draw()
{
	std::cout << " ";
}


