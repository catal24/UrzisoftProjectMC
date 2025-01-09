#pragma once
#include "GameObject.h"
#include <iostream>

class Wall : public GameObject
{
public:
	
	Wall(uint8_t xStart, uint8_t yStart, int id, bool isBreakable, bool isVisible, bool hasBomb);

	bool HasBomb()const;

	void SetDestructible(bool isBreakable);
	void SetBomb(bool hasBomb);
	

	bool IsBreakable() const;
	void SetBreakable(bool isBreakable);

	bool IsVisible() const;
	void SetVisible(bool isVisible);

	void Draw()override;

private:
	int m_id;
	uint8_t m_xStart;
	uint8_t m_yStart;
	bool m_isVisible;
	bool m_isBreakable;
	bool m_hasBomb;
};