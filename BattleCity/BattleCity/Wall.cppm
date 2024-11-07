export module Wall;
import <iostream>;

namespace battlecity
{
    export class Wall
    {
    public:
        
        Wall(bool destructible = true, bool hasBomb = false);

        
        bool IsDestructible() const;
        bool HasBomb() const;

        
        void SetDestructible(bool destructible);
        void SetBomb(bool hasBomb);

    private:
        bool m_destructible;
        bool m_hasBomb;
    };

    
    
}
