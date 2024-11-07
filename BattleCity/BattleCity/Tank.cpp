#include "Tank.h"




Tank::Tank(int xStart, int yStart, int id, bool isBreakable, bool isVisible, int lives, int speed,bool isDead, Axis axis):
	GameObject(xStart, yStart, id, isBreakable, isVisible),
	m_lives(lives),
	m_speed(speed),
	m_isDead(isDead),
	m_bullet (1, 10),
	m_axis(axis)
	{}

Tank::Tank()
{

}


void Tank::SetSpeed(int amount)
{
	m_speed = amount;
}

void Tank::SetLives(int amount)
{
	m_lives = amount;
}

void Tank::SetIsDead()
{
	m_isDead = true;
}

int Tank::GetSpeed() const
{
	return m_speed;
}

int Tank::GetLives() const
{
	return m_lives;
}


bool Tank::GetIsDead() const
{
	return m_isDead;
}

Axis Tank::GetAxis() const
{
	return m_axis;
}

void Tank::die()
{
	m_lives-= 1;
	if (m_lives> 0)
		respawn();
	else
		m_isDead = true;
}

void Tank::respawn()
{
}

void Tank::draw(int xStart, int yStart)
{
	
}
