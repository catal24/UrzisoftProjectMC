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
    : m_map(m) 
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
    m_map.getMap()[x][y] = new Road;
    m_map.getMap()[x][y]->draw();
}

bool GameScene::checkObj(int x, int y)
{
    //functia verifica daca e libera casuta
    if (typeid(*m_map.getMap()[x][y]) == typeid(Road))
        return true;
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

        
       
    }
    else
    {
        /*aici vom trata ce se intampla cand obiectul nostru interactioneaza cu un alt obiect*/
    }
}

void GameScene::drawTest()
{
    clearConsole();
    m_map.drawMap();
}

void GameScene::drawQueue(std::queue<GameObject*>& q)
{
    q.front()->draw();
    q.pop();
}

