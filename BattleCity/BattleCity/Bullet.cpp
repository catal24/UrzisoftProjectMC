#include "Bullet.h"

Bullet::Bullet(int id, int xStart, int yStart, bool isBreakable, bool isVisible, int level, int speed, Axis axis)
	:m_id{ id },
	m_xStart{ xStart },
	m_yStart{ yStart },
	m_isBreakable{ isBreakable },
	m_isVisible{ isVisible },
	m_level{ level },
	m_speed{ speed },
	m_axis{ axis }
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

