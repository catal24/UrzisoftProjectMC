#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "Axis.h"
class Tank :public GameObject
{
public:
	
	Tank(int xStart, int yStart, int id, bool isBreakable, bool isVisible, int lives=3, int speed=5, bool isDead = false, Axis axis=left);

	Tank();

	~Tank() {}
	
	


	void SetSpeed(int amount);
	void SetLives(int amount);
	void SetIsDead();
	void moveTank(char dir);
	int GetSpeed()const;
	int GetLives()const;
	bool GetIsDead()const;
	Axis GetAxis()const;
	void die();
	void respawn();
	void draw(int xStart,int yStart);


	private:
	Axis m_axis;
	int m_lives;
	int m_speed;
	bool m_isDead;
	Bullet m_bullet;
	


};

