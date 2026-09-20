#include "Triangle.h"

void Triangle::draw_side(Color color, int x1, int y1, int x2, int y2,
    std::vector<std::vector<std::string>>* board
) {
    int rows = board[0].size();
    int cols = board[0][0].size();

    int x_cur = x1;
    int y_cur = y1;
    int dx = std::abs(x2 - x1);
    int dy = -std::abs(y2 - y1);
    int error = dx + dy;

    while (true) {
        if (y_cur >= 0 && y_cur < rows &&
            x_cur >= 0 && x_cur < cols) {
            board[0][y_cur][x_cur] = color.ColorText(std::string(2, char(219)));
        }

        if (x_cur == x2 && y_cur == y2) {
            break;
        }

        int doubled_error = 2 * error;

        if (doubled_error >= dy) {
            error += dy;
            if (x2 > x1) x_cur++;
            else x_cur--;
        }

        if (doubled_error <= dx) {
            error += dx;
            if (y2 > y1) {
                y_cur += 1;
            }
            else {
                y_cur -= 1;
            }
        }
    }
}

Rect Triangle::get_rect(
    int x_point1, int y_point1,
    int x_point2, int y_point2,
    int x_point3, int y_point3) {
    int x_min = std::min(std::min(x_point1, x_point2), x_point3);
    int y_min = std::min(std::min(y_point1, y_point2), y_point3);
    int x_max = std::max(std::max(x_point1, x_point2), x_point3);
    int y_max = std::max(std::max(y_point1, y_point2), y_point3);

    return Rect(x_min,y_min, x_max - x_min + 1, y_max - y_min + 1);
}


Triangle::Triangle(bool filled, Color color,
    int x_point1, int y_point1,
    int x_point2, int y_point2,
    int x_point3, int y_point3)
    : Shape(filled, color, Triangle::get_rect(
        x_point1, y_point1,
        x_point2, y_point2,
        x_point3, y_point3)) {
    _x_point1 = x_point1;
    _x_point2 = x_point2;
    _x_point3 = x_point3;
    _y_point1 = y_point1;
    _y_point2 = y_point2;
    _y_point3 = y_point3;
}

std::vector<std::vector<std::string>>* Triangle::draw() {
    std::vector<std::vector<std::string>>* board = _bounding_box.get_empty_rect();
    
    int height = board[0].size();
    int width = board[0][0].size();

    int s_x = _bounding_box.get_start_x();
    int s_y = _bounding_box.get_start_y();
    Triangle::draw_side(_color, _x_point1 - s_x, _y_point1 - s_y, _x_point2 - s_x, _y_point2 - s_y, board);
    Triangle::draw_side(_color, _x_point3 - s_x, _y_point3 - s_y, _x_point2 - s_x, _y_point2 - s_y, board);
    Triangle::draw_side(_color, _x_point1 - s_x, _y_point1 - s_y, _x_point3 - s_x, _y_point3 - s_y, board);
    if (!is_filled) { return board; }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int d1 = (j + s_x - _x_point2) * (_y_point1 - _y_point2) - (i + s_y - _y_point2) * (_x_point1 - _x_point2);
            int d2 = (j + s_x - _x_point3) * (_y_point2 - _y_point3) - (i + s_y - _y_point3) * (_x_point2 - _x_point3);
            int d3 = (j + s_x - _x_point1) * (_y_point3 - _y_point1) - (i + s_y - _y_point1) * (_x_point3 - _x_point1);

            bool has_negative = d1 <= 0 || d2 <= 0 || d3 <= 0;
            bool has_positive = d1 >= 0 || d2 >= 0 || d3 >= 0;

            if (!(has_negative && has_positive)) {
                board[0][i][j] = _color.ColorText(std::string(2, char(219)));
            }

        }
    }
    return board;
}

std::string Triangle::get_desc() {
    return std::to_string(_id) + " Triangle " + _color.getRGBdefinition()
        + std::to_string(_x_point1) + " "
        + std::to_string(_y_point1) + " "
        + std::to_string(_x_point2) + " "
        + std::to_string(_y_point2) + " "
        + std::to_string(_x_point3) + " "
        + std::to_string(_y_point3); " ";
}

void Triangle::edit(std::string parameters) {
    std::stringstream parameters_input(parameters);

    int x1, y1, x2, y2, x3,y3;

    std::string token1, token2, token3, token4, token5, token6;

    if (parameters_input >> token1 >> token2 >> token3 >> token4 >> token5 >> token6)  {
        x1 = get_int_or_default(token1, _x_point1);
        y1 = get_int_or_default(token2, _y_point1);
        x2 = get_int_or_default(token3, _x_point2);
        y2 = get_int_or_default(token4, _y_point2);
        x3 = get_int_or_default(token5, _x_point3);
        y3 = get_int_or_default(token6, _y_point3);

        _bounding_box = Triangle::get_rect(x1, y1, x2, y2, x3, y3);

        _x_point1 = x1;
        _y_point1 = y1;
        _x_point2 = x2;
        _y_point2 = y2;
        _x_point3 = x3;
        _y_point3 = y3;
    }
    else {
        std::cout << "Not enough parameters for edit\n";
    }

}

std::string Triangle::serialise() {
    return Shape::serialise() + "triangle "
        + std::to_string(_x_point1) + " "
        + std::to_string(_y_point1) + " "
        + std::to_string(_x_point2) + " "
        + std::to_string(_y_point2) + " "
        + std::to_string(_x_point3) + " "
        + std::to_string(_y_point3);
}

