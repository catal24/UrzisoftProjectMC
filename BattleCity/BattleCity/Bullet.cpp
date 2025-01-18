#include "Bullet.h"

Bullet::Bullet(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible, int level, int speed, Axis axis)
	:GameObject{ xStart, yStart, x, y, id, isBreakable, isVisible },
	m_level{ level },
	m_speed{ speed },
	m_axis{ axis }
{}

Bullet::Bullet(const Bullet& other)
	:GameObject{ other.m_xStart, other.m_yStart, other.m_x, other.m_y, other.m_id, other.m_isBreakable, other.m_isVisible },
	m_level{ other.m_level },
	m_speed{ other.m_speed },
	m_axis{ other.m_axis }
{}

int Bullet::GetLevel() const { return m_level; }

int Bullet::GetSpeed() const { return m_speed; }

Axis Bullet::GetAxis() const { return m_axis; }

void Bullet::SetSpeed(int speed) { m_speed = speed; }

void Bullet::Draw() { std::cout << "*"; }

bool Bullet::IsFirstMove() { return m_firstMove; }
void Bullet::SetFirstMove(bool value) { m_firstMove = value; }

