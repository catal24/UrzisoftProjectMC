#pragma once
#include "GameObject.h"

class Bomb : public GameObject
{
public:
    Bomb(int xStart = 0, int yStart = 0, int id = 0, bool isBreakable = false, bool isVisible = false, int radius = 1);

    int getRadius() const;
    void setRadius(int radius);

    void explosion();
    
    void draw()override;

private:
    int m_id;
    int m_xStart;
    int m_yStart;
    bool m_isVisible;
    bool isBreakable;
	int m_radius=1;

};

