#pragma once
#include "GameObject.h"

class Bomb:public GameObject
{
public:
    Bomb(int xStart = 0, int yStart = 0, int id = 0, bool isBreakable = false, bool isVisible = false, int radius = 0);

    int getRadius() const;
    void setRadius(int radius);

    void explosion();

private:
	int m_radius=1;

};

