#include "CommandAdd.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include <sstream>


void CommandAdd::ExecuteParameters(Board* board, std::string parameters) {
    // [parameters] = [shape type][color][shape parameters]
    std::string shape_type, color_input;
    std::stringstream parameters_stream(parameters);

    std::getline(parameters_stream, shape_type, ' ');
    std::getline(parameters_stream, color_input, ' ');

    Color color(color_input);
    
    if (shape_type == "rect") {
        int start_x, start_y, height, width;
        if (parameters_stream >> start_x >> start_y >> height >> width) {
            Shape* shape = new Rectangle(color, Rect(start_x, start_y, height, width));
            board->add(shape);
            std::cout << "Added rectangle\n";
        };
        return;
    };
    if (shape_type == "circle") {
        int center_x, center_y, radius;
        if (parameters_stream >> center_x >> center_y >> radius) {
            Shape* shape = new Circle(color, center_x, center_y, radius);
            board->add(shape);
            std::cout << "Added circle\n";
        }
        return;
    }
    if (shape_type == "line") {
        int x1, y1, x2, y2;
        if (parameters_stream >> x1 >> y1 >> x2 >> y2){
            Shape* shape = new Line(color, x1, y1, x2, y2);
            board->add(shape);
            std::cout << "Added line\n";
        }
        return;
    }
    std::cout << "Our application does not support '" << shape_type << "' type of object.\n";


    //Shape* rect = new Rectangle(Color(0, 0, 255), Rect(14, 10, 5, 5));
    //board->add(rect);
}