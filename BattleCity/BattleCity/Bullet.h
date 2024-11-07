#pragma once
#include "GameObject.h"

class Bullet:public GameObject
{
public:

    enum Axis {
        X_AXIS,
        Y_AXIS
    };

    Bullet(int level, int speed)
        : m_level(level), m_speed(speed) {}
    Bullet();

    int getLevel() const;
    int getSpeed() const;

    void setSpeed(int speed);

private:
	int m_level;
	int m_speed;

};

