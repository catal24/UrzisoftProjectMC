#pragma once
#include "GameObject.h"

class Bullet:public GameObject
{
public:

    enum class Axis {
        X_AXIS,
        Y_AXIS
    };

public:
    Bullet() = default;
    Bullet(int id = 0, int xStart = 0, int yStart = 0, bool isBreakable = false, bool isVisible = true, int level, int speed, Axis axis);
        
    

    int getLevel() const;
    int getSpeed() const;

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

