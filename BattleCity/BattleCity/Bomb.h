#pragma once
#include "GameObject.h"

class Bomb : public GameObject
{
public:
    Bomb(uint8_t xStart, uint8_t yStart, int id, bool isBreakable, bool isVisible);
    void Draw()override;

private:
    int m_id;
    uint8_t m_xStart;
    uint8_t m_yStart;
    bool m_isVisible;
    bool isBreakable;

};

