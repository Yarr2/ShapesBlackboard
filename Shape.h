#pragma once
#include "Rect.h"
#include "Color.h"
#include "vector"


class Shape
{
	Color _color;
	Rect _bounding_box;
	Shape(Color color, Rect bbox) :
		_color(color), _bounding_box(bbox) {};
	void move(int x, int y);
	void setColor(Color color) { _color = color; };
	virtual	void setSize() {}
	virtual std::vector<std::vector<char>> draw() = 0;
};

