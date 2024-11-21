#include "Game.h"


Game::Game(std::vector<std::vector<int>> m_initMap, Difficulty difficulty)
    :m_scene{ new GameScene{m_initMap} }, m_playerCount{ 1 }, m_difficulty{ difficulty }
{
    m_v = { m_scene->GetStartingPositions()[m_playerCount-1].first, 
        m_scene->GetStartingPositions()[m_playerCount-1].second,0,false,true};
    m_scene->addObj(&m_v);
}
//spawn the vehicle at a dafault location
void Game::startGame()
{
    bool isStart = true;
    std::queue<GameObject*> q;
    m_scene->drawTest(*this);

    unsigned long lastShotTime = 0;  // Timpul ultimei trageri
    const unsigned long shootDelay = 500; // Delay de 500ms între trageri

    while (isStart) {
        Sleep(50);  // Sleep pentru a controla viteza jocului

        // Controlul jucătorului
        if (_kbhit()) {
            char key = _getch();
            if (key == 'w' || key == 'W') {
                m_scene->moveObject(&m_v, m_v.getXStart() - 1, m_v.getYStart());
                m_v.setAxis(key);

            }
            else if (key == 's' || key == 'S') {
                m_scene->moveObject(&m_v, m_v.getXStart() + 1, m_v.getYStart());
                m_v.setAxis(key);

            }
            else if (key == 'a' || key == 'A') {
                m_scene->moveObject(&m_v, m_v.getXStart(), m_v.getYStart() - 1);
                m_v.setAxis(key);

            }
            else if (key == 'd' || key == 'D') {
                m_scene->moveObject(&m_v, m_v.getXStart(), m_v.getYStart() + 1);
                m_v.setAxis(key);

            }
            else if (key == ' ') {
                unsigned long currentTime = GetTickCount();
                if (currentTime - lastShotTime >= shootDelay) {
                    bullets.push_back(m_v.shootBullet());
                    lastShotTime = currentTime; // Actualizăm timpul ultimei trageri
                }
            }
        }

        // Mișcarea gloanțelor
        for (auto it = bullets.begin(); it != bullets.end();) {
            int newX = it->getXStart();
            int newY = it->getYStart();

            // Determinarea direcției glonțului
            switch (it->getAxis()) {
            case Axis::up:    newX--; break;
            case Axis::down:  newX++; break;
            case Axis::left:  newY--; break;
            case Axis::right: newY++; break;
            }


            // verificarea coliziunilor
            if (m_scene->checkObj(newX, newY)) {

                // daca nu loveste nimic mutam glontul
                m_scene->moveObject(&(*it), newX, newY);
                it->setXStart(newX); // actualizare pozitie glont
                it->setYStart(newY);
                ++it;

            }
            else {
                // daca loveste tanc
                if (dynamic_cast<Vehicle*>(m_scene->getObjectAt(newX, newY)) != nullptr) {
                    m_scene->removeObj(newX, newY); //stergem tancu
                    if (!dynamic_cast<Vehicle*>(m_scene->getObjectAt(it->getXStart(), it->getYStart())))
                        m_scene->removeObj(it->getXStart(), it->getYStart());
                    it = bullets.erase(it);
                    continue;
                }

                // daca loveste alt glont
                if (dynamic_cast<Bullet*>(m_scene->getObjectAt(newX, newY)) != nullptr) {
                    m_scene->removeObj(newX, newY); //stergem glontu inamicului/al nostru
                    if (!dynamic_cast<Vehicle*>(m_scene->getObjectAt(it->getXStart(), it->getYStart())))
                        m_scene->removeObj(it->getXStart(), it->getYStart());
                    it = bullets.erase(it);
                    continue;
                }

                // daca loveste perete
                if (dynamic_cast<Wall*>(m_scene->getObjectAt(newX, newY)) != nullptr) {
                    if (dynamic_cast<Wall*>(m_scene->getObjectAt(newX, newY))->isBreakable())
                    {
                        m_scene->removeObj(newX, newY); //stergem peretele
                    }
                    if (!dynamic_cast<Vehicle*>(m_scene->getObjectAt(it->getXStart(), it->getYStart())))
                        m_scene->removeObj(it->getXStart(), it->getYStart());
                    it = bullets.erase(it);
                    continue;
                }

                // daca loveste o bomba
                if (Bomb*bomb =dynamic_cast<Bomb*>(m_scene->getObjectAt(newX, newY))) {
                    //coordonate bomba
                    HandleBombCollision(bomb, newX, newY);

                    m_scene->removeObj(newX, newY); //stergem bomba
                    if (!dynamic_cast<Vehicle*>(m_scene->getObjectAt(it->getXStart(), it->getYStart())))
                        m_scene->removeObj(it->getXStart(), it->getYStart());
                    it = bullets.erase(it);
                    continue;
                }
            }
        }
    }
}


Game::Difficulty Game::GetDifficulty()
{
    return m_difficulty;
}

void Game::SetDifficulty(Difficulty difficulty)
{
    m_difficulty = difficulty;
}

void Game::HandleBombCollision(Bomb* bomb, int bombX, int bombY)
{       
        //vector de perechi pentru directii
    std::vector<std::pair<int, int>> directions = {
        {-1,0},// sus
        {-1,1},//dreapta sus
        {0,1},//dreapta
        {1,1},//dreapta jos
        {1,0},//jos
        {1,-1},//stanga jos
        {0,-1},//stanga
        {-1,-1}//stanga sus
    };
    for (const auto& dir : directions)
    {
        int checkX = bombX + dir.first;
        int checkY = bombY + dir.second;
        //verificam daca este perete destructibil langa bomba
        if (Wall* wall = dynamic_cast<Wall*>(m_scene->getObjectAt(checkX, checkY)))
        {
            if (wall->isBreakable())
                m_scene->removeObj(checkX, checkY);
        }
        //verificam daca este vehicul si il distrugem
        if (Vehicle* vehicle = dynamic_cast<Vehicle*>(m_scene->getObjectAt(checkX, checkY))) {
            m_scene->removeObj(checkX, checkY);
        }
        //distrugem si bombele
        if (Bomb* bomb = dynamic_cast<Bomb*>(m_scene->getObjectAt(checkX, checkY))) {
            m_scene->removeObj(checkX, checkY);
        }
    }
}
