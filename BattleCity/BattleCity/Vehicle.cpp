#include "Vehicle.h"
import axis;

#include <iostream>

Vehicle::Vehicle(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible, int lives, int speed, bool isDead, Axis axis,int playerid) :
	GameObject{ xStart, yStart, x, y, id, isBreakable, isVisible },
	m_lives{ lives },
	m_speed{ speed },
	m_isDead{ isDead },
	m_axis{ axis },
	m_playerid{playerid}
{
	m_startingPositions = { {1,1},{18,18},{1,18},{18,1} };
}




std::shared_ptr<Bullet> Vehicle::ShootBullet(int x, int y)
{
	int bulletX = x;
	int bulletY = y;

	//	std::cout << "Shooting in direction: " << static_cast<int>(m_axis) << std::endl;
	switch (m_axis) {
	case Axis::up: bulletX--; break;
	case Axis::down: bulletX++; break;
	case Axis::left: bulletY--; break;
	case Axis::right: bulletY++; break;
	}

	//std::cout << "Bullet position after adjustment: (" << bulletX << ", " << bulletY << ")" << std::endl;

	return std::make_shared<Bullet>(bulletX, bulletY, bulletX, bulletY, 0, false, true, 1, 1, m_axis);

}

void Vehicle::SetAxis(char ax)
{
	if (ax == 'w')
		m_axis = Axis::up;
	else if (ax == 's')
		m_axis = Axis::down;
	else if (ax == 'd')
		m_axis = Axis::right;
	else if (ax == 'a')
		m_axis = Axis::left;

}

void Vehicle::SetSpeed(int amount) { m_speed = amount; }
void Vehicle::SetLives(int amount) { m_lives = amount; }
void Vehicle::SetIsDead(bool flag) { m_isDead = flag; }


int Vehicle::GetSpeed() const { return m_speed; }
int Vehicle::GetLives() const { return m_lives; }
bool Vehicle::GetIsDead() const { return m_isDead; }
Axis Vehicle::GetAxis() const { return m_axis; }

std::vector<std::pair<int, int>> Vehicle::GetStartingPositions() { return m_startingPositions; }

void Vehicle::Draw()
{
	std::cout << (char)254u;
}

int Vehicle::GetPlayerId() const
{
	return m_playerid;
}

void Vehicle::SetPlayerId(int playerid)
{
	m_playerid = playerid;
}
