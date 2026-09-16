#include "Rect.h"


void Rect::move(int x, int y) {
	_x += x;
	_y += y;
};
void Rect::setStart(int x, int y) {
	_x = x;
	_y = y;
};
void Rect::setSize(int height, int width) {
	_height = height;
	_width = width;
}