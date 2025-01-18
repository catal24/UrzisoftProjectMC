#include "Vehicle.h"
#include "Axis.h"

#include <iostream>

Vehicle::Vehicle(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible, int lives, int speed, bool isDead, Axis axis,int playerid) :
	GameObject{ xStart, yStart, x, y, id, isBreakable, isVisible },
	m_lives{ lives },
	m_speed{ speed },
	m_isDead{ isDead },
	m_axis{ axis },
	m_playerid{playerid}
{
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

void Vehicle::MoveTank(char dir)
{
	if (dir == 'w') {
		m_x--;
		m_axis = Axis::up;
		std::cout << "move direction up " << static_cast<int>(m_axis) << std::endl;


	}
	else if (dir == 's') {
		m_x++;
		m_axis = Axis::down;
		std::cout << "move direction down" << static_cast<int>(m_axis) << std::endl;


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

int Vehicle::GetSpeed() const { return m_speed; }
int Vehicle::GetLives() const { return m_lives; }
bool Vehicle::GetIsDead() const { return m_isDead; }
Axis Vehicle::GetAxis() const { return m_axis; }


void Vehicle::Die()
{
	m_lives -= 1;
	if (m_lives > 0)
		Respawn();
	else
		m_isDead = true;
}

void Vehicle::Respawn()
{
}

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
