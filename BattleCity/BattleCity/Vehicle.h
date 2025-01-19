#pragma once
import axis;
#include "GameObject.h"
#include "Bullet.h"
#include <vector>
#include <memory>
class Vehicle :public GameObject
{
public:
	
	Vehicle(int xStart, int yStart, int x, int y, int id, bool isBreakable, bool isVisible, int lives=3, int speed=5, bool isDead = false, Axis axis=Axis::left,int playerid=0);

	Vehicle() = default;

	~Vehicle() {}
	
	

	std::shared_ptr<Bullet> ShootBullet(int x, int y);

	void SetAxis(char ax);

	void SetSpeed(int amount);
	void SetLives(int amount);
	void SetIsDead(bool flag);
	int GetSpeed()const;
	int GetLives()const;
	bool GetIsDead()const;
	Axis GetAxis()const;
	std::vector<std::pair<int, int>> GetStartingPositions();
	void Draw()override;
	int GetPlayerId() const;
	void SetPlayerId(int playerid);
private:
	int m_id;
	int m_playerid;
	int m_x;
	int m_y;
	int m_xStart;
	int m_yStart;
	Axis m_axis;
	int m_lives;
	int m_speed;
	bool m_isDead;
	std::vector<std::pair<int, int>> m_startingPositions;

};

