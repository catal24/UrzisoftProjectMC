module Wall;
import <iostream>;

namespace battlecity
{
    
    Wall::Wall(bool destructible, bool hasBomb)
        : m_destructible{ destructible }, m_hasBomb{ hasBomb }
    {
    }

    
    bool Wall::IsDestructible() const
    {
        return m_destructible;
    }

    
    bool Wall::HasBomb() const
    {
        return m_hasBomb;
    }

    
    void Wall::SetDestructible(bool destructible)
    {
        m_destructible = destructible;
    }

    
    void Wall::SetBomb(bool hasBomb)
    {
        m_hasBomb = hasBomb;
    }

   
}
