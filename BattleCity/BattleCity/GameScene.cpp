#include "GameScene.h"


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
    //delete  m_map.getMap()[x][y];
    m_map.getMap()[x][y] = nullptr;
    m_map.getMap()[x][y] = new Road;

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

