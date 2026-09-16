#include "Point.h"


void Point::move(int x, int y) {
	_x += x;
	_y += y;
}
void Point::set(int x, int y) {
	_x = x;
	_y = y;
}