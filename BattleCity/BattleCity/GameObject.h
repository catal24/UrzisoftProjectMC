#pragma once
#include<iostream>
#include <windows.h>
#include <cstdint>
class GameObject
{

public:
    GameObject() = default;
    GameObject(uint8_t xStart, uint8_t yStart, int id, bool isBreakable, bool isVisible);

    uint8_t GetXStart() const;
    void SetXStart(uint8_t xStart);
    void SetTextColor(int color);

    uint8_t GetYStart() const;
    void SetYStart(uint8_t yStart);

    int GetId() const;
    void SetId(int id);

    bool IsBreakable() const;
    void SetBreakable(bool isBreakable);

    bool IsVisible() const;
    void SetVisible(bool isVisible);

   virtual void Draw()=0;

protected:
	uint8_t m_x;
    uint8_t m_y;
	int m_id;
	bool m_isBreakable;
	bool m_isVisible;

};

