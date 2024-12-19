#pragma once
#include <sqlite_orm/sqlite_orm.h>

namespace sql = sqlite_orm;

class PlayerDatabase
{
private:
	const std::string kDbFile{ "Players.sqlite" };

private:
	//Storage m_db = CreateStorage(kDbFile);
};

