#include "Game.h"


Game::Game(std::vector<std::vector<int>> m_initMap)
	:m_scene(m_initMap), m_v(2, 2, 0, false, true)
{
    m_scene.addObj(&m_v);
}

void Game::startGame()
{
    bool isStart = true;
    std::queue<GameObject*> q;
    m_scene.drawTest();
    while (isStart) {
        Sleep(50);  // Sleep pentru a controla viteza jocului

        
        if (_kbhit()) {
            char key = _getch();
            if (key == 'w' || key == 'W') {
                m_scene.moveObject(&m_v, m_v.getXStart() - 1, m_v.getYStart());
                m_v.setAxis(key);

            }
            else if (key == 's' || key == 'S') {
                m_scene.moveObject(&m_v, m_v.getXStart() + 1, m_v.getYStart());
                m_v.setAxis(key);
            }
            else if (key == 'a' || key == 'A') {
                m_scene.moveObject(&m_v, m_v.getXStart(), m_v.getYStart() - 1);
                m_v.setAxis(key);

            }
            else if (key == 'd' || key == 'D') {
                m_scene.moveObject(&m_v, m_v.getXStart(), m_v.getYStart() + 1);
                m_v.setAxis(key);

            }
            else if (key == ' ') {  
                
                bullets.push_back(m_v.shootBullet());
            }
        }

        
        for (auto it = bullets.begin(); it != bullets.end();) {
            int newX = it->getXStart();
            int newY = it->getYStart();

            switch (it->getAxis()) {
            case Axis::up:    newX--; break;
            case Axis::down:  newX++; break;
            case Axis::left:  newY--; break;
            case Axis::right: newY++; break;
            }

            
            if (m_scene.checkObj(newX, newY)) {
                m_scene.moveObject(&(*it), newX, newY);
                ++it;  
            }
            else {
                it = bullets.erase(it);  
            }
            
        }

        
         
    }
}
