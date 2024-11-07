#pragma once
class GameObject
{

public:

    GameObject(int xStart = 0, int yStart = 0, int id = 0, bool isBreakable = false, bool isVisible = true);

    int getXStart() const;
    void setXStart(int xStart);


    int getYStart() const;
    void setYStart(int yStart);

    int getId() const;
    void setId(int id);

    bool isBreakable() const;
    void setBreakable(bool isBreakable);

    bool isVisible() const;
    void setVisible(bool isVisible);

protected:
	int m_xStart;
	int m_yStart;
	int m_id;
	bool m_isBreakable;
	bool m_isVisible;

};

