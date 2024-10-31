#pragma once
#include "GameObject.h"
class Tank :public GameObject
{
public:
	Tank(int xStart, int yStart, int id, bool isBreakable, bool isVisible,int lives, int speed, bool isDead=false);

	~Tank();
	
	void setSpeed(int amount);
	void setLives(int amount);
	void setIsDead();
	int getSpeed()const;
	int getLives()const;
	bool getIsDead()const;
	void die();
	void respawn();
	


	private:
	int m_lives;
	int m_speed;
	bool m_isDead;
	


};

