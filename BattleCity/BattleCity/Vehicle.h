#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "Axis.h"
#include <vector>
#include <memory>
class Vehicle :public GameObject
{
public:
	
	Vehicle(int xStart, int yStart, int id, bool isBreakable, bool isVisible, int lives=3, int speed=5, bool isDead = false, Axis axis=Axis::left);

	Vehicle() = default;

	~Vehicle() {}
	
	

	std::shared_ptr<Bullet> shootBullet(int x, int y);

	void setAxis(char ax);

	void SetSpeed(int amount);
	void SetLives(int amount);
	void SetIsDead();
	void SetX(int x);
	void SetY(int y);
	void moveTank(char dir);
	int GetSpeed()const;
	int GetX();
	int GetY();
	int GetLives()const;
	bool GetIsDead()const;
	Axis GetAxis()const;
	void die();
	void respawn();
	std::vector<std::pair<int, int>> GetStartingPositions();
	void draw()override;


private:
	int m_x;
	int m_y;
	Axis m_axis;
	int m_lives;
	int m_speed;
	bool m_isDead;
	std::vector<std::pair<int, int>> m_startingPositions = { {1,1},{18,18},{1,18},{18,1} };

};

