#pragma once
#include "Rect.h"
#include "Color.h"
#include "vector"


class Shape
{
protected:
	Color _color;
	Rect _bounding_box;
public:	
	Shape(Color color, Rect bbox) :
		_color(color), _bounding_box(bbox) {};
	void move(int x, int y);
	void setColor(Color color) { _color = color; };
	int get_start_x() {
		return _bounding_box.get_start_x();
	}
	int get_start_y() {
		return _bounding_box.get_start_y();
	}
	virtual	void setSize() {}
	virtual std::vector<std::vector<std::string>>* draw() = 0;
};

