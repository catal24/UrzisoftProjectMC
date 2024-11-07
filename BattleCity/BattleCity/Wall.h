#pragma once
#include <iostream>

class Wall
{
public:
	Wall() = default;
	Wall(bool isDestructible, bool hasBomb = false);

	bool IsDestructible()const;
	bool HasBomb()const;

	void SetDestructible(bool destructible);
	void SetBomb(bool hasBomb);

private:
	bool m_isDestructible;
	bool m_hasBomb;
};