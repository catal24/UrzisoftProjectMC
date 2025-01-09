#include "GameObject.h"

GameObject::GameObject(uint8_t xStart, uint8_t yStart, int id, bool isBreakable, bool isVisible)
    : m_x{ xStart }, 
    m_y{ yStart }, 
    m_id{ id }, 
    m_isBreakable{ isBreakable }, 
    m_isVisible{ isVisible } 
{}



int GameObject::GetXStart() const { return m_x; }
void GameObject::SetXStart(int xStart) { m_x = xStart; }

void GameObject::SetTextColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int GameObject::GetYStart() const { return m_y; }
void GameObject::SetYStart(int yStart) { m_y = yStart; }

int GameObject::GetId() const { return m_id; }
void GameObject::SetId(int id) { m_id = id; }

bool GameObject::IsBreakable() const { return m_isBreakable; }
void GameObject::SetBreakable(bool isBreakable) { m_isBreakable = isBreakable; }

bool GameObject::IsVisible() const { return m_isVisible; }
void GameObject::SetVisible(bool isVisible) { m_isVisible = isVisible; }
