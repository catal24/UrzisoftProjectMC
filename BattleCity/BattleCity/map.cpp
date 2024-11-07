#include "Map.h";

void setTextColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

Map::Map(int width, int height)
{

	/*
	aici se va citi din fisier o matrice si pe baza matricei
	celulele cu 0 vor fi initializate ca obiecte din clasa Road
	iar celulele corespunzatoare cu 1 voar fi initializate cu ob din clasa Wall

	*/
	m_width = width;
	m_height = height;



}

void Map::drawMap()
{

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (m_map[i][j]->isVisible())
				m_map[i][j]->draw();
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}
}

