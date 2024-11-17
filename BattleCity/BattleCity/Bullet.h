#pragma once
#include "GameObject.h"
#include "Axis.h"

class Bullet:public GameObject
{


public:
    Bullet() = default;
    Bullet(int id = 0, int xStart = -1, int yStart = -1, bool isBreakable = false, bool isVisible = true, int level=0, int speed=0, Axis axis = Axis::left);
        
    

    int getLevel() const;
    int getSpeed() const;

    Axis getAxis() const;

    void setSpeed(int speed);

    int getXStart() const;
    void setXStart(int xStart);


    int getYStart() const;
    void setYStart(int yStart);

    int getId() const;
    void setId(int id);

    bool isBreakable() const;
    void setBreakable(bool isBreakable);

    bool isVisible() const;
    void setVisible(bool isVisible);

    void draw()override;
private:
    int m_id;
    Axis m_axis;
	int m_level;
	int m_speed;
    int m_xStart;
    int m_yStart;
    bool m_isBreakable;
    bool m_isVisible;
};

