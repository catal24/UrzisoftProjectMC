#include "Bullet.h"

Bullet::Bullet()
{
}

int Bullet::getLevel() const
{
	return m_level;
}

int Bullet::getSpeed() const
{
	return m_speed;
}

void Bullet::setSpeed(int speed)
{
	m_speed = speed;
}

