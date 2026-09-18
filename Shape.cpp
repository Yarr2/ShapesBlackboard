#include "Shape.h"
void Shape::move(int x, int y) {
	_bounding_box.move(x, y);
}
void Shape::SetId(int id) {
	if (_setted_id) {
		return;
	}
	_id = id;
	_setted_id = true;
}
int Shape::getId() {
	return _id;
}