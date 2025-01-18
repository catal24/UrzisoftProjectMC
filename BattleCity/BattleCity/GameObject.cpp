#include "GameObject.h"


GameObject::GameObject(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible)
    :m_xStart{xStart},
    m_yStart{yStart},
    m_x{x},
    m_y{y},
    m_id{id},
    m_isBreakable{isBreakable},
    m_isVisible{isVisible}
{}

int GameObject::GetXStart() const { return m_xStart; }
void GameObject::SetXStart(int xStart) { m_xStart = xStart; }

void GameObject::SetTextColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int GameObject::GetYStart() const { return m_yStart; }
void GameObject::SetYStart(int yStart) { m_yStart = yStart; }

int GameObject::GetX() const
{
    return m_x;
}

void GameObject::SetX(int x)
{
    m_x = x;
}

int GameObject::GetY() const
{
    return m_y;
}

void GameObject::SetY(int y)
{
    m_y = y;
}

int GameObject::GetId() const { return m_id; }
void GameObject::SetId(int id) { m_id = id; }

bool GameObject::IsBreakable() const { return m_isBreakable; }
void GameObject::SetBreakable(bool isBreakable) { m_isBreakable = isBreakable; }

bool GameObject::IsVisible() const { return m_isVisible; }
void GameObject::SetVisible(bool isVisible) { m_isVisible = isVisible; }
