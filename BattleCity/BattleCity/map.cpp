module map;
using namespace battlecity;

const std::optional<Tank>& Map::operator[](const Position& position) const
{
	const auto& [line, column] = position;
	return m_tanks[line * kWidth + column];
}

std::optional<Tank>& battlecity::Map::operator[](const Position& position)
{
	return const_cast<std::optional<Tank>&>(std::as_const(*this)[position]);
}

int battlecity::Map::GetNumberOfWalls()
{
	return m_numberOfWalls;
}

int battlecity::Map::SetNumberOfWalls(int numberOfWalls)
{
	m_numberOfWalls = numberOfWalls;
}


std::ostream& operator<<(std::ostream& out, const Tank& board)
{
	// TODO: insert return statement here
}