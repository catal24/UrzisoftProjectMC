#pragma once
#include "GameObject.h"
#include "Bullet.h"
class Tank :public GameObject
{
public:
	Tank(int xStart, int yStart, int id, bool isBreakable, bool isVisible, int lives=3, int speed=5, bool isDead = false);

	Tank();

	~Tank() {}
	
	void SetSpeed(int amount);
	void SetLives(int amount);
	void SetIsDead();
	int GetSpeed()const;
	int GetLives()const;
	bool GetIsDead()const;
	void die();
	void respawn();
	void draw(int xStart,int yStart);


	private:
	int m_lives;
	int m_speed;
	bool m_isDead;
	Bullet m_bullet;
	


};

