#include "Player.h"
#include "Vehicle.h"
Player::Player(std::string name, int id, int credits, int rank):
	m_name(name), 
	m_id(id),
	m_credits(credits),
	m_rank(rank), 
	m_tank(0,0,1,false,true)
{}

void Player::SetName(std::string name)
{
	m_name = name;
}

void Player::SetId(int id)
{
	m_id = id;
}

void Player::SetCredits(int credits)
{
	m_credits = credits;
}

void Player::SetRank(int rank)
{
	m_rank = rank;
}

std::string Player::GetName(std::string name) const
{
	return m_name;
}

int Player::GetId(int id) const
{
	return m_id;
}

int Player::GetCredits(int credits) const
{
	return m_credits;
}

int Player::GetRank(int rank) const
{
	return m_rank;
}


