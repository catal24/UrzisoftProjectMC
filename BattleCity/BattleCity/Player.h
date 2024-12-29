#pragma once
#include <string>
#include "Vehicle.h"
class Player
{public:
	Player(std::string name, int id, int credits=0, int rank=0);
	~Player() = default;

	void SetName(std::string name);
	void SetId(int id);
	void SetCredits(int credits);
	void SetRank(int rank);
	std::string GetName(std::string name)const;
	int GetId(int id)const;
	int GetCredits(int credits)const;
	int GetRank(int rank)const;

	private:
	std::string m_name;
	int m_id;
	int m_credits;
	int m_rank;
	Vehicle m_tank;
};

