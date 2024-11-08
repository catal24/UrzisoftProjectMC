#include "Vehicle.h"




Vehicle::Vehicle(int xStart, int yStart, int id, bool isBreakable, bool isVisible, int lives, int speed,bool isDead, Axis axis):
	GameObject(xStart, yStart, id, isBreakable, isVisible),
	m_lives{ lives },
	m_speed{ speed },
	m_isDead{ isDead },
	m_axis{ axis }
	{}




void Vehicle::SetSpeed(int amount)
{
	m_speed = amount;
}

void Vehicle::SetLives(int amount)
{
	m_lives = amount;
}

void Vehicle::SetIsDead()
{
	m_isDead = true;
}

void Vehicle::moveTank(char dir)
{
	if (dir == 'w') {
		m_x--;
		m_axis = Axis::up;
	}
	else if (dir == 's')
	{
		m_x++;
		m_axis = Axis::down;
	}
	
}

int Vehicle::GetSpeed() const
{
	return m_speed;
}

int Vehicle::GetLives() const
{
	return m_lives;
}


bool Vehicle::GetIsDead() const
{
	return m_isDead;
}

Axis Vehicle::GetAxis() const
{
	return m_axis;
}

void Vehicle::die()
{
	m_lives-= 1;
	if (m_lives> 0)
		respawn();
	else
		m_isDead = true;
}

void Vehicle::respawn()
{
}

void Vehicle::draw()
{
	std::cout << (char)254u;
}
