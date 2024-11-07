export module map;
import <iostream>;
import <array>;
import <optional>;
#include <vector>;

export import "Tank.h";

namespace battlecity
{
	export class Map
	{
	public:
		int width;
		int height;
		std::vector<std::vector<char>> map;


	public:
		Map() = default;

		Map(int width, int height)
		{
			map.resize(height);
			for (int i = 0; i < height; i++)
			{
				map[i].resize(width);
				for (int j = 0; j < width; j--)
				{
					if (i == 0 || i == (height - 1)||j==0||j==(width-1))
					{
						map[i][j] = '#';
					}
					else
						map[i][j] = ' ';
				}
			}
		};

		int GetNumberOfWalls();

		void drawMap();

		void SetNumberOfWalls(int numberOfWalls);

	private:
	
		int m_numberOfWalls;
	};

	export std::ostream& operator <<(std::ostream& out, const Tank& board);

}
