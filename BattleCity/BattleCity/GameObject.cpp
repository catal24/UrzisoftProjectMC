#include "GameObject.h"

GameObject::GameObject(int xStart, int yStart, int id, bool isBreakable, bool isVisible)
    : m_x(xStart), m_y(yStart), m_id(id), m_isBreakable(isBreakable), m_isVisible(isVisible) {}



int GameObject::getXStart() const { return m_x; }
void GameObject::setXStart(int xStart) { m_x = xStart; }

void GameObject::setTextColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int GameObject::getYStart() const { return m_y; }
void GameObject::setYStart(int yStart) { m_y = yStart; }

int GameObject::getId() const { return m_id; }
void GameObject::setId(int id) { m_id = id; }

bool GameObject::isBreakable() const { return m_isBreakable; }
void GameObject::setBreakable(bool isBreakable) { m_isBreakable = isBreakable; }

bool GameObject::isVisible() const { return m_isVisible; }
void GameObject::setVisible(bool isVisible) { m_isVisible = isVisible; }
