#pragma once
#include<iostream>
#include <windows.h>
class GameObject
{

public:
    GameObject() = default;
    GameObject(int xStart, int yStart, int id, bool isBreakable, bool isVisible);

    int getXStart() const;
    void setXStart(int xStart);
    void setTextColor(int color);

    int getYStart() const;
    void setYStart(int yStart);

    int getId() const;
    void setId(int id);

    bool isBreakable() const;
    void setBreakable(bool isBreakable);

    bool isVisible() const;
    void setVisible(bool isVisible);

   virtual void draw()=0;

protected:
	int m_x;
	int m_y;
	int m_id;
	bool m_isBreakable;
	bool m_isVisible;

};

