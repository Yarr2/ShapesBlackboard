#pragma once
#include "Rect.h"
#include "Color.h"
#include "vector"
#include <sstream>


int get_int_or_default(std::string input, int default_value);

class Shape
{
protected:
	Color _color;
	Rect _bounding_box;
	int _id = 0;
	bool _setted_id = false;
	bool is_filled = true;
public:	
	void SetId(int id);
	int getId();
	Shape(bool filled, Color color, Rect bbox) :
		_color(color), _bounding_box(bbox) {
		is_filled = filled;
	};
	virtual std::string serialise();
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
	virtual std::string get_desc() = 0;
	virtual void edit(std::string parameters) = 0;
	virtual void move(std::string parameters);
	virtual ~Shape() = default;
};

