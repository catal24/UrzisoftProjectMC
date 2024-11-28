#include "Bullet.h"

Bullet::Bullet(int xStart, int yStart, int id, bool isBreakable, bool isVisible, int level, int speed, Axis axis)
	:GameObject{ xStart, yStart, id, isBreakable, isVisible },
	m_level{ level },
	m_speed{ speed },
	m_axis{ axis }
{
	m_xStart = xStart;
	m_yStart = yStart;
}

Bullet::Bullet(const Bullet& other)
	:GameObject{ other.m_xStart, other.m_yStart, other.m_id, other.m_isBreakable, other.m_isVisible },
	m_level{ other.m_level },
	m_speed{ other.m_speed },
	m_axis{ other.m_axis }
{}

int Bullet::GetLevel() const { return m_level; }

int Bullet::GetSpeed() const { return m_speed; }

Axis Bullet::GetAxis() const { return m_axis; }

void Bullet::SetSpeed(int speed) { m_speed = speed; }



void Bullet::Draw() { std::cout << "*"; }

int Bullet::GetXStart() const { return m_xStart; }
void Bullet::SetXStart(int xStart) { m_xStart = xStart; }

int Bullet::GetYStart() const { return m_yStart; }
void Bullet::SetYStart(int yStart) { m_yStart = yStart; }

int Bullet::GetId() const { return m_id; }
void Bullet::SetId(int id) { m_id = id; }

bool Bullet::IsBreakable() const { return m_isBreakable; }
void Bullet::SetBreakable(bool isBreakable) { m_isBreakable = isBreakable; }

bool Bullet::IsVisible() const { return m_isVisible; }
void Bullet::SetVisible(bool isVisible) { m_isVisible = isVisible; }

bool Bullet::IsFirstMove() { return m_firstMove; }
void Bullet::SetFirstMove(bool value) { m_firstMove = value; }

