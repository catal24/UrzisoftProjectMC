#pragma once
class GameObject
{

public:
    int getXStart() const { return m_xStart; }
    void setXStart(int xStart) { m_xStart = xStart; }

    int getYStart() const { return m_yStart; }
    void setYStart(int yStart) { m_yStart = yStart; }

    int getId() const { return m_id; }
    void setId(int id) { m_id = id; }

    bool isBreakable() const { return m_isBreakable; }
    void setBreakable(bool isBreakable) { m_isBreakable = isBreakable; }

    bool isVisible() const { return m_isVisible; }
    void setVisible(bool isVisible) { m_isVisible = isVisible; }

protected:
	int m_xStart;
	int m_yStart;
	int m_id;
	bool m_isBreakable;
	bool m_isVisible;

};

