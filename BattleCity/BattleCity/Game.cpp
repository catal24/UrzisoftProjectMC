#include "Game.h"

Game::Game(std::vector<std::vector<int>> m_initMap)
	:m_scene(m_initMap), m_v(2, 2, 0, false, true)
{
    m_scene.addObj(&m_v);
}

void Game::startGame()
{
    bool isStart=true;
    std::queue<GameObject*> q;
    m_scene.drawTest();
    while (isStart) {
        Sleep(1);
        if (_kbhit()) {  
            char key = _getch();  
            if (key == 'w' || key == 'W') {
                
                m_scene.moveObject(&m_v, m_v.getXStart() - 1, m_v.getYStart());

            }
            else if (key == 's' || key == 'S') {
                m_scene.moveObject(&m_v, m_v.getXStart() + 1, m_v.getYStart());
            }
            else if (key == 'a' || key == 'A') {
                m_scene.moveObject(&m_v, m_v.getXStart(), m_v.getYStart() - 1);
            }
            else if (key == 'd' || key == 'D') {
                m_scene.moveObject(&m_v, m_v.getXStart(), m_v.getYStart() + 1);
            }
           // m_scene.drawTest();
        }

    }
}
