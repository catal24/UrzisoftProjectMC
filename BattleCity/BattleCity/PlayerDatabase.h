#pragma once
#include <sqlite_orm/sqlite_orm.h>
#include <string>
#include <vector>
#include "Player.h"
#include "Vehicle.h"

namespace sql = sqlite_orm;
namespace http
{
	inline auto CreateStorage(const std::string& filename)
	{
		return sql::make_storage(
			filename,
			sql::make_table(
				"Player",
				//&UsersEntity::SetUsername, &UsersEntity::GetUsername
				sql::make_column("id", &Player::SetId, &Player::GetId, sql::primary_key().autoincrement()),
				sql::make_column("name", &Player::SetName, &Player::GetName),
				sql::make_column("credits",&Player::SetCredits,&Player::GetCredits),
				sql::make_column("rank",&Player::SetRank,&Player::GetRank)
			
			)
			
		);
	}
	using Storage = decltype(CreateStorage(""));
	class PlayerDatabase
	{
	private:
		const std::string kDbFile{ "Players.sqlite" };

	private:
		Storage m_db = CreateStorage(kDbFile);
	};
}
