#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "Axis.h"
#include <vector>
#include <memory>
class Vehicle :public GameObject
{
public:
	
	Vehicle(int xStart, int yStart, int id, bool isBreakable, bool isVisible, int lives=3, int speed=5, bool isDead = false, Axis axis=Axis::left,int playerid=0);

	Vehicle() = default;

	~Vehicle() {}
	
	std::shared_ptr<Bullet> ShootBullet(int x, int y);

	void SetAxis(char ax);

	void SetSpeed(int amount);
	void SetLives(int amount);
	void SetIsDead(bool flag);
	void SetX(int x);
	void SetY(int y);
	int GetSpeed()const;
	uint8_t GetX();
	uint8_t GetY();
	uint8_t GetLives()const;
	bool GetIsDead()const;
	Axis GetAxis()const;
	std::vector<std::pair<uint8_t, uint8_t>> GetStartingPositions();
	void Draw()override;
	void SetId(int id);
	int GetId() const;
	int GetPlayerId() const;
	void SetPlayerId(int playerid);
private:
	int m_id;
	int m_playerid;
	uint8_t m_x;
	uint8_t m_y;
	Axis m_axis;
	uint8_t m_lives;
	int m_speed;
	bool m_isDead;
	std::vector<std::pair<uint8_t, uint8_t>> m_startingPositions = { {1,1},{18,18},{1,18},{18,1} };// in constructor default

};

