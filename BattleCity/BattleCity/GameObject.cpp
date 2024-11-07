#include "GameObject.h"

GameObject::GameObject(int xStart, int yStart, int id, bool isBreakable, bool isVisible)
    : m_xStart(xStart), m_yStart(yStart), m_id(id), m_isBreakable(isBreakable), m_isVisible(isVisible) {}

int GameObject::getXStart() const { return m_xStart; }
void GameObject::setXStart(int xStart) { m_xStart = xStart; }

int GameObject::getYStart() const { return m_yStart; }
void GameObject::setYStart(int yStart) { m_yStart = yStart; }

int GameObject::getId() const { return m_id; }
void GameObject::setId(int id) { m_id = id; }

bool GameObject::isBreakable() const { return m_isBreakable; }
void GameObject::setBreakable(bool isBreakable) { m_isBreakable = isBreakable; }

bool GameObject::isVisible() const { return m_isVisible; }
void GameObject::setVisible(bool isVisible) { m_isVisible = isVisible; }
