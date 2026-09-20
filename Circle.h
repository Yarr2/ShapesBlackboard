#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
    int _center_x = 0;
    int _center_y = 0;
    int _radius = 0;
    static Rect get_rect(int center_x, int center_y, int radius);
public:
    Circle(bool filled, Color color, int center_x, int center_y, int radius);
    std::vector<std::vector<std::string>>* draw() override;
    std::string get_desc() override;
    void edit(std::string parameters) override;
    void move(std::string parameters) override;
};

