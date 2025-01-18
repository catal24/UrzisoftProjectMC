#pragma once
#include<iostream>
#include <windows.h>
class GameObject
{

public:
    GameObject() = default;
    GameObject(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible);

    int GetXStart() const;
    void SetXStart(int xStart);
    void SetTextColor(int color);

    int GetYStart() const;
    void SetYStart(int yStart);

    int GetX()const;
    void SetX(int x);

    int GetY()const;
    void SetY(int y);

    int GetId() const;
    void SetId(int id);

    bool IsBreakable() const;
    void SetBreakable(bool isBreakable);

    bool IsVisible() const;
    void SetVisible(bool isVisible);

   virtual void Draw()=0;

protected:
	int m_x;
	int m_y;
    int m_xStart;
    int m_yStart;
	int m_id;
	bool m_isBreakable;
	bool m_isVisible;

};

