#include "Map.h"
#include "Road.h"
#include "Bomb.h"
#include <ctime>

void setTextColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

Map::Map(std::vector<std::vector<int>> mat)
{
	m_width = mat.size();
	m_height = mat[0].size();
	m_map.resize(mat.size());
	
	for (int i = 0; i < m_height; i++)
	{
		m_map[i].resize(m_width);
		for (int j = 0; j < m_width; j++)
		{
			if (mat[i][j] == 0)
			{
				m_map[i][j] = new Road;
				m_numberOfRoads++;
			}
			else
			{
				m_map[i][j] = new Wall;
				m_numberOfWalls++;
			}
		}
	}
	/*
	aici se va citi din fisier o matrice si pe baza matricei
	celulele cu 0 vor fi initializate ca obiecte din clasa Road
	iar celulele corespunzatoare cu 1 voar fi initializate cu ob din clasa Wall

	*/
	


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

std::vector<std::vector<GameObject*>>& Map::getMap()
{
	return m_map; 
}

void Map::generateRandomBombsOnWalls(int numBombs)
{
	srand(time(nullptr));

	int count = 0;
	while (count < numBombs)
	{
		int i = rand() % m_height;
		int j = rand() % m_width;

		// verificam sa nu fie pe bordura matricei
		if (i > 0 && i < m_height - 1 && j > 0 && j < m_width - 1)
		{
			// verificam daca este perete si nu are bomba
			if (dynamic_cast<Wall*>(m_map[i][j]) != nullptr && dynamic_cast<Bomb*>(m_map[i][j]) == nullptr)
			{
				bool hasAdjacentRoad = false; // verificam daca are drum invecinat

				if (i > 0 && dynamic_cast<Road*>(m_map[i - 1][j]) != nullptr)
					hasAdjacentRoad = true; // sus
				if (i < m_height - 1 && dynamic_cast<Road*>(m_map[i + 1][j]) != nullptr)
					hasAdjacentRoad = true; // jos
				if (j > 0 && dynamic_cast<Road*>(m_map[i][j - 1]) != nullptr)
					hasAdjacentRoad = true; // stanga
				if (j < m_width - 1 && dynamic_cast<Road*>(m_map[i][j + 1]) != nullptr)
					hasAdjacentRoad = true; // dreapta

				if (hasAdjacentRoad)
				{
					delete m_map[i][j];
					m_map[i][j] = new Bomb(i, j, 0, false, true, 1);
					count++;
				}
			}
		}
	}
}


void Map::generateRandomIndestructibleWalls(int count)
{
	int modified = 0;

	while (modified < count) {
		int x = rand() % m_height; // pozitie aleatorie pentru x
		int y = rand() % m_width;  // pozitie aleatorie pentru y

		//verificam daca este destructibil deja
		Wall* wall = dynamic_cast<Wall*>(m_map[x][y]);
		if (wall && wall->isBreakable()) {
			wall->setBreakable(false); // il facem indestructibil
			++modified;
		}
	}

}

void Map::setIndestructibleBorders()
{
	for (int i = 0; i < m_height; i++)
		for (int j = 0; j < m_width; j++)
			if (i == 0 || i == m_height - 1 || j == 0 || j == m_width - 1)
				m_map[i][j] = new Wall(0, i, j, true, false,false);
}


GameObject* Map::getObjectAt(int x, int y)
{
	if (x >= 0 && x < m_height && y >= 0 && y < m_width) {
		return m_map[x][y]; // returnam obiectul de pe pozitia (x, y)
	}
	return nullptr;
}

std::vector<GameObject*>& Map::operator[](int index)
{
	return m_map[index];
}

const std::vector<GameObject*>& Map::operator[](int index) const
{
	return m_map[index];
}



int Map::GetWidth()
{
	return m_width;
}

int Map::GetHeight()
{
	return m_height;
}

int Map::GetNumberOfRoads()
{
	return m_numberOfRoads;
}

int Map::GetNumberOfWalls()
{
	return m_numberOfWalls;
}

void Map::SetWidth(int width)
{
	m_width = width;
}

void Map::SetHeight(int height)
{
	m_height = height;
}

void Map::SetNumberOfRoads(int numberOfRoads)
{
	m_numberOfRoads = numberOfRoads;
}

void Map::SetNumberOfWalls(int numberOfWalls)
{
	m_numberOfWalls = numberOfWalls;
}

