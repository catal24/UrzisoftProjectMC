export module Wall;
import <iostream>;
import <optional>;

export import "map";

namespace battlecity
{
    export class Wall
    {


    public:
        Wall(bool destructible = true, bool hasBomb = false)
            : m_destructible{ destructible }, m_hasBomb{ hasBomb } {}
        
       
        bool IsDestructible() const { return m_destructible; }
        bool HasBomb() const { return m_hasBomb; }

        
        void SetDestructible(bool destructible) { m_destructible = destructible; }
        void SetBomb(bool hasBomb) { m_hasBomb = hasBomb; }

        

    private:
        bool m_destructible;
        bool m_hasBomb;
    };

   
}