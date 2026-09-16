#pragma once
class Point
{
private:
	int _x;
	int _y;
public:
	Point(int x, int y) {
		_x = x;
		_y = y;
	};
	void move(int x, int y);
	void set(int x, int y);
};

