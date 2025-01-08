#pragma once
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

#include <sqlite_orm/sqlite_orm.h>
#include <string>
#include <vector>
#include "Player.h"
#include "Vehicle.h"


namespace sql = sqlite_orm;
inline auto CreateStorage(const std::string& filename)
{
	auto storage =
		sql::make_storage(
			filename,
			sql::make_table(
				"Vehicle",
				sql::make_column("id", &Vehicle::SetId, &Vehicle::GetId, sql::primary_key().autoincrement()),
				sql::make_column("speed", &Vehicle::SetSpeed, &Vehicle::GetSpeed)
			),
			sql::make_table(
				"Player",
				sql::make_column("id", &Player::SetId, &Player::GetId, sql::primary_key().autoincrement()),
				sql::make_column("name", &Player::SetName, &Player::GetName),
				sql::make_column("credits", &Player::SetCredits, &Player::GetCredits),
				sql::make_column("rank", &Player::SetRank, &Player::GetRank)
				//sql::make_column("vehicle_id", &Player::SetVehicleId, &Player::GetVehicleId,
				//	sql::foreign_key(&Player::SetVehicleId)
				//	.references(&Vehicle::SetId)
				//	.on_update.cascade()
				//	.on_delete.set_null()) // Dacă un vehicul este șters, vehiculul din `Player` devine NULL.
			)
		
		);
	storage.sync_schema();
	return storage;
}

using Storage = decltype(CreateStorage(""));

class PlayerDatabase
{
private:
	const std::string kDbFile{ "Players.sqlite" };

private:
	Storage m_db = CreateStorage(kDbFile);
};
