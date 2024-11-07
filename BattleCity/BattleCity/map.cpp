#include "Map.h";

void setTextColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

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
			if (m_map[i][j] == (char)254u)
			{
				setTextColor(3);
				std::cout << m_map[i][j];
				setTextColor(7);
			}
			else
				std::cout << m_map[i][j];
		}
		std::cout << std::endl;
	}
}

void Map::addTank(Tank t)
{
	
	int x = t.getXStart()-1;
	int y = t.getYStart()-1;
	m_map[x+1][y+1] = (char)254u;
	m_map[x+2][y+2] = (char)254u;
	m_map[x+0][y+0] = (char)254u;
	m_map[x+0][y+2] = (char)254u;
	m_map[x+0][y+1] = (char)254u;
	m_map[x+2][y+1] = (char)254u;
	m_map[x+1][y+2] = (char)254u;
	m_map[x+1][y+0] = (char)254u;
	m_map[x+2][y+0] = (char)254u;
	if(t.GetAxis()==Axis::right)
		m_map[x+1][y+3] = (char)254u;
	else if (t.GetAxis() == Axis::left)
		m_map[x + 1][y - 1] = (char)254u;
	else if (t.GetAxis() == Axis::down)
		m_map[x + 3][y +1] = (char)254u;
	else if (t.GetAxis() == Axis::up)
		m_map[x - 1][y + 1] = (char)254u;

}

