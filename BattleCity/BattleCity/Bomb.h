#pragma once
#include "GameObject.h"

class Bomb : public GameObject
{
public:
    Bomb(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible);

    
    void Draw()override;

private:
    int m_id;
    int m_xStart;
    int m_yStart;
    int m_x;
    int m_y;
    bool m_isVisible;
    bool isBreakable;

};

