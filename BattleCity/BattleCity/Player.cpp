#include "Player.h"
#include "Vehicle.h"
Player::Player(std::string name, int id, int credits, int rank):
	m_name{ name },
	m_id{ id },
	m_credits{ credits },
	m_rank{rank}, 
	m_v{ 0,0,0,0,1,false,true }
{}

void Player::SetName(std::string name)	{m_name = name;}

void Player::SetId(int id)	{m_id = id;}

void Player::SetCredits(int credits)	{m_credits = credits;}

void Player::SetRank(int rank)	{m_rank = rank;}

std::string Player::GetName() const	 {return m_name;}

int Player::GetId() const	 {return m_id;}

int Player::GetCredits() const  {return m_credits;}

int Player::GetRank() const  {return m_rank;}


