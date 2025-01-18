#pragma once
#include "GameObject.h"
#include "Axis.h"

class Bullet:public GameObject
{


public:
    Bullet() = default;
    Bullet(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible, int level=0, int speed=0, Axis axis = Axis::left);
    Bullet(const Bullet& other);
    

    int GetLevel() const;
    int GetSpeed() const;

    Axis GetAxis() const;

    void SetSpeed(int speed);

    bool IsFirstMove();
    void SetFirstMove(bool value);

    void Draw()override;
private:
    int m_id;
    Axis m_axis;
	int m_level;
    int m_speed;
    int m_xStart;
    int m_yStart;
    int m_x;
    int m_y;
    bool m_isBreakable;
    bool m_isVisible;
    bool m_firstMove = true;
};

