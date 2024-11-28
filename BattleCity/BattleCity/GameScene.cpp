    #include "GameScene.h"

    void moveCursor(int x, int y) {
        // Make the cursor invisible
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = FALSE; 
        SetConsoleCursorInfo(hConsole, &cursorInfo);
        //Go to x, y position to draw
        COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    }

    void clearConsole() {
        system("cls");
    }

    GameScene::GameScene(std::vector<std::vector<int>> m)
        : m_map{ m }
    {
    
    }

    void GameScene::addObj(GameObject* obj)
    {
        m_map.getMap()[obj->getXStart()][obj->getYStart()] = obj;
    
    }

    void GameScene::removeObj(int x,int y)
    {   
        moveCursor(y, x);
   
        m_map.getMap()[x][y] = nullptr;
        m_map.getMap()[x][y] = new Road{x,y,0,false,true};
        m_map.getMap()[x][y]->draw();
    }

    bool GameScene::checkObj(int x, int y)
    {
        if (x < 0 || x >= m_map.GetHeight() || y < 0 || y >= m_map.GetWidth()) {
            return false; // poz este in afara hartii
        }

        if (typeid(*m_map.getMap()[x][y]) == typeid(Road)) {
            return true; // este liber
        }

        return false;
    }

    void GameScene::moveObject(GameObject* obj, int x, int y)
    {
        if (checkObj(x, y))
        {
            removeObj(obj->getXStart(), obj->getYStart());

            m_map.getMap()[x][y] = obj;
            moveCursor(y, x);
            m_map.getMap()[x][y]->draw();
            obj->setXStart(x);
            obj->setYStart(y);
       
            if (Vehicle* vehicle = dynamic_cast<Vehicle*>(obj)) {
                // Setăm coordonatele specifice vehiculului
                vehicle->SetX(x);
                vehicle->SetY(y);

                // Mesaj de debugging pentru a verifica setarea corectă
                //std::cout << "Vehicle moved to new position: (" << vehicle->GetX() << ", " << vehicle->GetY() << ")" << std::endl;
            }

            if (Bullet* bullet = dynamic_cast<Bullet*>(obj)) {
                bullet->setXStart(x);
                bullet->setYStart(y);
            }

        }
        else
        {
            /*aici vom trata ce se intampla cand obiectul nostru interactioneaza cu un alt obiect*/
        }
    }

    void GameScene::drawTest(Game g)
    {
        clearConsole();
        m_map.setIndestructibleBorders();
        int indestructibleWallCount = 0;
        switch (g.GetDifficulty())
        {
        case Game::Difficulty::EASY:
            m_map.generateRandomBombsOnWalls(7);
            indestructibleWallCount = 5;
            break;
        case Game::Difficulty::MEDIUM:
            m_map.generateRandomBombsOnWalls(10);
            indestructibleWallCount = 10;
            break;
        case Game::Difficulty::HARD:
            m_map.generateRandomBombsOnWalls(15);
            indestructibleWallCount = 15;
            break;
        case Game::Difficulty::EXTREME:
            m_map.generateRandomBombsOnWalls(20);
            indestructibleWallCount = 20;
            break;
        default:
            break;
        }
        m_map.generateRandomIndestructibleWalls(indestructibleWallCount);
        m_map.drawMap();
    }

    void GameScene::drawQueue(std::queue<GameObject*>& q)
    {
        q.front()->draw();
        q.pop();
    }

    std::vector<std::pair<int,int>> GameScene::GetStartingPositions()
	{
		return m_startingPositions;
	
    }

    GameObject* GameScene::getObjectAt(int x, int y)
    {
        if (x >= 0 && x < m_map.GetHeight() && y >= 0 && y < m_map.GetWidth()) {
            return m_map[x][y];
        }
        return nullptr;
    }

    void GameScene::respawnObj(Vehicle* obj, int x, int y)
    {
        if (obj->GetLives())
        {
            moveObject(obj, x, y);
            int lives = obj->GetLives();
            lives--;
            obj->SetLives(lives);
        }
        else
        {
            removeObj(obj->GetX(),obj->GetY());
            obj->SetIsDead(true);
        }
    }

  