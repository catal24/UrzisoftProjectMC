#pragma once
#include "GameObject.h"
#include <iostream>

class Wall : public GameObject
{
public:
	
	Wall(int xStart, int yStart, int id, bool isBreakable, bool isVisible, bool hasBomb);

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