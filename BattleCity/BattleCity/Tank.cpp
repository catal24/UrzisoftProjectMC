#include "Tank.h"




Tank::Tank(int xStart, int yStart, int id, bool isBreakable, bool isVisible, int lives, int speed,bool isDead)
{
	GameObject(xStart, yStart, id, isBreakable, isVisible);
	m_lives = lives;
	m_speed=speed;
	m_isDead = false;
}

void Tank::setSpeed(int amount)
{
	m_speed = amount;
}

void Tank::setLives(int amount)
{
	m_lives = amount;
}

void Tank::setIsDead()
{
	m_isDead = true;
}

int Tank::getSpeed() const
{
	return m_speed;
}

int Tank::getLives() const
{
	return m_lives;
}

bool Tank::getIsDead() const
{
	return m_isDead;
}

void Tank::die()
{
	setLives(m_lives - 1);
	if (m_isDead > 0)
		respawn();
	else
		setIsDead();
}
