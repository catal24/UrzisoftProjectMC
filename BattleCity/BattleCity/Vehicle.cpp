#include "Vehicle.h"
#include "Axis.h"

#include <iostream>

Vehicle::Vehicle(int xStart, int yStart, int id, bool isBreakable, bool isVisible, int lives, int speed,bool isDead, Axis axis):
	GameObject(xStart, yStart, id, isBreakable, isVisible),
	m_lives{ lives },
	m_speed{ speed },
	m_isDead{ isDead },
	m_axis{ axis }
	{}




Bullet Vehicle::shootBullet()
{
	int bulletX = m_x;
	int bulletY = m_y;

	std::cout << "Shooting in direction: " << static_cast<int>(m_axis) << std::endl;
	switch (m_axis) {
	case Axis::up: bulletX--; break;
	case Axis::down: bulletX++; break;
	case Axis::left: bulletY--; break;
	case Axis::right: bulletY++; break;
	}
	return Bullet(0, bulletX, bulletY, false, true, 1, 1, m_axis);
	
}

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
	else if (dir == 's') {
		m_x++;   
		m_axis = Axis::down;
		
	}
	else if (dir == 'a') {
		m_y--;   
		m_axis = Axis::left;
		
	}
	else if (dir == 'd') {
		m_y++;   
		m_axis = Axis::right;
		
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
