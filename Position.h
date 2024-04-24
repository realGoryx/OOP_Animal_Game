#pragma once

class Position
{
public:
	Position() = default;
	Position(int x2, int y2);

	int getX();
	void setX(int x2);
	
	int getY();
	void setY(int y2);

private:
	int x = 0;
	int y = 0;
};

