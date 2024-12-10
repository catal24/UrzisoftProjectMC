    #include "GameScene.h"

    void MoveCursor(int x, int y) {
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

    void GameScene::ClearConsole() {
        system("cls");
    }

    GameScene::GameScene(std::vector<std::vector<int>> m)
        : m_map{ m }
    {
    
    }

    void GameScene::AddObj(GameObject* obj)
    {
        m_map.GetMap()[obj->GetXStart()][obj->GetYStart()] = obj;
    
    }

    void GameScene::RemoveObj(int x,int y)
    {   
        MoveCursor(y, x);
   
        m_map.GetMap()[x][y] = nullptr;
        m_map.GetMap()[x][y] = new Road{x,y,0,false,true};
        m_map.GetMap()[x][y]->Draw();
    }

    bool GameScene::CheckObj(int x, int y)
    {
        if (x < 0 || x >= m_map.GetHeight() || y < 0 || y >= m_map.GetWidth()) {
            return false; // poz este in afara hartii
        }

        if (typeid(*m_map.GetMap()[x][y]) == typeid(Road)) {
            return true; // este liber
        }

        return false;
    }

    void GameScene::MoveObject(GameObject* obj, int x, int y)
    {
        if (CheckObj(x, y))
        {
            RemoveObj(obj->GetXStart(), obj->GetYStart());

            m_map.GetMap()[x][y] = obj;
            MoveCursor(y, x);
            m_map.GetMap()[x][y]->Draw();
            obj->SetXStart(x);
            obj->SetYStart(y);
       
            if (Vehicle* vehicle = dynamic_cast<Vehicle*>(obj)) {
                // Setăm coordonatele specifice vehiculului
                vehicle->SetX(x);
                vehicle->SetY(y);

                // Mesaj de debugging pentru a verifica setarea corectă
                //std::cout << "Vehicle moved to new position: (" << vehicle->GetX() << ", " << vehicle->GetY() << ")" << std::endl;
            }

            if (Bullet* bullet = dynamic_cast<Bullet*>(obj)) {
                bullet->SetXStart(x);
                bullet->SetYStart(y);
            }
           GetMap().EncodeMap();


        }
        else
        {
            /*aici vom trata ce se intampla cand obiectul nostru interactioneaza cu un alt obiect*/
        }
    }

    void GameScene::DrawTest(Game g)
    {
        ClearConsole();
        m_map.SetIndestructibleBorders();
        int indestructibleWallCount = 0;
        switch (g.GetDifficulty())
        {
        case Game::Difficulty::EASY:
            m_map.GenerateRandomBombsOnWalls(7);
            indestructibleWallCount = 5;
            break;
        case Game::Difficulty::MEDIUM:
            m_map.GenerateRandomBombsOnWalls(10);
            indestructibleWallCount = 10;
            break;
        case Game::Difficulty::HARD:
            m_map.GenerateRandomBombsOnWalls(15);
            indestructibleWallCount = 15;
            break;
        case Game::Difficulty::EXTREME:
            m_map.GenerateRandomBombsOnWalls(20);
            indestructibleWallCount = 20;
            break;
        default:
            break;
        }
        m_map.GenerateRandomIndestructibleWalls(indestructibleWallCount);
        m_map.DrawMap();
    }

    void GameScene::DrawQueue(std::queue<GameObject*>& q)
    {
        q.front()->Draw();
        q.pop();
    }

    std::vector<std::pair<int,int>> GameScene::GetStartingPositions()
	{
		return m_startingPositions;
	
    }

    GameObject* GameScene::GetObjectAt(int x, int y)
    {
        if (x >= 0 && x < m_map.GetHeight() && y >= 0 && y < m_map.GetWidth()) {
            return m_map[x][y];
        }
        return nullptr;
    }

    Map& GameScene::GetMap()
    {
        return m_map;
    }

    void GameScene::RespawnObj(Vehicle* obj, int x, int y)
    {
        if (obj->GetLives())
        {
            MoveObject(obj, x, y);
            int lives = obj->GetLives();
            lives--;
            obj->SetLives(lives);
        }
        else
        {
            RemoveObj(obj->GetX(),obj->GetY());
            obj->SetIsDead(true);
        }
    }

  