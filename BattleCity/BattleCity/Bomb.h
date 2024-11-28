#pragma once
#include "GameObject.h"

class Bomb : public GameObject
{
public:
    Bomb(int xStart, int yStart, int id, bool isBreakable, bool isVisible, int radius = 1);

    int getRadius() const;
    void setRadius(int radius);

    void explosion();
    
    void Draw()override;

private:
    int m_id;
    int m_xStart;
    int m_yStart;
    bool m_isVisible;
    bool isBreakable;
	int m_radius=1;

};

