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
				m_map[i][j] = new Road{ i,j,0,false,true };
				m_numberOfRoads++;
			}
			else
			{
				m_map[i][j] = new Wall{ i,j,0,true,true,false };
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

void Map::DrawMap()
{

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (m_map[i][j]->IsVisible())
				m_map[i][j]->Draw();
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<GameObject*>>& Map::GetMap()
{
	return m_map;
}

void Map::GenerateRandomBombsOnWalls(int numBombs)
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
					m_map[i][j] = new Bomb{ i, j, 0, true, true, 1 };
					count++;
				}
			}
		}
	}
}


void Map::GenerateRandomIndestructibleWalls(int count)
{
	int modified = 0;

	while (modified < count) {
		int x = rand() % m_height; // pozitie aleatorie pentru x
		int y = rand() % m_width;  // pozitie aleatorie pentru y

		//verificam daca este destructibil deja
		Wall* wall = dynamic_cast<Wall*>(m_map[x][y]);
		if (wall && wall->IsBreakable()) {
			wall->SetBreakable(false); // il facem indestructibil
			++modified;
		}
	}

}

void Map::SetIndestructibleBorders()
{
	for (int i = 0; i < m_height; i++)
		for (int j = 0; j < m_width; j++)
			if (i == 0 || i == m_height - 1 || j == 0 || j == m_width - 1)
			{
				Wall* wall = dynamic_cast<Wall*>(m_map[i][j]);
				if (wall && wall->IsBreakable())
					wall->SetBreakable(false);

			}
}


GameObject* Map::GetObjectAt(int x, int y)
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



int Map::GetWidth() { return m_width; }
int Map::GetHeight() { return m_height; }
int Map::GetNumberOfRoads() { return m_numberOfRoads; }
int Map::GetNumberOfWalls() { return m_numberOfWalls; }

void Map::SetWidth(int width) { m_width = width; }
void Map::SetHeight(int height) { m_height = height; }
void Map::SetNumberOfRoads(int numberOfRoads) { m_numberOfRoads = numberOfRoads; }
void Map::SetNumberOfWalls(int numberOfWalls) { m_numberOfWalls = numberOfWalls; }

