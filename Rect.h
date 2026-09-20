#pragma once
#include <vector>
#include <string>
class Rect
{
private:
	int _x;
	int _y;
	int _height;
	int _width;
public:
	Rect(int x, int y, int height, int width) {
		_x = x;
		_y = y;
		_width = width;
		_height = height;
	};
	void move(int x, int y);
	void setStart(int x, int y);
	void setSize(int height, int width);
	void setWidth(int width) { _width = width; };
	void setHeight(int height) { _height = height; };
	std::string serialise();
	int get_start_x() {
		return _x;
	}
	int get_start_y() {
		return _y;
	}
	std::vector<std::vector<std::string>>* get_empty_rect();
};

