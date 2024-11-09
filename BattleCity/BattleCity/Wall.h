#pragma once
#include "GameObject.h"
#include <iostream>

class Wall : public GameObject
{
public:
	
	Wall(int id = 0, int xStart = 0, int yStart = 0, bool isVisible = true, bool isBreakable = true, bool hasBomb = false);

	bool IsBreakable()const;
	bool HasBomb()const;

	void SetDestructible(bool isBreakable);
	void SetBomb(bool hasBomb);

	int getXStart() const;
	void setXStart(int xStart);

	int getYStart() const;
	void setYStart(int yStart);

	int getId() const;
	void setId(int id);

	bool isBreakable() const;
	void setBreakable(bool isBreakable);

	bool isVisible() const;
	void setVisible(bool isVisible);

	void draw()override;

private:
	int m_id;
	int m_xStart;
	int m_yStart;
	bool m_isVisible;
	bool m_isBreakable;
	bool m_hasBomb;
};