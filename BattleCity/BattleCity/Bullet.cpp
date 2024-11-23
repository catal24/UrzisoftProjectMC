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

Bullet::Bullet(const Bullet & other)
	:GameObject{ other.m_xStart, other.m_yStart, other.m_id, other.m_isBreakable, other.m_isVisible },
	m_level{other.m_level},
	m_speed{other.m_speed},
	m_axis{other.m_axis}
{}

int Bullet::getLevel() const   {return m_level;}

int Bullet::getSpeed() const   {return m_speed;}

Axis Bullet::getAxis() const   {return m_axis;}

void Bullet::setSpeed(int speed)    {m_speed = speed;}

void Bullet::draw()		{std::cout << "*";}

int Bullet::getXStart() const    { return m_xStart; }
void Bullet::setXStart(int xStart)     { m_xStart = xStart; }

int Bullet::getYStart() const    { return m_yStart; }
void Bullet::setYStart(int yStart)   { m_yStart = yStart; }

int Bullet::getId() const { return m_id; }
void Bullet::setId(int id) { m_id = id; }

bool Bullet::isBreakable() const { return m_isBreakable; }
void Bullet::setBreakable(bool isBreakable) { m_isBreakable = isBreakable; }

bool Bullet::isVisible() const { return m_isVisible; }
void Bullet::setVisible(bool isVisible) { m_isVisible = isVisible; }

