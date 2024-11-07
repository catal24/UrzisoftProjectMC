#include "Map.h";


Map::Map(int width, int height)
{
	m_width = width;
	m_height = height;
	m_map.resize(height);
	
	for (int i = 0; i < height; i++)
	{
		m_map[i].resize(width);
		
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == (height - 1) || j == 0 || j == (width - 1))
			{
				m_map[i][j] = '#';
			}
			else
				m_map[i][j] = ' ';
		}
	}
	
}

void Map::drawMap()
{
	
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			
			std::cout << m_map[i][j];
		}
		std::cout << std::endl;
	}
}

