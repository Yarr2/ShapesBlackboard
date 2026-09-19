#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    Circle(Color color, int center_x, int center_y, int radius);
    std::vector<std::vector<std::string>>* draw() override;
    std::string get_desc() override;
};

