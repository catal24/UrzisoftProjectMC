#pragma once
#include "GameObject.h"

class Bullet:public GameObject
{
public:
    enum Axis {
        X_AXIS,
        Y_AXIS
    };
private:
	int m_level;
	int m_speed;

};

