#pragma once
class Point2D {
private:
	int m_x, m_y;
public:
	Point2D(int x = 0, int y = 0) : m_x(x), m_y(y) 
	{
	}
	void changePosByX(int x) { m_x += x; }
	void changePosByY(int y) { m_y += y; }
	void moveTo(int x, int y) { m_x = x; m_y = y; }

	int getX() const { return m_x; }
	int getY() const { return m_y; }
};

