export module map;
import <iostream>;
import <array>;
import <optional>;

export import "Tank.h";

namespace battlecity
{
	export class Map
	{
	public:
		static const size_t kWidth{ 600 };
		static const size_t kHeight{ 400 };
		using Position = std::pair<size_t, size_t>;

	public:
		Map() = default;

		//getter
		const std::optional<Tank> &operator [](const Position& position)const;
		//getter and/or setter
		std::optional<Tank> &operator [](const Position& position);

		int GetNumberOfWalls();

		int SetNumberOfWalls(int numberOfWalls);

	private:
		static const size_t kSize{ kWidth * kHeight };
		std::array<std::optional<Tank>, kSize> m_tanks;
	};

	export std::ostream& operator <<(std::ostream& out, const Tank& board);

}
