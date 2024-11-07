export module Wall;
import <iostream>;
import "GameObject.h";
namespace battlecity
{
    export class Wall:GameObject
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
