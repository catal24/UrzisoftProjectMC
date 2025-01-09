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
	std::string GetName()const;
	int GetId()const;
	int GetCredits()const;
	int GetRank()const;

	private:
	std::string m_name;
	int m_id;
	int m_credits;
	int m_rank;
	Vehicle m_v;
};

